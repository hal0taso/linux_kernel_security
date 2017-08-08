#include <linux/module.h>
#include <linux/init.h>

static int step21_init(void)
{
  while(1){
    printk(KERN_ALERT "Running...\n");
  }
  return 0;
}

static void step21_exit(void)
{
  printk(KERN_ALERT "step22 unloaded.\n");
}

module_init(step21_init);
module_exit(step21_exit);
