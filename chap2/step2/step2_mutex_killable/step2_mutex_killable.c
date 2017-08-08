#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/kernel.h>
#include <linux/errno.h>

//static struct mutex *lock;
DEFINE_MUTEX(lock);

int step2_init(void)
{
  printk(KERN_ALERT "step2 LOADED.\n");

  if(mutex_lock_killable(&lock)) {
    return -EINTR;
  }
  printk(KERN_ALERT "mutex is LOCKED.\n");

  printk(KERN_ALERT "Try to lock mutex again.\n");
  if (mutex_lock_killable(&lock)) {
    return -EINTR;
  }

  mutex_unlock(&lock);
  mutex_unlock(&lock);

  return 0;
}

void step2_exit(void)
{
  printk(KERN_ALERT "step2 UNLOADED.\n");
}

module_init(step2_init);
module_exit(step2_exit);
