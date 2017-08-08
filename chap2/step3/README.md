# 3

## /proc/sys/kernel/panic_on_oops=0で実行

insmodを実行するとSIGKILLが発行されて強制的に終了する。dmesgを確認すると、以下のようなstack traceが確認できる。

```
[  163.712648] step3: module license 'unspecified' taints kernel.
[  163.712649] Disabling lock debugging due to kernel taint
[  163.713117] step3 LOADING.
[  163.713120] a is 5.
[  163.713120] p is now point to a.
               and p value is 5.
[  163.713121] b is 5
[  163.713121] now, p is set to Null.
[  163.713125] BUG: unable to handle kernel NULL pointer dereference at           (null)
[  163.713155] IP: step3_init+0x54/0x70 [step3]
[  163.713168] PGD 0 

[  163.713181] Oops: 0000 [#1] SMP
[  163.713191] Modules linked in: step3(POE+) fuse ip6t_rpfilter ip6t_REJECT nf_reject_ipv6 xt_conntrack ip_set nfnetlink ebtable_nat ebtable_broute bridge stp llc ip6table_nat nf_conntrack_ipv6 nf_defrag_ipv6 nf_nat_ipv6 ip6table_mangle ip6table_raw ip6table_security iptable_nat nf_conntrack_ipv4 nf_defrag_ipv4 nf_nat_ipv4 nf_nat nf_conntrack libcrc32c iptable_mangle iptable_raw iptable_security ebtable_filter ebtables ip6table_filter ip6_tables vboxsf(OE) sunrpc ppdev crct10dif_pclmul crc32_pclmul ghash_clmulni_intel intel_rapl_perf parport_pc parport vboxvideo(OE) ttm drm_kms_helper snd_intel8x0 snd_ac97_codec ac97_bus vboxguest(OE) snd_seq snd_seq_device snd_pcm joydev snd_timer snd soundcore i2c_piix4 video drm tpm_tis tpm_tis_core tpm e1000 crc32c_intel serio_raw ata_generic pata_acpi
[  163.713393] CPU: 1 PID: 2779 Comm: insmod Tainted: P           OE   4.11.12-200.fc25.x86_64 #1
[  163.713415] Hardware name: innotek GmbH VirtualBox/VirtualBox, BIOS VirtualBox 12/01/2006
[  163.713437] task: ffff9df4f6328000 task.stack: ffffaf97422fc000
[  163.713455] RIP: 0010:step3_init+0x54/0x70 [step3]
[  163.713468] RSP: 0018:ffffaf97422ffca0 EFLAGS: 00010286
[  163.713483] RAX: 0000000000000016 RBX: ffffffffc05cf000 RCX: 0000000000000006
[  163.713502] RDX: 0000000000000000 RSI: 0000000000000092 RDI: ffff9df53fd0e0c0
[  163.713521] RBP: ffffaf97422ffca0 R08: 0000000000000001 R09: 0000000000000223
[  163.713540] R10: ffff9df4f65f82a0 R11: 0000000000000223 R12: ffffffffc05d1000
[  163.713558] R13: 0000000000000000 R14: ffffaf97422ffea8 R15: 0000000000000001
[  163.713577] FS:  00007f07b5ee25c0(0000) GS:ffff9df53fd00000(0000) knlGS:0000000000000000
[  163.713599] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  163.713614] CR2: 0000000000000000 CR3: 000000007869e000 CR4: 00000000000406e0
[  163.713660] DR0: 0000000000000000 DR1: 0000000000000000 DR2: 0000000000000000
[  163.713680] DR3: 0000000000000000 DR6: 00000000fffe0ff0 DR7: 0000000000000400
[  163.713699] Call Trace:
[  163.713718]  do_one_initcall+0x52/0x1a0
[  163.713735]  ? kmem_cache_alloc_trace+0x159/0x1b0
[  163.713751]  ? do_init_module+0x27/0x1f8
[  163.713763]  do_init_module+0x5f/0x1f8
[  163.713775]  load_module+0x27cc/0x2be0
[  163.713787]  ? vfs_read+0x11b/0x130
[  163.713799]  SYSC_finit_module+0xdf/0x110
[  163.714287]  ? SYSC_finit_module+0xdf/0x110
[  163.714732]  SyS_finit_module+0xe/0x10
[  163.715212]  entry_SYSCALL_64_fastpath+0x1a/0xa9
[  163.715665] RIP: 0033:0x7f07b53bdaa9
[  163.716117] RSP: 002b:00007ffe0553fb88 EFLAGS: 00000246 ORIG_RAX: 0000000000000139
[  163.716580] RAX: ffffffffffffffda RBX: 00007f07b567cb38 RCX: 00007f07b53bdaa9
[  163.717034] RDX: 0000000000000000 RSI: 00000092c48b2186 RDI: 0000000000000003
[  163.717479] RBP: 00007f07b567cae0 R08: 0000000000000000 R09: 00007f07b567ee80
[  163.718039] R10: 0000000000000003 R11: 0000000000000246 R12: 00007f07b567cb38
[  163.718488] R13: 0000000000001010 R14: 00007f07b567d168 R15: 000000000000270f
[  163.718934] Code: 00 00 48 c7 c7 80 00 5d c0 e8 10 90 bf e3 be 05 00 00 00 48 c7 c7 40 00 5d c0 e8 ff 8f bf e3 48 c7 c7 49 00 5d c0 e8 f3 8f bf e3 <8b> 34 25 00 00 00 00 48 c7 c7 61 00 5d c0 e8 e0 8f bf e3 31 c0 
[  163.720241] RIP: step3_init+0x54/0x70 [step3] RSP: ffffaf97422ffca0
[  163.720640] CR2: 0000000000000000
[  163.720981] fbcon_switch: detected unhandled fb_set_par error, error code -16
[  163.722026] fbcon_switch: detected unhandled fb_set_par error, error code -16
[  163.723104] ---[ end trace fc9ef3f033b0783a ]---
```

## もう一回実行してみる

SIGKILLが送信されるまでプロンプトが帰ってこない。

dmesgは何も変化なし。　

## /proc/sys/kernel/panic_on_oops=1で実行

一応`/proc/sys/kernel/panic`を60に設定して実行。

システムがハングアップした。60秒くらいしてから再起動した。
