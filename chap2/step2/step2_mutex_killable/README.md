# 2-1 

## mutex_lock�ˤ��ǥåɥ�å�

```
$ make
make -C /lib/modules/4.11.12-200.fc25.x86_64/build M=/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step22 modules
make[1]: Entering directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
  Building modules, stage 2.
  MODPOST 1 modules
make[1]: Leaving directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
$ sudo insmod
```

insmod�ǥ����ͥ�⥸�塼�����ɤ���ȥץ��ץȤ����äƤ��ʤ��ʤä���

dmesg���ǧ���Ƥߤ�Ȱʲ��Τ褦�ˤʤäƤ�����

```
$ dmesg | grep step2 -A 3
[14170.900719] step2_mutex: module license 'unspecified' taints kernel.
[14170.900720] Disabling lock debugging due to kernel taint
[14170.904061] step2 LOADED.
[14170.904065] mutex is LOCKED.
[14170.904066] Try to lock mutex again.
```

2���ܤΥ�å����Ǥ����ǥåɥ�å��ˤʤäƤ��롩��

KILL�����äƤ�ץ�������λ���ʤ���

## mutex\_lock_killable��Ĥ���

```
$ make
make -C /lib/modules/4.11.12-200.fc25.x86_64/build M=/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable modules
make[1]: Entering directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
  CC [M]  /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable/step2_mutex_killable.o
/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable/step2_mutex_killable.c: In function ��step2_init��:
/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable/step2_mutex_killable.c:12:3: warning: ignoring return value of ��mutex_lock_killable��, declared with attribute warn_unused_result [-Wunused-result]
   mutex_lock_killable(&lock);
   ^~~~~~~~~~~~~~~~~~~~~~~~~~
/home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable/step2_mutex_killable.c:16:3: warning: ignoring return value of ��mutex_lock_killable��, declared with attribute warn_unused_result [-Wunused-result]
   mutex_lock_killable(&lock);
   ^~~~~~~~~~~~~~~~~~~~~~~~~~
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable/step2_mutex_killable.mod.o
  LD [M]  /home/fedora/.ghq/github.com/hal0taso/linux_kernel_security/chap2/step2/step2_mutex_killable/step2_mutex_killable.ko
make[1]: Leaving directory '/usr/src/kernels/4.11.12-200.fc25.x86_64'
$ sudo insmod step2_mutex_killable.ko 
```

insmod�塢��ۤ�Ʊ�ͥץ��ץȤ����äƤ��ʤ���

```
$ dmesg | grep step2 -A 3
[  371.524827] step2_mutex_killable: module license 'unspecified' taints kernel.
[  371.524828] Disabling lock debugging due to kernel taint
[  371.527075] step2 LOADED.
[  371.527079] mutex is LOCKED.
[  371.527080] Try to lock mutex again.
$ sudo kill -9 5353 # insmod �Υץ���
```

KILL������դ�����


```
$ sudo insmod step2_mutex_killable.ko 
[sudo] password for fedora: 
fish: ��sudo insmod step2_mutex_killabl�ġ� terminated by signal SIGKILL (Forced quit)
```

�ץ��ץȤ����äƤ�����
