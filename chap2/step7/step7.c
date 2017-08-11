#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL v2");

int step7_init(void)
{
  int size = PAGE_SIZE * 4;
  void *ptr;
  
  printk(KERN_ALERT "step7 LOAD\n");
  while(1){
    ptr = kmalloc(size, GFP_KERNEL);
    if(ptr == NULL){
      printk("break\n");
      break;
    }
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
