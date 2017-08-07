# 2-1

```
$ make
make -C /lib/modules/4.11.12-200.fc25.x86_64/build M=/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step1 modules
make[1]: Entering directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
Makefile:923: "Cannot use CONFIG_STACK_VALIDATION, please install libelf-dev, libelf-devel or elfutils-libelf-devel"
  CC [M]  /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step1/step1.o
  Building modules, stage 2.
  MODPOST 1 modules
  LD [M]  /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step1/step1.ko
make[1]: Leaving directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
$ sudo insmod step1.ko 
$ dmesg | grep Hello
[ 7783.621335] Hello World!
$ sudo rmmod step1 
$ dmesg | grep UNLOADED
[ 7813.616964] Driver UNLOADED.
```
