obj-m := mydev.o
mydev-objs := mymod_net.o

# With this simplified Makefile, type 'make' to build your module
# Type 'make install' to build and install the module to the target file system

KERNELDIR=/lib/modules/$(shell uname -r)/build
TARGETDIR=/targetfs

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules modules_install INSTALL_MOD_PATH=$(TARGETDIR)
