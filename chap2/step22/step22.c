#include <linux/module.h>
#include <linux/mutex.h>
#include <pthread.h>

#define LOOP 0x100

static pthread_mutex_t mtx1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mtx2 = PTHREAD_MUTEX_INITIALIZER;

static int cnt;

void f1(void);
void f2(void);

static int step22_init(void)
{

  printk(KERN_ALERT "step2 LOADED\n");
  
  pthread thread1, thread2;
  int ret1, ret2;

  ret1 = pthread_create(&thread1, NULL, (void *)f1, NULL);
  ret2 = pthread_create(&thread2, NULL, (void *)f2, NULL);

  /*
   * カーネル内のエラー処理ってどうなってるんだ...
   */
  if (ret1 != 0){
    printk(KERN_ALERT "Error: can not create thread1\n");
  }

  if (ret2 != 0){
    printk(KERN_ALERT "Error: can not create thread2\n");
  }

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

  
  printk(KERN_ALERT "cnt: %d\n", cnt);
  
  return 0;
}


static int step22_exit(void)
{
  printk(KERN_ALERT "Step2 Unloaded.\n");
}

int f1(void)
{
  printk(KERN_ALERT "mtx1 LOCKING....\n");
  pthread_mutex_lock(&mtx1);
  printk(KERN_ALERT "mtx1 LOCKED.\n");
  for( int i; i < LOOP; i ++){
    cnt += 1
  }

  printk(KERN_ALERT "mtx2 LOCKING....\n");
  pthread_mutex_lock(&mtx2);
  printk(KERN_ALERT "mtx2 LOCKED.\n");

  pthread_mutex_unlock(&mtx1);
  printk(KERN_ALERT "mtx1 UNLOCKED\n");

  pthread_mutex_unlock(&mtx2);
  printk(KERN_ALERT "mtx2 UNLOCKED\n");

  return cnt;
}

int f2(void)
{
  printk(KERN_ALERT "mtx2 LOCKING....\n");  
  pthread_mutex_lock(&mtx2);
  printk(KERN_ALERT "mtx2 LOCKED.\n");

  for( int i; i < LOOP; i ++){
    cnt += 1
  }
  
  printk(KERN_ALERT "mtx1 LOCKING....\n");  
  pthread_mutex_lock(&mtx1);
  printk(KERN_ALERT "mtx1 LOCKED.\n");

  pthread_mutex_unlock(&mtx2);
  printk(KERN_ALERT "mtx2 UNLOCKED\n");

  pthread_mutex_unlock(&mtx1);
  printk(KERN_ALERT "mtx1 UNLOCKED\n");

  return cnt;
}


module_init(step22_init);
module_exit(step22_exit);
