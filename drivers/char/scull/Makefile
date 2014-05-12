KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD :=$(shell pwd)
scull-objs := main.o access.o pipe.o
obj-m := scull.o

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.c *.symvers *.order
