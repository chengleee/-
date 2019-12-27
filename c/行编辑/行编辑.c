#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define YES 1
#define FALSE 0
#define OVERFLOW -1
#define init_stack_size 100
#define increment 10
typedef int status;
typedef char elemtype;
typedef struct		//定义栈类型
{
	elemtype *base;
	elemtype *top;
	int stacksize;
}stack;

status initstack(stack *s)		//初始化栈
{
	s->base=(elemtype *)malloc(init_stack_size*sizeof(elemtype));
	if(!s->base)
		exit(OVERFLOW);
	s->top=s->base;
	s->stacksize=init_stack_size;
	return OK;
}

status Push(stack *s,elemtype e)		//入栈
{
	if(s->top-s->base>=init_stack_size)
	{
		s->base=(elemtype *)realloc(s->base,(s->stacksize+increment)*sizeof(elemtype));
		if(!s->base)
			exit(OVERFLOW);
		s->top=s->base+s->stacksize;
		s->stacksize+=increment;
	}
	*s->top++=e;
	return OK;
}

status Pop(stack *s,elemtype *e)		//出栈
{
	if(s->top==s->base)
		return ERROR;
	*e=*--s->top;
	return OK;
}

status clearstack(stack *s)			//清空栈
{
	s->top=s->base;
	return OK;
}

status destroystack(stack *s)		//销毁栈
{
	if(!s->base)
	{
		s->top=s->base;
		free(s->base);
		s->top=NULL;
		s->base=NULL;
		return OK;
	}
	else 
		return ERROR;
}

void lineedit()
{
	char c,ch,*p;
	stack s;
    initstack(&s);	
	ch=getchar();
	while(ch!=EOF)
	{
		while(ch!=EOF&&ch!='\n')
		{
			switch(ch)
			{
			case '#':
				Pop(&s,&c);
				break;
			case '@':
				clearstack(&s);
				break;
			default:
				Push(&s,ch);
				break;
			}
			ch=getchar();
		}
		p=s.base;
		while(p!=s.top)
		{
			putchar(*p);
			p++;
		}
		putchar(10);
		clearstack(&s);
		if(ch!=EOF)
			ch=getchar();
	}
	destroystack(&s);
}

int main()
{
	lineedit();
}