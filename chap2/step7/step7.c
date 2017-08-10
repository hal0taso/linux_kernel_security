#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL v2");

#define PAGESIZE 4096

void mset(char *buf, size_t size)
{
  int i;
  for(i = 0; i < size/sizeof(unsigned long long int); i ++){
    *buf = 0ULL;
    buf += sizeof(unsigned long long int);
  }
}

int step7_init(void)
{
  int size = PAGESIZE * 4;
  void *ptr;
  
  printk(KERN_ALERT "step7 LOAD\n");
  while(1){
    ptr = kmalloc(size, GFP_KERNEL);
    if(ptr == NULL){
      printk("break\n");
      break;
    }
    mset(ptr, size);
    printk("[%p] %d byte memory allocated.\n", ptr, size);
  }

  return 0;
}

void step7_exit(void)
{
  printk(KERN_ALERT "step7 UNLOADED\n");
}

module_init(step7_init);
module_exit(step7_exit);
