#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define stack_init_size 100
#define stackincrement 10
typedef int Status;
typedef char selemtype;
typedef struct		//定义栈
{
	selemtype *top;
	selemtype *base;
	int stacksize;
}sqstack;

Status initstack(sqstack &s)		//创建栈
{
	s.base=(selemtype *)malloc(stack_init_size*sizeof(selemtype));
	if(!s.base)
		exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=stack_init_size;
	return OK;
}

Status Push(sqstack &s,selemtype e)		//入栈
{
	if(s.top-s.base>=stack_init_size)
	{
	s.base=(selemtype *)realloc(s.base,(s.stacksize+stackincrement)*sizeof(selemtype));
	if(!s.base)
		exit(OVERFLOW);
	s.top=s.base+s.stacksize;
	s.stacksize+=stackincrement;
	}
	*s.top=e;
	s.top++;
	return OK;
}

Status Pop(sqstack &s,selemtype &e)		//出栈
{
	if(s.top==s.base)
		return ERROR;
	e=*--s.top;
	return OK;
}

void test()
{
	selemtype a,e;
	sqstack s;
	initstack(s);
	printf("请输入符号(输入Ctrl+2结束，即空字符):\n");
	scanf("%c",&e);
	Push(s,e);
	while(e)
	{
		getchar();  // 吸收回车
		scanf("%c",&e);
		a=*--s.top;
		s.top++;
		if(e==a+1||e==a+2)
		{
			Pop(s,a);
		}
		else if(!e)
			continue;
		else
			Push(s,e);
	}
	if(s.top==s.base)
		printf("符号匹配\n");
	else
		printf("符号不匹配\n");
}

int main()
{
	test();
}
