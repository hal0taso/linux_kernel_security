#include <linux/module.h>
#include <linux/kernel.h>

int step4_init(void)
{
  printk(KERN_ALERT "step3 LOADING.\n");
  int a = 10;
  int b = 0;
  printk("a is %d\n", a);
  printk("b is %d\n", b);

  printk("a/b is %d\n", a/b);

  return 0;
}

void step4_exit(void)
{
  printk(KERN_ALERT "step4 UNLOADED.\n");   
}

module_init(step4_init);
module_exit(step4_exit);
