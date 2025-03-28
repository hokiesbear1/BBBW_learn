obj-m +=first_driver.o

KDIR = /lib/modules/$(shell uname -r)/build

all:
		make -c $(KDIR) M=$(shell pwd) modules

clean:
		make -c $(KDIR) M=$(shell pwd) clean