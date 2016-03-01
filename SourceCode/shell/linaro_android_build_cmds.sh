#!/bin/bash
# Author+=amit.pundir@linaro.org

set -e

EXACT=0
INTERACTIVE=1
DIR=android
if [ -z "${LINARO_ANDROID_ACCESS_ID}" ] ; then
	LINARO_ANDROID_ACCESS_ID=${USER}
fi
SOURCE_OVERLAY_OPTIONAL=1

usage()
{
	echo 'Usage: $0 -m <manifest.xml> -o <overlay.tar> [ -t -d directory -l login ]'
	echo -e '\n -m <manifest>    If -t is not used, then using a browser with cookies you\n                  must download the pinned manifest from:\n             http://snapshots.linaro.org/android/~linaro-android/lcr-reference-juno-m/52/\n -o               The path to the vendor required overlay.\n                  Can be downloaded from http://snapshots.linaro.org/android/binaries/arm/20151111/vendor.tar.bz2\n'
	echo " -t                Reproduce the build from the tip of the branch rather than doing"
	echo "                   an exact replica build"
	echo " -d <directory>    The directory to download code and build from"
	echo "                   Default: ${DIR}"
	echo " -l <login-id>     login-id to clone from linaro-private git repositories"
	echo "                   If in doubt, please contact Linaro Android mailing list for details"
	echo "                   Default: ${LINARO_ANDROID_ACCESS_ID}"
	echo " -y                Assume answer 'YES' for all questions. Non-interactive mode. Requires -l"
	echo " -h                Will show this message."
	exit 1
}

while getopts   "m:o:d:l:hty" optn; do
	case    $optn   in
		o   ) SOURCE_OVERLAY=$OPTARG; SOURCE_OVERLAY_OPTIONAL=0;;  m   ) MANIFEST=`readlink -f $OPTARG`; EXACT=1;;
		d   ) DIR=$OPTARG;;
		l   ) LINARO_ANDROID_ACCESS_ID=$OPTARG;;
		t   ) EXACT=0;;
		y   ) INTERACTIVE=0;;
		h   ) usage; exit 1;;
		\?  ) usage; exit 1;;
        esac
done

UBUNTU=`cat /etc/issue.net | cut -d' ' -f2`
HOST_ARCH=`uname -m`
if [ ${HOST_ARCH} == "x86_64" ] ; then
	PKGS='gnupg flex bison gperf build-essential zip curl zlib1g-dev libc6-dev lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z1-dev libgl1-mesa-dev g++-multilib mingw32 tofrodos python-markdown libxml2-utils xsltproc vim-common python-parted python-yaml wget uuid-dev python-mako'
else
	echo "ERROR: Only 64bit Host(Build) machines are supported at the moment."
	exit 1
fi
if [[ ${UBUNTU} =~ "14.04" || ${UBUNTU} =~ "13." || ${UBUNTU} =~ "12.10" ]]; then
	#Install basic dev package missing in chrooted environments
	sudo apt-get install software-properties-common
	sudo dpkg --add-architecture i386
	PKGS+=' libstdc++6:i386 git-core'
	if [[ ${UBUNTU} =~ "14.04" ]]; then
		PKGS+=' u-boot-tools bc acpica-tools'
	elif [[ ${UBUNTU} =~ "13.10" ]]; then
		PKGS+=' u-boot-tools bc iasl'
	else
		PKGS+=' uboot-mkimage acpica-tools'
	fi
elif [[ ${UBUNTU} =~ "12.04" || ${UBUNTU} =~ "10.04" ]] ; then
	#Install basic dev package missing in chrooted environments
	sudo apt-get install python-software-properties
	if [[ ${UBUNTU} =~ "12.04" ]]; then
		PKGS+=' libstdc++6:i386 git-core'
	else
		PKGS+=' ia32-libs libssl-dev libcurl4-gnutls-dev libexpat1-dev gettext'
	fi
else
	echo "ERROR: Only Ubuntu 10.04, 12.*, 13.* and 14.04 versions are supported."
	exit 1
fi

echo
echo "Setting up Ubuntu software repositories..."
sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) main universe restricted multiverse"
sudo add-apt-repository ppa:linaro-maintainers/tools
sudo apt-get update
echo
echo "Install OpenJDK v1.7?"
echo "*** If you are building AOSP master based builds then you should install OpenJDK v1.7. ***"
echo "*** But if you are building Android 4.4.4 or earlier Android releases then OpenJDK v1.6 is OK to use. ***"
echo "Press "y" to install OpenJDK v1.7, OR"
echo "Press "n" to install OpenJDK v1.6, OR"
echo "Press any other key to continue with the existing JDK installation."
read JDK
if [ ${JDK} == y ] ; then
	PKGS+=' openjdk-7-jdk openjdk-7-jre'
elif [ ${JDK} == n ] ; then
	PKGS+=' openjdk-6-jdk openjdk-6-jre'
else
	echo "Continue with the existing JDK installation .."
fi
echo
echo "Installing missing dependencies if any..."
if [ $INTERACTIVE -eq 1 ] ; then
	sudo apt-get install ${PKGS}
else
	sudo apt-get -y install ${PKGS}
fi
# Obsolete git version 1.7.04 in lucid official repositories
# repo need at least git v1.7.2
if [[ ${UBUNTU} =~ "10.04" ]]; then
	echo
	echo "repo tool complains of obsolete git version 1.7.04 in lucid official repositories"
	echo "Building git for lucid from precise sources .."
	wget http://archive.ubuntu.com/ubuntu/pool/main/g/git/git_1.7.9.5.orig.tar.gz
	tar xzf git_1.7.9.5.orig.tar.gz
	cd git-1.7.9.5/
	make prefix=/usr
	sudo make prefix=/usr install
fi

if [ $EXACT -eq 1 ]; then
	if [ "a$MANIFEST" == "a" -o ! -f $MANIFEST ]; then
		echo "ERROR: no pinned manifest provided. Please download from http://snapshots.linaro.org/android/~linaro-android/lcr-reference-juno-m/52/. This must be done from a browser that accepts cookies."
		exit 1
	fi
fi
if [ $SOURCE_OVERLAY_OPTIONAL -ne 1 ]; then
	if [ "a$SOURCE_OVERLAY" == "a" -o ! -f $SOURCE_OVERLAY ]; then
		echo "ERROR: no source overlay provided. Please download from http://snapshots.linaro.org/android/binaries/arm/20151111/vendor.tar.bz2. This must be done from a browser that accepts cookies."
		exit 1
	fi
fi
if [ -d ${DIR} ] ; then
	if [ $INTERACTIVE -eq 1 ] ; then
		echo "Directory ${DIR} exists. Are you sure you want to use this? (y/n) "
		read CONTINUE
		[ ${CONTINUE} == y ] || exit 1
	else
		echo "Using existing directory: ${DIR} . "
	fi
else
	mkdir ${DIR}
fi
cd ${DIR}

# check for linaro private manifests
PM=`echo http://android-git.linaro.org/git/platform/manifest.git | grep -i "linaro-private" | wc -l`
if [ ${PM} -gt 0 -a ${INTERACTIVE} -eq 1 ] ; then
	if [ "${LINARO_ANDROID_ACCESS_ID}" == "${USER}" ] ; then
		echo "You must specify valid login/access-id to clone from linaro-private manifest repositories."
		echo "Press "y" to continue with login: ${USER}, OR"
		echo "Press "n" to enter new login details, OR"
		echo "Press "h" for help."
		read NEXT
		if [ ${NEXT} == n ] ; then
			echo "Enter login/access-id:"
			read LINARO_ANDROID_ACCESS_ID
		elif [ ${NEXT} == h ] ; then
			usage
		fi
	fi
fi
export MANIFEST_REPO=`echo http://android-git.linaro.org/git/platform/manifest.git | sed 's/\/\/.*-bot@/\/\/'"${LINARO_ANDROID_ACCESS_ID}"'@/'`
export LOCAL_MANIFEST=`echo http://android-git.linaro.org/git/platform/manifest.git | sed 's/\/\/.*-bot@/\/\/'"${LINARO_ANDROID_ACCESS_ID}"'@/'`
export MANIFEST_BRANCH=android-6.0.1_r10
export LOCAL_MANIFEST_BRANCH=linaro-marshmallow
export MANIFEST_FILENAME=default.xml
export TARGET_PRODUCT=juno
export PATCHSETS="juno-m-workarounds MARSHMALLOW-RLCR-PATCHSET"
export LUNCH=juno-userdebug
export TARGET_SIMULATOR=false
export BUILD_TINY_ANDROID=
export CPUS=`grep -c processor /proc/cpuinfo`
export INCLUDE_PERF=
export TARGET_BUILD_VARIANT=userdebug
export BUILD_FS_IMAGE=1
export DEBUG_NO_STRICT_ALIASING=
export DEBUG_NO_STDCXX11=
export TOOLCHAIN_TRIPLET=
export ANDROID_64=
export WITH_HOST_DALVIK=true
export USE_LINARO_TOOLCHAIN=
export TARGET_TOOLS_PREFIX=

# download the repo tool for android
curl "https://android-git.linaro.org/gitweb?p=tools/repo.git;a=blob_plain;f=repo;hb=refs/heads/stable" > repo
chmod +x repo

# download the android code
./repo init -u ${MANIFEST_REPO} -b ${MANIFEST_BRANCH} -m ${MANIFEST_FILENAME} --repo-url=git://android.git.linaro.org/tools/repo -g default,-device,arm
if [ ${EXACT} -eq 1 ] ; then
	rm .repo/manifest.xml
	cp $MANIFEST .repo/manifest.xml
fi
rm -rf .repo/local_manifests
if [[ -n ${LOCAL_MANIFEST} && ! -n ${MANIFEST} ]]; then
	cd .repo/
        git clone ${LOCAL_MANIFEST} -b ${LOCAL_MANIFEST_BRANCH} local_manifests
        cd -
fi

# check for linaro private git repositories
PRI=`grep -i "linaro-private" .repo/manifest.xml | wc -l`
if [ ${PRI} -gt 0 -a ${INTERACTIVE} -eq 1 ] ; then
	if [ "${LINARO_ANDROID_ACCESS_ID}" == "${USER}" ] ; then
		echo "You must specify valid login/access-id to clone from linaro-private git repositories."
		echo "Press "y" to continue with login: ${USER}, OR"
		echo "Press "n" to enter new login details, OR"
		echo "Press "h" for help."
		read NEXT
		if [ ${NEXT} == n ] ; then
			echo "Enter login/access-id:"
			read LINARO_ANDROID_ACCESS_ID
		elif [ ${NEXT} == h ] ; then
			usage
		fi
	fi
	sed -i 's/\/\/.*-bot@/\/\/'"${LINARO_ANDROID_ACCESS_ID}"'@/' .repo/manifest.xml
	sed -i 's/\/\/.*-bot@/\/\/'"${LINARO_ANDROID_ACCESS_ID}"'@/' .repo/local_manifests/*.xml
fi
./repo sync -f -j1

# download and apply the patches
for i in $PATCHSETS; do
	sh ./android-patchsets/$i
done

if [ -n "${SOURCE_OVERLAY}" ]; then
	# extract the vendor's source overlay
	tar -x -a -f "${SOURCE_OVERLAY}" -C .
	source_overlay_name=$(basename ${SOURCE_OVERLAY})
	[ -f ./${source_overlay_name} ] || cp -uv "${SOURCE_OVERLAY}" .
fi

# build the code
source build/envsetup.sh
lunch ${LUNCH}
make -j${CPUS} selinuxtarballs
