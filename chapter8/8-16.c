#include "apue.h"
#include "sys/wait.h"

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL };

int main(void)
{
	pid_t pid;

	if((pid = fork()) < 0)
		err_sys("fork error\n");
	else if(pid == 0){
		if(execle("/home/book/apue/chapter8/8-17", "8-17", "myarg1",
		 	"MY ARG2", (char *)0, env_init) < 0)
			err_sys("execle error\n");
	}

	if(waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");
	
	if((pid = fork()) < 0)
		err_sys("fork error\n");
	else if(pid == 0){
		if(execlp("8-17", "8-17", "only 2 arg", (char *)0) < 0)
			err_sys("execlp error");
	}
	
	exit(0);
}
