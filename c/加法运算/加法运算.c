#include<stdio.h>

int add(int a)
{
    int s=0,i;
	for(i=0;i<=a;i++)
	{
          s+=i;
	}
	return s;
}

main()
{
    int a;
	while(1)
	{
    printf("������һ������:\n");
	scanf("%d",&a);
	a=add(a);
	printf("��Ϊ%d\n",a);
	}
}