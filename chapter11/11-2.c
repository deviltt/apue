#include "apue.h"
#include <pthread.h>

pthread_t ntid;

void printids(char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx) \n", s, (unsigned long)pid,
		(unsigned long)tid, (unsigned long)tid);
}

void *pth_handler(void *arg)
{
	printids("new thread:");
	return ((void *) 0);
}

int main()
{
	int err;

	err = pthread_create(&ntid, NULL, pth_handler, NULL);
	if(err != 0)
		err_exit(err, "can't creat pthread");

	printids("main thread:");
	sleep(1);
	return 0;
}
