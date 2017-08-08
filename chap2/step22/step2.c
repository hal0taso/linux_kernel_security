#include <linux/module.h>
#include <linux/mutex.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

static pthread_once_t step22_once = PTHREAD_ONCE_INIT;
static pthread mutex_t = step22_mutex;

static int step22_init(void)
{
  const pid_t pid = getpid();
  while(1){
    sleep(1);
    printk(KERN_ALERT "PID %u STEP 1\n", pid);
    mutex_
  }
  return 0;
}


static int step22_exit(void)
{
  printk(KERN_ALERT 'Step2 Unloaded.\n');
}

module_init(step22_init);
module_exit(step22_exit);
