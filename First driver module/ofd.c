#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>

static int __init ofd_init(void){
	printk(KERN_INFO "Hello! This is my first driver module! It starts here! :)");
	return 0;
}
static void __exit ofd_exit(void){
	printk(KERN_INFO "This is where my module ends :(");
}

module_init(ofd_init);
module_exit(ofd_exit);

MODULE_LICENSE("Sridhar");
MODULE_AUTHOR("Sridhar Pandian");
MODULE_DESCRIPTION("My first driver");
