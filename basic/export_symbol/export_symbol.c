#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

int add_integar(int a, int b)
{
	
	printk(KERN_ALERT "add_intergar\n");

	return a + b;
}

int sub_integar(int a, int b)
{
	printk(KERN_ALERT "sub_integar\n");
	return a - b;
}

EXPORT_SYMBOL(add_integar);
EXPORT_SYMBOL(sub_integar);

MODULE_AUTHOR("Xu Xiaohai");
MODULE_DESCRIPTION("A simple hello world module");
MODULE_ALIAS("A simplest module");
