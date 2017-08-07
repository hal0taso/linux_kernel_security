#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL v2");

static int step1_init(void)
{
	printk(KERN_ALERT "Driver LOADED.\n");
	printk(KERN_ALERT "Hello World!\n");
	return 0;
}

static void step1_exit(void)
{
	printk(KERN_ALERT "Driver UNLOADED.\n");
}

module_init(step1_init);
module_exit(step1_exit);
