KBUILD_EXTRA_SYMBOLS := /home/vilhelm/foo/Module.symvers
ifneq (${KERNELRELEASE},)
    obj-m := keyboard.o
else
    KERNEL_SOURCE := /usr/src/linux-headers-4.13.0-37-generic
    PWD := $(shell pwd)
default:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules
 
clean:
	${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
endif

