#include <stdio.h>
void swap(int *,int *);
main()
{
	int i = 40,j = 60;
	void (*f)();
	f = swap;
	if(i<j) f(&i,&j);
	printf("交换后的结果：i=%d,j=%d\n",i,j);
}
void swap(int *p1,int *p2)
{
	int temp;
	printf("%d\n",*p1);
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
		
}
