#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>

//probe function
//called on a device insertion if and only if no other device has beat us to the punch
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO"[*] Aneeshprabu Pen drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
	return 0;//return 0 indicates we will manage this device
}

//disconnect
static void pen_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "[*] Aneeshprabu Pen drive remove\n");
}

//usb_device_id
static struct usb_device_id pen_table[] = 
{
	//0781:5567 (vendorID:productID)
	{USB_DEVICE(0x0781,0x5567),
	USB_DEVICE(0X0046,0X1532),
	USB_DEVICE(0x0bc2,0xab1e)}, //information is obtained using "lsusb" at the command line
	{} //Terminating entry
};

MODULE_DEVICE_TABLE (usb, pen_table);

//usb_driver
static struct usb_driver pen_driver =
{
	.name = "Aneeshprabu-USB Stick-Driver",
	.id_table = pen_table,  //type - usb_device_id
	.probe = pen_probe,
	.disconnect = pen_disconnect,
};

static int __init pen_init(void)
{
	int ret = -1;
	printk(KERN_INFO "[*] Aneeshprabu Constructor of driver");
	printk(KERN_INFO "\tRegistering Driver with kernel");
	ret = usb_register(&pen_driver);
	printk(KERN_INFO "\tRegisteration is complete");
	return ret;
}

static void __exit pen_exit(void)
//deregister
{
	printk(KERN_INFO "[*] Aneeshprabu Destructor of driver");
	usb_deregister(&pen_driver);
	printk(KERN_INFO "\tunregistration complete!");
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aneeshprabu");
MODULE_DESCRIPTION("USB Pendrive registration Driver");
