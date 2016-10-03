ifneq ($(KERNELRELEASE),)

obj-m := memdev.o

else
	
KDIR := ~/tina2.0/Tina-V2/lichee/linux-3.4
all:
	make -C $(KDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=arm-linux-
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers  modul*

endif
