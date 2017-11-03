#include "apue.h"
#include "sys/wait.h"

int main()
{
	pid_t pid;
	
	if((pid = fork()) < 0){              
		err_sys("fork error\n");
	}
	else if(pid == 0){                    //first child
		if((pid = fork()) < 0)
			err_sys("fork error\n");
		else if(pid > 0){             //first child
		   	printf("first child, pid = %ld\n",(long)getpid());
			exit(0);
		}
		else{	
			sleep(4);
		   	printf("second child, pid = %ld\n",(long)getpid());
		}
		printf("second child, parent pid = %ld\n",(long)getpid());
		exit(0);
	}
	if(waitpid(pid,NULL,0) != pid)
		err_sys("waitpid error\n");
	
	exit(0);
}
