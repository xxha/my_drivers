#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
	printk(KERN_ALERT "hello world init\n");

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "hello world exit\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Xu Xiaohai");
MODULE_VERSION("v1.0");
MODULE_DESCRIPTION("A simple hello world module");
MODULE_ALIAS("A simplest module");
