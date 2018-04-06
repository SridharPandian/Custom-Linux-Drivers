obj-m := stick_driver.o

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)
all:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	
clean:
	sudo make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
