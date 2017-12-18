#include "apue.h"
#include <pthread.h>

void *pth1_handler(void *arg)
{
	printf("thread 1 returning\n");
	return ((void *)1);
}

void *pth2_handler(void *arg)
{
	printf("thread 2 exiting\n");
	pthread_exit((void *)2);
}

int main()
{
	pthread_t tid1, tid2;
	int       err;
	void      *tret;

	err = pthread_create(&tid1, NULL, pth1_handler, NULL);
	if(err != 0)
		err_exit(err, "can't creat pthread1");
	err = pthread_create(&tid2, NULL, pth2_handler, NULL);
	if(err != 0)
		err_exit(err, "can't creat pthread2");
	
	err = pthread_join(tid1, &tret);
	if(err != 0)
		err_exit(err, "can't join with thread 1");
	printf("thread 1 exit code %ld\n", (long)tret);
	
	err = pthread_join(tid2, &tret);
	if(err != 0)
		err_exit(err, "can't join with thread 2");
	printf("thread 2 exit code %ld\n", (long)tret);
	
	exit(0);
}
