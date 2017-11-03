#include "apue.h"

void charactatime(char *str);

int main(void)
{
	pid_t pid;

	TELL_WAIT();	

	if((pid = fork()) < 0)
		err_sys("fork error\n");
	else if(pid ==0){
		WAIT_PARENT();
		charactatime("output from child\n");
		TELL_PARENT(getpid());
	}
	else{
		charactatime("output from parent\n");
		TELL_CHILD(pid);
		WAIT_CHILD();
	}
	printf("end\n");
	return 0;
}

void charactatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout,NULL);
	for(ptr=str; (c = *ptr++) != 0;)
		putc(c, stdout);
}
