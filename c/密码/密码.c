#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
	int i;
	char a[5];
	char b[5]={'0','5','2','3'};
	printf("���������룺");
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
			printf("�������\n");
			exit(1);
		}
	}
	printf("������ȷ\n");
	system("����ƥ��.exe");
}