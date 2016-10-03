
#
# Makefile for the bus drivers.
#

# gt bus for ARM platforms
obj-$(CONFIG_SCC_BUS)		+= Bus.o
obj-$(CONFIG_SCC_DEVICE)		+= Device.o
obj-$(CONFIG_SCC_DRIVER)		+= Driver.o
obj-$(CONFIG_SCC_TEST_CHAR)		+= test.o	
obj-$(CONFIG_SPI_GPA2311)		+= spi_gpa2311.o	
obj-$(CONFIG_SUN_CLASS_MKDEV)		+= mkdev.o	
obj-$(CONFIG_S3C2440_SPI)		+= s3c_spi.o	
obj-$(CONFIG_PLATFORM_DEV)		+= device.o	
obj-$(CONFIG_PLATFORM_DRV)		+= driver.o	
obj-$(CONFIG_SYSFS_KOBJECT)		+= Kobject.o	
obj-$(CONFIG_SYSFS_KSET)		+= Kset.o	
#obj-$(CONFIG_SYSFS_KSET)		+= kset.o	
obj-$(CONFIG_SYSFS_MYSPI)		+= myspi.o	
obj-$(CONFIG_STRUCT_LIST)		+= struct_list.o	
obj-$(CONFIG_TIMER_TEST)		+= timer.o	
obj-$(CONFIG_PROC_READ)		+= proc/proc.o	
obj-$(CONFIG_PROC_WRITE)		+= proc/proc1.o	

clean:
	rm modules.order *.ko *.o *.mod.*

