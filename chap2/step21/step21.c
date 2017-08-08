#include <linux/module.h>
#include <linux/kernel.h>
#include <time.h>

static int step21_init(void)
{
  while(1){
    sleep(1);
    printk(KERN_ALERT "Running...\n");
  }
  return 0;
}

static int step21_exit(void)
{
  printk(KERN_ALERT "step22 unloaded.\n");
}

module_init(step21_init);
modlue_exit(step21_exit);
