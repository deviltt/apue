#include "apue.h"
int main()
{
	char name[L_tmpnam];
	printf("%s\n",tmpnam(NULL));
	
	tmpnam(name);
	printf("%s\n",name);

	if((fp = tmpfile()) == NULL)
		err_sys("tmpfile error");
	fputs("one line of output\n",fp);
	rewind(fp);
	if(fgets() == NULL)
		err_sys("fgets error");
	fputs(line,stdout);

	exit(0);
}
