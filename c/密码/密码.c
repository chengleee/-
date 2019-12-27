#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
	int i;
	char a[5];
	char b[5]={'0','5','2','3'};
	printf("ÇëÊäÈëÃÜÂë£º");
	for(i=0;i<=3;i++)
	{
		a[i]=getch();
	}
	for(i=0;i<=3;i++)
	{
		if(a[i]==b[i])
			continue;
		else
		{
			printf("ÃÜÂë´íÎó£¡\n");
			exit(1);
		}
	}
	printf("ÃÜÂëÕıÈ·\n");
	system("À¨ºÅÆ¥Åä.exe");
}