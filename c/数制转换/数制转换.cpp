#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef int SElemType;
typedef struct		//����ջ
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &s)		//����һ����ջ
{
	s.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!s.base)
		exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &s,SElemType e)		//��ջ
{
	if(s.top-s.base>=s.stacksize)
	{
		s.base=(SElemType *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!s.base)
			exit(OVERFLOW);
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*s.top++=e;
	return OK;
}

Status Pop(SqStack &s,SElemType &e)		//��ջ
{
	if(s.top==s.base)
		return ERROR;
	e=*--s.top;
	return OK;
}

Status StackEmpty(SqStack s)		//�ж�ջ�Ƿ�Ϊ��
{
	if(s.top==s.base)
		return 1;
	else
		return 0;
}

void conversion()
{
	SqStack S;
	int e,n;
	InitStack(S);
	printf("������һ��ʮ����������\n");
	scanf("%d",&e);
	while(e)
	{
		Push(S,e%8);
		e=e/8;
	}
	printf("ת��Ϊ8��������\n");
	while(!StackEmpty(S))
	{
		Pop(S,n);
		printf("%d",n);
	}
	printf("\n");
}

int main()
{
	conversion();
}