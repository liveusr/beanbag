#include <linux/kernel.h>   // printk()
#include <linux/module.h>   // module_init/exit(), MODULE_DESCRIPTION/AUTHOR/LICENSE

#include <linux/fs.h>       // register/unregister_chrdev(), struct file_operations

MODULE_DESCRIPTION("Simple Char Device Driver");
MODULE_AUTHOR("Me <myself@i.com>");
MODULE_LICENSE("GPL");

#define DEV_MAJOR   60
#define DEV_NAME    "testdriver"

static int testdriver_open(struct inode *inodp, struct file *filp)
{
    printk(KERN_INFO"Opening testdriver\n");
    return 0;
}

static int testdriver_release(struct inode *inodp, struct file *filp)
{
    printk(KERN_INFO"Releasing testdriver\n");
    return 0;
}

static struct file_operations dev_fops = {
    .owner = THIS_MODULE,
    .open = testdriver_open,
    .release = testdriver_release,
};

static int testdriver_init(void)
{
    int ret;

    printk(KERN_INFO"Initing testdriver\n");

    ret = register_chrdev(DEV_MAJOR, DEV_NAME, &dev_fops);
    if(ret < 0)
        printk(KERN_ERR"Initing testdriver failed\n");

    return ret;
}

static void testdriver_exit(void)
{
    printk(KERN_INFO"Exiting testdriver\n");

    unregister_chrdev(DEV_MAJOR, DEV_NAME);
}

module_init(testdriver_init);
module_exit(testdriver_exit);
