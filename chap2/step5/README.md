# step5

## 4096バイトずつbufに書き込んだとき

```
[ 1984.599398] step5 LOADED.
[ 1984.599403] [ffffb69505dbac80] finished initialized buf.
[ 1984.599405] [ffffb69505db9c60] finished initialized buf.
[ 1984.599407] [ffffb69505db8c40] finished initialized buf.
[ 1984.599410] BUG: stack guard page was hit at ffffb69505db7c18 (stack is ffffb69505db8000..ffffb69505dbbfff)
[ 1984.599413] kernel stack overflow (double-fault): 0000 [#1] SMP
[ 1984.599433] Modules linked in: step5(OE+) fuse ip6t_rpfilter ip6t_REJECT nf_reject_ipv6 xt_conntrack ip_set nfnetlink ebtable_nat ebtable_broute bridge stp llc ip6table_raw ip6table_mangle ip6table_nat nf_conntrack_ipv6 nf_defrag_ipv6 nf_nat_ipv6 ip6table_security iptable_raw iptable_mangle iptable_nat nf_conntrack_ipv4 nf_defrag_ipv4 nf_nat_ipv4 nf_nat nf_conntrack libcrc32c iptable_security ebtable_filter ebtables ip6table_filter ip6_tables vboxsf(OE) sunrpc crct10dif_pclmul snd_intel8x0 crc32_pclmul ppdev ghash_clmulni_intel snd_ac97_codec ac97_bus snd_seq intel_rapl_perf snd_seq_device snd_pcm vboxvideo(OE) vboxguest(OE) snd_timer joydev ttm snd soundcore drm_kms_helper parport_pc drm parport tpm_tis video i2c_piix4 tpm_tis_core tpm e1000 crc32c_intel ata_generic serio_raw pata_acpi
[ 1984.599643] CPU: 1 PID: 7220 Comm: insmod Tainted: G           OE   4.11.12-200.fc25.x86_64 #1
[ 1984.599665] Hardware name: innotek GmbH VirtualBox/VirtualBox, BIOS VirtualBox 12/01/2006
[ 1984.599686] task: ffff916df6854b00 task.stack: ffffb69505db8000
[ 1984.599704] RIP: 0010:rstack+0x30/0x80 [step5]
[ 1984.599716] RSP: 0018:ffffb69505db7c20 EFLAGS: 00010246
[ 1984.599731] RAX: ffffb69505db7c20 RBX: 0000000000000004 RCX: 0000000000000006
[ 1984.599749] RDX: ffffb69505db8c20 RSI: 0000000000000096 RDI: 0000000000000004
[ 1984.599767] RBP: ffffb69505db8c30 R08: 0000000000000001 R09: 0000000000000226
[ 1984.599786] R10: ffff916e1a737340 R11: 0000000000000226 R12: ffffffffc076e000
[ 1984.599804] R13: 0000000000000000 R14: ffffb69505dbbea8 R15: 0000000000000001
[ 1984.599822] FS:  00007f0dd195d5c0(0000) GS:ffff916e3fd00000(0000) knlGS:0000000000000000
[ 1984.599843] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[ 1984.599858] CR2: ffffb69505db7c18 CR3: 000000005a76b000 CR4: 00000000000406e0
[ 1984.599879] DR0: 0000000000000000 DR1: 0000000000000000 DR2: 0000000000000000
[ 1984.599897] DR3: 0000000000000000 DR6: 00000000fffe0ff0 DR7: 0000000000000400
[ 1984.599915] Call Trace:
[ 1984.599944]  ? pointer+0xfa/0x400
[ 1984.599957]  ? kvm_sched_clock_read+0x1e/0x30
[ 1984.599970]  ? sched_clock+0x9/0x10
[ 1984.599983]  ? up+0x32/0x50
[ 1984.599991]  ? log_store+0x1b5/0x270
[ 1984.600002]  ? console_unlock+0x2d0/0x4b0
[ 1984.600014]  ? vprintk_emit+0x2fc/0x380
[ 1984.600025]  ? vprintk_default+0x1f/0x30
[ 1984.600036]  ? vprintk_func+0x20/0x50
[ 1984.600048]  ? printk+0x52/0x6e
[ 1984.600057]  ? rstack+0x56/0x80 [step5]
[ 1984.600096]  ? rstack+0x56/0x80 [step5]
[ 1984.600523]  ? rstack+0x56/0x80 [step5]
[ 1984.600928]  ? rstack+0x80/0x80 [step5]
[ 1984.601306]  ? step5_init+0x1f/0x30 [step5]
[ 1984.601675]  ? do_one_initcall+0x52/0x1a0
[ 1984.602036]  ? kmem_cache_alloc_trace+0x159/0x1b0
[ 1984.602380]  ? do_init_module+0x27/0x1f8
[ 1984.602699]  ? do_init_module+0x5f/0x1f8
[ 1984.602972]  ? load_module+0x27cc/0x2be0
[ 1984.603233]  ? vfs_read+0x11b/0x130
[ 1984.603505]  ? SYSC_finit_module+0xdf/0x110
[ 1984.603744]  ? SYSC_finit_module+0xdf/0x110
[ 1984.603970]  ? SyS_finit_module+0xe/0x10
[ 1984.604277]  ? entry_SYSCALL_64_fastpath+0x1a/0xa9
[ 1984.604538] Code: 55 48 89 e5 53 89 fb 48 81 ec 08 10 00 00 65 48 8b 04 25 28 00 00 00 48 89 45 f0 31 c0 48 8d 85 f0 ef ff ff 48 8d 90 00 10 00 00 <c6> 00 00 48 83 c0 01 48 39 d0 75 f4 48 8d b5 f0 ef ff ff 48 c7 
[ 1984.605499] RIP: rstack+0x30/0x80 [step5] RSP: ffffb69505db7c20
[ 1984.605961] fbcon_switch: detected unhandled fb_set_par error, error code -16
[ 1984.607101] fbcon_switch: detected unhandled fb_set_par error, error code -16
[ 1984.608033] ---[ end trace 323c9b1ce38db78f ]---
```

 3ページ分は書き込めてる
 
 ローカル変数、退避したrbp, リターンアドレスによってスタックのアドレスが少しずれてる
 
 ちょっと編集しながら見てみる。

## 992バイトずつ書き込んだとき

14回のループを実行できた。
それぞれのbufのアドレスは0x400 = 1024バイトずつ変化するように実験した。
15回目のループはカーネルパニックが発生した。

```
[   41.734773] step5 LOADED.
[   41.734787] [ffffb912c05b84a0] finished initialized buf.
[   41.734788] [ffffb912c05b88a0] finished initialized buf.
[   41.734789] [ffffb912c05b8ca0] finished initialized buf.
[   41.734789] [ffffb912c05b90a0] finished initialized buf.
[   41.734790] [ffffb912c05b94a0] finished initialized buf.
[   41.734790] [ffffb912c05b98a0] finished initialized buf.
[   41.734791] [ffffb912c05b9ca0] finished initialized buf.
[   41.734792] [ffffb912c05ba0a0] finished initialized buf.
[   41.734792] [ffffb912c05ba4a0] finished initialized buf.
[   41.734793] [ffffb912c05ba8a0] finished initialized buf.
[   41.734793] [ffffb912c05baca0] finished initialized buf.
[   41.734794] [ffffb912c05bb0a0] finished initialized buf.
[   41.734795] [ffffb912c05bb4a0] finished initialized buf.
[   41.734795] [ffffb912c05bb8a0] finished initialized buf.
```

1024 * 14 = 14336 = 0x3800バイト

1ページは4KB = 0x1000なので、14.336KBのスタック領域を使えている。

v4.11のカーネルを使っているので、16KBつかえるはず。

いい感じにつかえたかなぁ...?
