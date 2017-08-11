#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL v2");

int step6_init(void)
{
  int size = PAGE_SIZE;
  void* ptr;
  int i;
  
  printk(KERN_ALERT "step6 LOAD\n");
  for(i = 0; i < 32; i ++){
    ptr = kmalloc(size, GFP_KERNEL);
    if(ptr == 0){
      printk("break\n");
      break;
    }
    printk("[%p] %d byte memory allocated.\n", ptr, size);
    kfree(ptr);
    size *= 2;
  }

  return 0;
}

void step6_exit(void)
{
  printk(KERN_ALERT "step6 UNLOADED\n");
}

module_init(step6_init);
module_exit(step6_exit);
