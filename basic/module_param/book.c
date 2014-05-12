#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *book_name = "Linux Device Driver";
static int num = 500;

static int book_init(void)
{
	printk(KERN_ALERT "Book name : %s\n", book_name);
	printk(KERN_ALERT "Book count : %d\n", num);

	return 0;
}

static void book_exit(void)
{
	printk(KERN_ALERT "Book Module exit\n");
}

module_init(book_init);
module_exit(book_exit);

module_param(book_name, charp, S_IRUGO);
module_param(num, int, S_IRUGO);

MODULE_AUTHOR("Xu Xiaohai");
MODULE_DESCRIPTION("A test module to get module parameters");
MODULE_ALIAS("Book module");
