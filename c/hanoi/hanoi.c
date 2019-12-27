#include <stdio.h>
int c=0;
void mov(char x,int n,char z)
{
	printf("%i. Move disk %i from %c to %c\n",++c,n,x,z);
}

void hanoi(int n,char x,char y,char z)
{
	if(n==1)
	{
		mov(x,1,z);
	}
	else
	{
		hanoi(n-1,x,z,y);	//mov x's NO.1 to NO.n-1 to y
		mov(x,n,z);		//mov n from x to z
		hanoi(n-1,y,x,z);	//mov y's element to z
	}
}

int main()
{
	char x='X',y='Y',z='Z';
	int n;
	printf(":\n");
	scanf("%i",&n);
	hanoi(n,x,y,z);
}
