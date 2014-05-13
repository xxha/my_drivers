#include <linux/module.h>

static int __init
mymod_init (void)
{
	printk("Hello from my module!\n");
	return 0;
}  

static void __exit
mymod_exit(void) 
{
	printk("Goodbye from my module.\n"); 
}  

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_AUTHOR("Me"); 
MODULE_LICENSE("GPL"); 
MODULE_DESCRIPTION("Basic hello world-type module.");
