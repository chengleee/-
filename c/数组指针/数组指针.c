#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int txt(char *,int);
main()
{
    int m;
	char *pt;
	printf("输入文本行数：");
	scanf("%d",&m);
	getchar();
	pt=(char *)malloc(m*81);
	txt(pt,m);
}
txt(char *pt,int n)
{
    char (*p)[81];
	int i,t=0;
	p=(char (*)[81])pt;
	do
	{
	    printf("%d: ",t++);
		gets(*p);
		printf("%c\n",**p);
	}while((**p++)&&(t<n));
	p=(char (*)[81])pt;
	for(i=1;i<=t;i++)
	{
		printf("%d: ",i);
		puts(*p++);
	}
	return t-1;
}