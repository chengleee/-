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
    printf("请输入一个整数:\n");
	scanf("%d",&a);
	a=add(a);
	printf("和为%d\n",a);
	}
}