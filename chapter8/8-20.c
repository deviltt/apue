#include "apue.h"
#include "sys/wait.h"

int main()
{
	pid_t pid;

	if((pid = fork()) < 0)
		err_sys("fork error");
	else if(pid == 0){
		if(execl("/home/book/apue/chapter8/test.sh", "test.sh", "myarg1",
			"myarg2", (char *)0) < 0)
			err_sys("execl error"); 
	}

	if(waitpid(pid, NULL, 0) < 0)
		err_sys("waitpid error");
	
	exit(0);
}

