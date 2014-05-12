#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

extern int add_integar(int a, int b);
extern int sub_integar(int a, int b);

static int symbol_init(void)
{
	int ret;
	int a = 5, b = 3;
	printk(KERN_ALERT "symbol module init\n");


	ret = add_integar(a, b);	
	printk(KERN_ALERT "add_integar = %d\n", ret);

	ret = sub_integar(a, b);	
	printk(KERN_ALERT "sub_integar = %d\n", ret);

	return 0;
}

static void symbol_exit(void)
{
	printk(KERN_ALERT "symbol module exit\n");
}

module_init(symbol_init);
module_exit(symbol_exit);

MODULE_AUTHOR("Xu Xiaohai");
MODULE_DESCRIPTION("A simple export symbol module");
MODULE_ALIAS("A export symbol test module");
