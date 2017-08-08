#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL v2");

#define PAGESIZE 4096

void rstack(int n)
{
  char buf[PAGESIZE];
  int i;
  for(i = 0; i < PAGESIZE; i ++ ){
    buf[i] = (char)0;
  }
  printk("[%p] finished initialized buf.\n", &buf);
  rstack(n);
}

int step5_init(void)
{
  int n = 4;
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
