#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define OVERFLOW -1
#define FALSE 0
#define OVER
#define stack_init_size 100
#define stackincrement 10
char c[]={'+','-','*','/','(',')','=','^'};		//符号库
typedef int status;
typedef char elem;
typedef float trelem;			//transform
//定义数据队列
typedef struct QNode
{
	trelem data;
	struct QNode *next;
}QNode;
typedef struct
{
	QNode *front,*rear;
}LinkQueue;
//定义转换数据栈
typedef struct
{
	trelem *top,*base;
	int stacksize;
}TrStack;
//定义符号栈
typedef struct
{
	elem *top,*base;
	int stacksize;
}ChStack;
/******求指数******/
float Pow(float a,int b)
{
	int i;
	float p=a;
	if(b==0)
		return 1;
	for(i=1;i<b;i++)
	{
		p*=a;
	}	
	return p;
}
/******初始化栈及队列******/
status all_init(LinkQueue *L,TrStack *T,ChStack *C)
{
	L->front=L->rear=(QNode *)malloc(sizeof(QNode));
	if(!L->front)
		exit(OVERFLOW);
	L->front->next=NULL;
	T->base=(trelem *)malloc(stack_init_size*sizeof(trelem));
	C->base=(elem *)malloc(stack_init_size*sizeof(elem));
	if(!T->base||!C->base)
		exit(OVERFLOW);
	T->top=T->base;
	C->top=C->base;
	T->stacksize=stack_init_size;
	C->stacksize=stack_init_size;
	return OK;
}
/******入符号栈******/
status PushCh(ChStack *C,elem e)
{
	if(C->top-C->base>=C->stacksize)
	{
		C->base=(elem *)realloc(C->base,(C->stacksize+stackincrement)*sizeof(elem));
		if(!C->base)
			exit(OVERFLOW);
		C->top=C->base+C->stacksize;
		C->stacksize+=stackincrement;
	}
	*C->top++=e;
	return OK;
}
/******入数据栈******/
status PushTr(TrStack *T,trelem e)
{
	if(T->top-T->base>=T->stacksize)
		{
			T->base=(trelem *)realloc(T->base,(T->stacksize+stackincrement)*sizeof(trelem));
			if(!T->base)
				exit(OVERFLOW);
			T->top=T->base+T->stacksize;
			T->stacksize+=stackincrement;
		}
		*T->top++=e;
		return OK;
}
/******出符号栈******/
status PopCh(ChStack *C,elem *e)
{
	if(C->top==C->base)
		return ERROR;
	*e=*--C->top;
	return OK;
}
/******出数据栈******/
status PopTr(TrStack *T,trelem *e)
{
	if(T->top==T->base)
		return ERROR;
	*e=*--T->top;
	return OK;
}
/******插入数据队列******/
status EnQueue(LinkQueue *L,elem e)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	L->rear->next=p;
	L->rear=p;
	return OK;
}
/******从头出队列******/
status FrQueue(LinkQueue *L,elem *e)
{
	QNode *p;
	if(L->rear==L->front)
		return ERROR;
	p=L->front->next;
	*e=p->data;
	L->front->next=p->next;
	if(L->rear==p)
		L->rear=L->front;
	free(p);
	p=NULL;
	return OK;
}
/******获取ChStack栈顶元素******/
char GetTop(ChStack C)
{
	elem e,*p;
	p=C.top-1;
	e=*p;
	return e;
}
/******比较优先级******/
char compare(ChStack C,elem e)
{
	switch(GetTop(C))
		{
			case '+':
			case '-':
				if(e=='+'||e=='-'||e==')'||e=='=')
					return '>';
				else if(e=='*'||e=='/'||e=='('||e=='^')
					return '<';
				else
					return ERROR;
		  		break;
			case '*':
			case '/':
				if(e=='+'||e=='-'||e=='*'||e=='/'||e==')'||e=='=')
					return '>';
				else if(e=='('||e=='^')
					return '<';
				else
					return ERROR;
				break;
			case '(':
				if(e==')')
					return '=';
				else if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e=='^')
					return '<';
				else
					return ERROR;
				break;
			case ')':
				if(e=='+'||e=='-'||e=='*'||e=='/'||e=='>'||e=='='||e==')'||e=='^')
					return '>';
				else
					return ERROR;
				break;
			case '=':
				if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e=='^')
					return '<';
				else if(e=='=')
					return '=';
				else
					return ERROR;
				break;
			case '^':
				if(e=='+'||e=='-'||e=='*'||e=='/'||e==')'||e=='='||e=='^')
					return '>';
				else if(e=='(')
					return '<';
				else
					return ERROR;
				break;	
			default:
					return ERROR;
					break;
		}
}
/******数据转换******/
//整数部分
int Ztransform(LinkQueue *L)
{
	int s=0;
	int i=0;
	elem e;
	QNode *p;
	p=L->front->next;
	while(p!=L->rear)
	{
		i++;
		p=p->next;
	}	
	i++;
	while(L->rear!=L->front)
	{
		FrQueue(L,&e);
		s+=(int)(e-'0')*Pow(10,i-1);
		i--;
	}
	return s;
}
//小数部分
float ftransform(LinkQueue *L)
{
	int i=1;
	float f=0;
	elem e;
	while(L->rear!=L->front)
	{
		FrQueue(L,&e);
		f+=(float)(e-'0')*Pow(0.1,i);
		i++;
	}
	return f;
}
/******是否在符号库中******/
status inc(elem e)
{
	int i;
	i=0;
	while(c[i]!=0)
	{
		if(e==c[i])
			return OK;
		i++;
	}
	return ERROR;
}
/******计算a+b******/
float calculate(float a,char b,float c)
{
	switch(b)
	{
	case '+':
		return (a+c);
		break;
	case '-':
		return (a-c);
		break;
	case '*':
		return (a*c);
	case '/':
		return (a/c);
		break;
	case '^':
		return Pow(a,c);
	default:
		return ERROR;
		break;
	}
}
int main()
{
	while(1){
	int i;
	int	z;
	float a,c,f,s;
	elem b,e;
	TrStack T;
	ChStack C;
	LinkQueue L;	
	all_init(&L,&T,&C);
	PushCh(&C,'=');	
	printf("\n计算说明:\n用来计算表达式的值，遵循计算法则，特意加入了指数算法\n请不要输入负数，会出现意想不到的结果。\n由于您的程序员很忙，没有时间修改这个bug，请不要扔板砖(^.^)。\n\n");
	printf("请输入表达式(注间表达式的末尾一定要'='):\n");
	e=getchar();
	while(e!='='||GetTop(C)!='=')
	{
		if((e>='0'&&e<='9')||e=='.')
		{
			if(e>='0'&&e<='9')
			{
				while(e>='0'&&e<='9')
				{
					EnQueue(&L,e);
					e=getchar();
				}
				z=Ztransform(&L);
				s=z;
			}
			if(e=='.')
			{
				e=getchar();
				while(e>='0'&&e<='9')
				{
					EnQueue(&L,e);
					e=getchar();
				}
				f=ftransform(&L);
				if(e=='.')
					return ERROR;
				s=z+f;
			}
			PushTr(&T,s);
		}
		else if(inc(e))
		{
			switch(compare(C,e))
			{
			case '<':
				PushCh(&C,e);
				e=getchar();
				break;
			case '=':
				PopCh(&C,&e);
				e=getchar();
				break;
			case '>':
				PopTr(&T,&c);
				PopTr(&T,&a);
				PopCh(&C,&b);
				PushTr(&T,calculate(a,b,c));
				break;
			default:
				return ERROR;
				break;
			}
		}
		else
			return ERROR;
	}
	PopTr(&T,&s);
	printf("计算结果:%f\n",s);
	printf("是否退出:(退出计算输入0,继续计算输入1)\n");
	free(L.front);L.rear=L.front=NULL;
	free(T.base);T.top=T.base=NULL;
	free(C.base);C.top=C.base=NULL;
	scanf("%d",&i);
	getchar();
	if(!i)
		exit(0);
	}
}
