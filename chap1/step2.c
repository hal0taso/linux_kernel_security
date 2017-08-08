#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>

static void test(const int fd1, const int fd2)
{
	const pid_t pid = getpid();
	while (1) {
		sleep(1);
		fprintf(stderr, "PID %u STEP 1\n", pid);
		flock(fd1, LOCK_EX);
		sleep(1);
		fprintf(stderr, "PID %u STEP 2\n", pid);
		flock(fd2, LOCK_EX);
		sleep(1);
		fprintf(stderr, "PID %u STEP 3\n", pid);
		flock(fd1, LOCK_UN);
		sleep(1);
		fprintf(stderr, "PID %u STEP 4\n", pid);
		flock(fd2, LOCK_UN);
	}
}

int main(int argc, char *argv[])
{
	if (fork() == 0) {
		sleep(10);
		test(open("/dev/null", O_WRONLY), open("/dev/zero", O_RDONLY));
	} else {
		test(open("/dev/zero", O_RDONLY), open("/dev/null", O_WRONLY));
	}
	return 0;
}
