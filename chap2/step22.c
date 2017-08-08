#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/kthread.h>

#define LOOP 0x100

DEFINE_MUTEX(mtx1);
DEFINE_MUTEX(mtx2);

static int cnt;

int f1(void);
int f2(void);

static struct task_struct *kthread_tsk;



static int step22_init(void)
{

  printk(KERN_ALERT "step2 LOADED\n");
  
  task_struct tk1, tk2;
  int ret1, ret2;

  tk1 = kthread_create((void *)f1, NULL, NULL);
  tk2 = kthread_create((void *)f2, NULL, NULL);

  /*
   * カーネル内のエラー処理ってどうなってるんだ...
   */
  if (ret1 != 0){
    printk(KERN_ALERT "Error: can not create thread1\n");
  }

  if (ret2 != 0){
    printk(KERN_ALERT "Error: can not create thread2\n");
  }

  /*
  printk(KERN_ALERT "Execute pthread_join thread1\n");
    ret1 = pthread_join(thread1, NULL);
  if(ret1 != 0){
    printk(KERN_ALERT "Error: can not join thred1\n");
  }

  printk(KERN_ALERT "Execute pthread_join thread2\n");
    ret2 = pthread_join(thread2, NULL);
  if(ret2 != 0){
    printk(KERN_ALERT "Error: can not join thred2\n");
  }
  */

  
  printk(KERN_ALERT "cnt: %d\n", cnt);
  
  return 0;
}


static void step22_exit(void)
{
  printk(KERN_ALERT "Step2 Unloaded.\n");
}

int f1(void)
{
  int i;
  printk(KERN_ALERT "mtx1 LOCKING....\n");
  mutex_lock(&mtx1);
  printk(KERN_ALERT "mtx1 LOCKED.\n");
  for (i = 0; i < LOOP; i ++){
    cnt += 1;
  }

  printk(KERN_ALERT "mtx2 LOCKING....\n");
  mutex_lock(&mtx2);
  printk(KERN_ALERT "mtx2 LOCKED.\n");

  mutex_unlock(&mtx1);
  printk(KERN_ALERT "mtx1 UNLOCKED\n");

  mutex_unlock(&mtx2);
  printk(KERN_ALERT "mtx2 UNLOCKED\n");

  return cnt;
}

int f2(void)
{
  int i;
  printk(KERN_ALERT "mtx2 LOCKING....\n");  
  mutex_lock(&mtx2);
  printk(KERN_ALERT "mtx2 LOCKED.\n");

  for (i = 0; i < LOOP; i ++){
    cnt += 1;
  }
  
  printk(KERN_ALERT "mtx1 LOCKING....\n");  
  mutex_lock(&mtx1);
  printk(KERN_ALERT "mtx1 LOCKED.\n");

  mutex_unlock(&mtx2);
  printk(KERN_ALERT "mtx2 UNLOCKED\n");

  mutex_unlock(&mtx1);
  printk(KERN_ALERT "mtx1 UNLOCKED\n");

  return cnt;
}


module_init(step22_init);
module_exit(step22_exit);
