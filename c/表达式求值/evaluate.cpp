#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char OperandType;
typedef int Status;
typedef struct
{
	OperandType *top;
	OperandType *base;
	int stacksize;
}OPTR,OPND;		//OPTR means operator,OPND means operand

Status InitStack(OPND &s)	//Initiate SqStack
{
	s.base=(OperandType *)malloc(STACK_INIT_SIZE*sizeof(OperandType));
	if(!s.base)
		exit(OVERFLOW);
	s.top=s.base;
	s.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(OPND &s,OperandType e)
{
	if(s.top-s.base>=STACK_INIT_SIZE)
	{
		s.base=(OperandType *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(OperandType));
		if(!s.base)
			exit(OVERFLOW);
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCREMENT;
	}
	*s.top++=e;
	return OK;
}

Status Pop(OPND &s,OperandType &e)
{
	if(s.top==s.base)
		return ERROR;
	e=*--s.top;
	return OK;
}

OperandType GetTop(OPND s)	//Get top data
{
	OperandType e;
	if(s.top==s.base)
		return ERROR;
	e=*--s.top;
	s.top++;
	return e;
}

OperandType precede(OPTR s,OperandType e)	//compare priority
{
	switch(GetTop(s))
	{
		case '+':
		case '-':
			if(e=='+'||e=='-'||e==')'||e=='#')
				return '>';
			else if(e=='*'||e=='/'||e=='(')
				return '<';
			else
				return ERROR;
	  		break;
		case '*':
		case '/':
			if(e=='+'||e=='-'||e=='*'||e=='/'||e==')'||e=='#')
				return '>';
			else if(e=='(')
				return '<';
			else
				return ERROR;
			break;
		case '(':
			if(e==')')
				return '=';
			else if(e=='+'||e=='-'||e=='*'||e=='/'||e=='(')
				return '<';
			else
				return ERROR;
			break;
		case ')':
			if(e=='+'||e=='-'||e=='*'||e=='/'||e=='>'||e=='#'||e==')')
				return '>';
			else 
				return ERROR;
			break;
		case '#':
			if(e=='+'||e=='-'||e=='*'||e=='/'||e=='(')
				return '<';
			else if(e=='#')
				return '=';
			else 
				return ERROR;
			break;
			default:
				return ERROR;
				break;
	}
}

int Operate(char a,char b,char c)
{
	if (a >='0'&&a <= '9')
		a = a - '0';
	if (c >= '0'&&c <= '9')
		c = c - '0';
	switch(b)
	{
		case '+':
			return (a+c);
			break;
		case '-':
			return (a-c);
		case '*':
			return (a*c);
			break;
		case '/':
			return (a/c);
			break;
		default:
			return ERROR;
			break;
	}
}

OperandType EvaluateExpression(OPTR &TR,OPND &ND)	//come ture algorithm（算法）
{
	char a,b,c,x;
	InitStack(TR);
	Push(TR,'#');
	InitStack(ND);
	c=getchar();
	while (c != '#' || GetTop(TR) != '#')
	{
		if (c >= '0'&&c <= '9')
		{
			Push(ND, c);
			c = getchar();
		}
		else
		{
			switch (precede(TR, c))
			{
			case '<':
				Push(TR, c);
				c = getchar();
				break;
			case '=':
				Pop(TR, x);
				c = getchar();
				break;
			case '>':
				Pop(TR, x);
				Pop(ND, b);
				Pop(ND, a);
				Push(ND, (char)Operate(a, x, b));
				break;
			default:
				return ERROR;
				break;
			}
		}
	}
	return GetTop(ND);
	
}

int main()
{
	int s;
	OPTR TR;
	OPND ND;
	EvaluateExpression(TR,ND);
	s=(int)GetTop(ND);
	printf("%d",s);
	putchar(10);
}
