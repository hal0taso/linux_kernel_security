#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/kernel.h>
#include <linux/errno.h>

//static struct mutex *lock;
DEFINE_MUTEX(lock);

int step2_init(void)
{
  printk(KERN_ALERT "step2 LOADED.\n");

  printk("first lock is LOCKING...\n");
  if(mutex_lock_killable(&lock)) {
    printk("While first lock, interrupted.\n");
    return -EINTR;
  }

  
  printk("second lock is LOCKING...\n");  
  printk(KERN_INFO "Try to lock mutex again.\n");
  if (mutex_lock_killable(&lock)) {
    printk("While second lock, interrupted.\n");
    mutex_unlock(&lock);
    return -EINTR;
  }

  
  printk(KERN_INFO "lock is UNLOCKED.\n");
  mutex_unlock(&lock);
  printk(KERN_INFO "lock is UNLOCKED.\n");
  mutex_unlock(&lock);
  
  return 0;
}

void step2_exit(void)
{
  printk(KERN_ALERT "step2 UNLOADED.\n");
}

module_init(step2_init);
module_exit(step2_exit);
