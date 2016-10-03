#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sun jack");
MODULE_DESCRIPTION("Timer Module");
MODULE_ALIAS("Timer module");


struct timer_list timer;

void timer_function(int para)
{
	printk("<0>Timer Expired and para is %d!!\n", para);
}

int timer_init()
{
	init_timer(&timer);
	timer.data = 5;
	timer.expires = jiffies + (20 * HZ);
	timer.function = timer_function;
	add_timer(&timer);

	return 0;
}

void timer_exit()
{
	del_timer(&timer);
}

module_init(timer_init);
module_exit(timer_exit);
