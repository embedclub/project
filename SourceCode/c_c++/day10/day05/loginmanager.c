#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define USER_FILE "user.dat"


typedef struct tag_User {
	char name[256];
	char passwd[256];
}	USER;


int menuLogin (void) {
	printf ("------------\n");
	printf ("学生管理系统\n");
	printf ("------------\n");
	printf ("[1] 注册    \n");
	printf ("[2] 登录    \n");
	printf ("[0] 退出    \n");
	printf ("------------\n");

        int idMenu = -1;
	while(1)
        {
	    printf ("请选择：");
            if(scanf ("%d", &idMenu) == 1)
            {
                break;
            }
            getchar();
        }

	return idMenu;
}


int onRegister (void) {
	USER userNew;

        char verify[256];

	printf ("用户名：");
	scanf ("%s", userNew.name);
        do{
            memset(verify, 0, 256);
            memset(userNew.passwd, 0, 256);
	    printf ("密码：");
	    scanf ("%s", userNew.passwd);
	    printf ("再次输入密码：");
	    scanf ("%s", verify);
        } while(strcmp(userNew.passwd,verify));

	int fd = open (USER_FILE, O_RDWR | O_CREAT, 0644);
	if (fd == -1) {
		perror ("open");
		return -1;
	}

	USER userOld;
	ssize_t bytes;

	while ((bytes = read (fd, &userOld, sizeof (userOld))) > 0)
		if (! strcmp (userOld.name, userNew.name)) {
			printf ("用户名已存在，注册失败！\n");
			close (fd);
			return 0;
		}

	if (bytes == -1) {
		perror ("read");
		close (fd);
		return -1;
	}

	if (write (fd, &userNew, sizeof (userNew)) == -1) {
		perror ("write");
		close (fd);
		return -1;
	}

	close (fd);

	printf ("注册成功！\n");

	return 0;
}


int onLogin (void) {
	USER userLog;
	printf ("用户名：");
	scanf ("%s", userLog.name);
	printf ("密码：");
	scanf ("%s", userLog.passwd);

	int fd = open (USER_FILE, O_RDONLY | O_CREAT, 0644);
	if (fd == -1) {
		perror ("open");
		return -1;
	}

	USER userOld;
	ssize_t bytes;

	while ((bytes = read (fd, &userOld, sizeof (userOld))) > 0)
		if (! strcmp (userOld.name, userLog.name)) {
			if (strcmp (userOld.passwd, userLog.passwd)) {
				printf ("密码错误，登录失败！\n");
				close (fd);
				return -1;
			}
			else
				break;
		}

	if (bytes == -1) {
		perror ("read");
		close (fd);
		return -1;
	}

	if (bytes == 0) {
		printf ("用户名错误，登录失败！\n");
		close (fd);
		return -1;
	}

	close (fd);
        printf("%s 登录成功！\n", userLog.name);

	return 0;
}


int main (void)
{
    int user_select;

    while(1)
    {
        user_select = menuLogin();
        switch(user_select)
        {
            case 1:
                onRegister();
                break;
            case 2:
                onLogin();
                break;
            case 0:
                return -1;
            defualt:
                break;
        }
    }
    
    return 0;
}
