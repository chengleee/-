#include <stdio.h>
int main()
{
	int i,j,k,a[4];
	printf("请输入要排列的4个数字:\n");
	scanf("%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3]);
	if(a[0]==a[1]&&a[0]==a[2]&&a[1]==a[2])
	{
		printf("ERROR");
	}
	else
	{
	
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(a[i]!=a[j])
				{	
					for(k=0;k<4;k++)
					{
						if(a[j]!=a[k]&&a[i]!=a[k])
						{
							printf("%d%d%d ",a[i],a[j],a[k]);	
						}
					}
				}
			}
		}
	}
	putchar(10);
}
