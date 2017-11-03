#include "stdio.h"

static void my_exit1(void);
static void my_exit2(void);

int main()
{
	if(atexit(my_exit1) != 0)
		printf("register my_exit1 error!");

	if(atexit(my_exit2) != 0)
		printf("register my_exit2 error!");

	if(atexit(my_exit1) != 0)
		printf("register my_exit1 error!");

	printf("main is done!\n");

	exit(0);
}

static void my_exit1(void)
{
	printf("first\n");
}

static void my_exit2(void)
{
	printf("second\n");
}
