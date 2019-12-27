#include <stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			if(i!=j)
				for(k=1;k<=4;k++)
				{
					if(k!=j&k!=i)
						printf("%d%d%d ",i,j,k);
				}
		}
	}
	putchar(10);
}
