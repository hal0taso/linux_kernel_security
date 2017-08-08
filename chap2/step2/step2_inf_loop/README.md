# 2-1
無限ループを行うプログラムの作成

```
$ make
make -C /lib/modules/4.11.12-200.fc25.x86_64/build M=/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step21 modules
make[1]: Entering directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
Makefile:923: "Cannot use CONFIG_STACK_VALIDATION, please install libelf-dev, libelf-devel or elfutils-libelf-devel"
  CC [M]  /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step21/step21.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step21/step21.mod.o
  LD [M]  /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step21/step21.ko
make[1]: Leaving directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
```
