# step4

insmodすると、SISSEGV (Address boundary error)でプロセスが終了した？？？

でもstack trace見てみるとdivide errorって表示されているんですが....

```
[  249.300879] step4: module license 'unspecified' taints kernel.
[  249.300880] Disabling lock debugging due to kernel taint
[  249.301290] step4 LOADING.
[  249.301293] a is 10
[  249.301294] b is 0
[  249.301298] divide error: 0000 [#1] SMP
[  249.301330] Modules linked in: step4(POE+) fuse ip6t_rpfilter ip6t_REJECT nf_reject_ipv6 xt_conntrack ip_set nfnetlink ebtable_broute bridge stp llc ebtable_nat ip6table_raw ip6table_nat nf_conntrack_ipv6 nf_defrag_ipv6 nf_nat_ipv6 ip6table_security ip6table_mangle iptable_raw iptable_nat nf_conntrack_ipv4 nf_defrag_ipv4 nf_nat_ipv4 nf_nat nf_conntrack libcrc32c iptable_security iptable_mangle ebtable_filter ebtables ip6table_filter ip6_tables vboxsf(OE) sunrpc crct10dif_pclmul crc32_pclmul ghash_clmulni_intel ppdev snd_intel8x0 intel_rapl_perf vboxvideo(OE) snd_ac97_codec ac97_bus vboxguest(OE) joydev snd_seq snd_seq_device ttm drm_kms_helper snd_pcm parport_pc tpm_tis tpm_tis_core parport tpm drm i2c_piix4 snd_timer snd soundcore video crc32c_intel serio_raw e1000 ata_generic pata_acpi
[  249.301526] CPU: 0 PID: 3210 Comm: insmod Tainted: P           OE   4.11.12-200.fc25.x86_64 #1
[  249.301548] Hardware name: innotek GmbH VirtualBox/VirtualBox, BIOS VirtualBox 12/01/2006
[  249.301569] task: ffff91176060cb00 task.stack: ffffb036424ec000
[  249.301587] RIP: 0010:init_module+0x43/0x50 [step4]
[  249.301600] RSP: 0018:ffffb036424efca0 EFLAGS: 00010246
[  249.301614] RAX: 000000000000000a RBX: ffffffffc0424000 RCX: 0000000000000000
[  249.301633] RDX: 0000000000000000 RSI: 0000000000000092 RDI: ffffffffc0425048
[  249.301651] RBP: ffffb036424efca0 R08: 0000000000000001 R09: 0000000000000221
[  249.301670] R10: ffff91177b9fce60 R11: 0000000000000221 R12: ffffffffc0426000
[  249.301688] R13: 0000000000000000 R14: ffffb036424efea8 R15: 0000000000000001
[  249.301706] FS:  00007f47ab0875c0(0000) GS:ffff91177fc00000(0000) knlGS:0000000000000000
[  249.301727] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  249.301742] CR2: 000000012b6a1b78 CR3: 0000000062fff000 CR4: 00000000000406f0
[  249.301778] DR0: 0000000000000000 DR1: 0000000000000000 DR2: 0000000000000000
[  249.301797] DR3: 0000000000000000 DR6: 00000000fffe0ff0 DR7: 0000000000000400
[  249.301815] Call Trace:
[  249.301833]  do_one_initcall+0x52/0x1a0
[  249.301850]  ? kmem_cache_alloc_trace+0x159/0x1b0
[  249.301865]  ? do_init_module+0x27/0x1f8
[  249.301876]  do_init_module+0x5f/0x1f8
[  249.301889]  load_module+0x27cc/0x2be0
[  249.301901]  ? vfs_read+0x11b/0x130
[  249.301912]  SYSC_finit_module+0xdf/0x110
[  249.301923]  ? SYSC_finit_module+0xdf/0x110
[  249.301935]  SyS_finit_module+0xe/0x10
[  249.302396]  entry_SYSCALL_64_fastpath+0x1a/0xa9
[  249.302855] RIP: 0033:0x7f47aa562aa9
[  249.303309] RSP: 002b:00007ffde33cc698 EFLAGS: 00000246 ORIG_RAX: 0000000000000139
[  249.303783] RAX: ffffffffffffffda RBX: 00007f47aa821b38 RCX: 00007f47aa562aa9
[  249.304237] RDX: 0000000000000000 RSI: 0000000129ad9186 RDI: 0000000000000003
[  249.304671] RBP: 00007f47aa821ae0 R08: 0000000000000000 R09: 00007f47aa823e80
[  249.305051] R10: 0000000000000003 R11: 0000000000000246 R12: 00007f47aa821b38
[  249.305419] R13: 0000000000001010 R14: 00007f47aa822168 R15: 000000000000270f
[  249.305778] Code: 00 00 48 c7 c7 36 50 42 c0 e8 21 40 da c9 31 f6 48 c7 c7 3f 50 42 c0 e8 13 40 da c9 b8 0a 00 00 00 31 c9 48 c7 c7 48 50 42 c0 99 <f7> f9 89 c6 e8 fb 3f da c9 31 c0 5d c3 0f 1f 44 00 00 55 48 c7 
[  249.306857] RIP: init_module+0x43/0x50 [step4] RSP: ffffb036424efca0
[  249.307211] fbcon_switch: detected unhandled fb_set_par error, error code -16
[  249.308247] fbcon_switch: detected unhandled fb_set_par error, error code -16
[  249.309311] ---[ end trace b8fb0991c8db7843 ]---
```
