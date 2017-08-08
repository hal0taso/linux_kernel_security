#include <linux/module.h>
#include <linux/kernel.h>


int step3_init(void)
{

  printk(KERN_ALERT "step3 LOADING.\n");

  int a;
  int b;
  int c;
  int *p;

  a = 5;
  printk("a is %d.\n", a);
  p = &a;
  printk("p is now point to a.\nand p value is %d.\n", *p);
  b = *p;
  printk("b is %d\n", b);
  p = NULL;
  printk("now, p is set to Null.\n");
  c = *p;
  printk("c is %d\n", c);
  
  return 0;
}

void step3_exit(void)
{
  printk(KERN_ALERT "step3 UNLOADED.\n");   
}

module_init(step3_init);
module_exit(step3_exit);
