#include <stdio.h>
serror(int);
main()
{
	int i;
	for(i=0;i<4;i++)
		serror(i);
	putchar(10);
}
serror(int num)
{
	char *error[]=
	{
		"cann't open file\n",
		"read error\n",
		"write error\n",
		"media failure\n"
	};
	printf("%s",error[num]);
}
