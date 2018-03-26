ifneq (${KERNELRELEASE},)
    obj-m := USB-pendrive.o
else
    KERNEL_SOURCE := /usr/src/linux-headers-4.13.0-36-generic
    PWD := $(shell pwd)
default:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules
 
clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
endif

