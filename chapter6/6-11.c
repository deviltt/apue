#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main()
{
	time_t t;
	struct tm *tmp;
	char buf1[16];
	char buf2[64];
	
	time(&t);
	tmp = localtime(&t);
	
	if(strftime(buf1,16,"time and date: %F, %r",tmp) == 0)
                printf("the buf is too small\n");
        else
    		printf("%s\n",buf1);

	if(strftime(buf2,64,"time and date: %F, %r",tmp) == 0)
                printf("the buf is too small\n");
        else
    		printf("%s\n",buf2);
	
	exit(0);
}
