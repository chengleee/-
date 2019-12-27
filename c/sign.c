#include<stdio.h>
#include<string.h>
typedef struct n
{
	char name[16];
	int h1;
	int m1;
	int s1;
	int h2;
	int m2;
	int s2;
}man;
int judge(man a, man b, int flag)
{
	if (flag)
	{
		if (a.h1 != b.h1)return a.h1 - b.h1;
		else if (a.m1 != b.m1) return a.m1 - b.m1;
		else if (a.s1 != b.s1) return a.s1 - b.s1;
	}
	else
	{
		if (a.h2 != b.h2)return b.h2 - a.h2;
		else if (a.m2 != b.m2) return b.m2 - a.m2;
		else if (a.s2 != b.s2) return b.s2 - a.s2;
	}
}
main()
{
	man max, min;
	max.h2 = 0;
	max.m2 = 0;
	max.s2 = 0;
	min.h1 = 23;
	min.m1 = 59;
	min.s1 = 59;
	man temp;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s %d:%d:%d %d:%d:%d", temp.name, &temp.h1, &temp.m1, &temp.s1, &temp.h2, &temp.m2, &temp.s2);
		if (judge(min, temp, 1) > 0)min = temp;
		if (judge(max, temp, 0) > 0)max = temp;
	}
	printf("%s %s", min.name, max.name);
}