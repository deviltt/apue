#include "apue.h"
#include "sys/resource.h"

#define doit(name) pr_limit(#name, name)

static void pr_limit(char *,int);

int main()
{
#ifdef RLIMIT_AS
	doit(RLIMIT_AS);
#endif

	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);	
	doit(RLIMIT_FSIZE);	
	doit(RLIMIT_MEMLOCK);

#ifdef RLIMIT_MSGQUEUE
		doit(RLIMIT_MSGQUEUE);
#endif

#ifdef RLIMIT_NICE
	doit(RLIMIT_NICE);
#endif

#ifdef RLIMIT_NOFILE
	doit(RLIMIT_NOFILE);
#endif

	exit(0);
}

static void pr_limit(char *name,int num)
{
	struct rlimit 	   limit;
	unsigned long long lim;
	
	if(getrlimit(num,&limit) < 0)
		err_sys("getrlimit error for %s\n",name);
	printf("%-14s ",name);
	if(limit.rlim_cur == RLIM_INFINITY)
		printf("(infinite) ");
	else{
		lim = limit.rlim_cur;
		printf("%10lld",lim);
	}
	
	if(limit.rlim_max == RLIM_INFINITY)
		printf("(infinite) ");
	else{
		lim = limit.rlim_max;
		printf("%10lld",lim);
	}
	
	putchar('\n');
}













