#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL v2");
/*
#define PAGESIZE 4096
これだと0x20バイト分だけ引数、リターンアドレス、saved rbp、ローカル変数iが占める..??
ちょうど0x1000バイトだけ変化するように調整 -> step5_initが使う分はどうする？？
*/
#define SIZE 992

int rstack(int n)
{
  char buf[SIZE];
  int i;
  if(n < 1){
    for(i = 0; i < SIZE; i ++ ){
      buf[i] = (char)0;
    }
    n --;
    rstack(n);
  }
  printk("[%p] finished initialized buf.\n", &buf);
  return 0;
}

int step5_init(void)
{
  int n = 12;
  int ret;
  
  printk(KERN_ALERT "step5 LOADED.\n");
  rstack(n);
  
  return 0;
}

void step5_exit(void)
{
  printk(KERN_ALERT "step5 UNLOADED\n");
}

module_init(step5_init);
module_exit(step5_exit);
