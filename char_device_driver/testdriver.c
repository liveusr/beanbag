#include <linux/kernel.h>   // printk()
#include <linux/module.h>   // module_init/exit(), MODULE_DESCRIPTION/AUTHOR/LICENSE

#include <linux/fs.h>       // register/unregister_chrdev(), struct file_operations
#include <linux/uaccess.h>  // copy_from_user(), copy_to_user()

MODULE_DESCRIPTION("Simple Char Device Driver");
MODULE_AUTHOR("Me <myself@i.com>");
MODULE_LICENSE("GPL");

#define DEV_MAJOR   60
#define DEV_NAME    "testdriver"
#define DATA_COUNT  10

static char data[DATA_COUNT][80];
static int data_len[DATA_COUNT];
static int r_index;
static int w_index;

static int testdriver_open(struct inode *inodp, struct file *filp)
{
    printk(KERN_INFO"[%d:%d] Opening testdriver\n", MAJOR(inodp->i_rdev), MINOR(inodp->i_rdev));

    r_index = w_index - 1;

    return 0;
}

static int testdriver_release(struct inode *inodp, struct file *filp)
{
    printk(KERN_INFO"[%d:%d] Releasing testdriver\n", MAJOR(inodp->i_rdev), MINOR(inodp->i_rdev));
    return 0;
}

static ssize_t mychardev_read(struct file *filp, char __user *buf, size_t count, loff_t *off)
{
    printk(KERN_INFO"[%d:%d] Reading testdriver\n", MAJOR(filp->f_inode->i_rdev), MINOR(filp->f_inode->i_rdev));

    if(r_index < 0)
        return 0;

    copy_to_user(buf, data[r_index], data_len[r_index]);

    return data_len[r_index--];
}

static ssize_t mychardev_write(struct file *filp, const char __user *buf, size_t count, loff_t *off)
{
    printk(KERN_INFO"[%d:%d] Writing testdriver\n", MAJOR(filp->f_inode->i_rdev), MINOR(filp->f_inode->i_rdev));

    copy_from_user(data[w_index], buf, count);
    data_len[w_index] = count;
    printk(KERN_INFO"[%d:%d] data = %s", MAJOR(filp->f_inode->i_rdev), MINOR(filp->f_inode->i_rdev), data[w_index]);
    w_index++;

    return count;
}

static struct file_operations dev_fops = {
    .owner = THIS_MODULE,
    .open = testdriver_open,
    .release = testdriver_release,
    .read = mychardev_read,
    .write = mychardev_write,
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
