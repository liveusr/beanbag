#include <linux/kernel.h>   // printk()
#include <linux/module.h>   // module_init/exit(), MODULE_DESCRIPTION/AUTHOR/LICENSE

MODULE_DESCRIPTION("Simple Char Device Driver");
MODULE_AUTHOR("Me <myself@i.com>");
MODULE_LICENSE("GPL");

static int testdriver_init(void)
{
    printk(KERN_INFO"Initing testdriver\n");

    return 0;
}

static void testdriver_exit(void)
{
    printk(KERN_INFO"Exiting testdriver\n");
}

module_init(testdriver_init);
module_exit(testdriver_exit);
