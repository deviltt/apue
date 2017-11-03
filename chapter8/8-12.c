#include "apue.h"

void charactatime(char *str);

int main(void)
{
	pid_t pid;
	
	if((pid = fork()) < 0)
		err_sys("fork error\n");
	else if(pid == 0)
		charactatime("output from child\n");
	else
		charactatime("output from parent\n");
	
	exit(0);
}

void charactatime(char *str)
{
	char *ptr;
	int c;

	setbuf(stdout,NULL);
	for(ptr=str; (c = *ptr++) != 0;)
		putc(c, stdout);
}
