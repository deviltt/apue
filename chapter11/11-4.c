#include "apue.h"
#include <pthread.h>

struct foo {
	int a, b, c, d;
};

void print_foo(const char *s, const struct foo *fp)
{
	printf("%s", s);
	printf("structure at 0x%lx\n", (unsigned long) fp);
	printf("foo.a = %d\n", fp->a);
	printf("foo.b = %d\n", fp->b);
	printf("foo.c = %d\n", fp->c);
	printf("foo.d = %d\n", fp->d);
}

void *th_fun1(void *arg)
{
	struct foo foo = {1, 2, 3, 4};

	print_foo("thread 1:\n", &foo);
	pthread_exit((void *)&foo);
}

void *th_fun2(void *arg)
{
	printf("thread 2 id is 0x%lu\n", (unsigned long)pthread_self());
	pthread_exit((void *)0);
}

int main()
{
	pthread_t tid1, tid2;
	int 	  err;
	struct foo *fp;

	if((err = pthread_create(&tid1, NULL, th_fun1, NULL)) != 0)
		err_exit(err, "can't creat thread 1");

	if((err = pthread_join(tid1, (void *)&fp)) != 0)
		err_exit(err, "can't join with thread 1");

	sleep(1);

	printf("parent starting second thread\n");
	
	if((err = pthread_create(&tid2, NULL, th_fun2, NULL)) != 0)
		err_exit(err, "can't creat thread 2");

	sleep(1);
	print_foo("parent:\n", fp);

	exit(0);
}
