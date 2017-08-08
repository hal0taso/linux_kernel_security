# 2-1 mutex_lockによるデッドロック

```
$ make
make -C /lib/modules/4.11.12-200.fc25.x86_64/build M=/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step22 modules
make[1]: Entering directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
  Building modules, stage 2.
  MODPOST 1 modules
make[1]: Leaving directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
$ sudo insmod
```

insmodでカーネルモジュールをロードするとプロンプトが帰ってこなくなった。

dmesgを確認してみると以下のようになっていた。

```
$ dmesg | grep step2 -A 3
[14170.900719] step2_mutex: module license 'unspecified' taints kernel.
[14170.900720] Disabling lock debugging due to kernel taint
[14170.904061] step2 LOADED.
[14170.904065] mutex is LOCKED.
[14170.904066] Try to lock mutex again.
```

2度目のロックができずデッドロックになっている？？

