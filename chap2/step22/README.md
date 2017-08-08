# 2-1 mutex_lockによるデッドロック

```
$ make
make -C /lib/modules/4.11.12-200.fc25.x86_64/build M=/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step22 modules
make[1]: Entering directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
  Building modules, stage 2.
  MODPOST 1 modules
make[1]: Leaving directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
```
