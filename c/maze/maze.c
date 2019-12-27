#include <stdio.h>
#include <stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define stack_init_size 100
#define increment 10
int ma[10][10] = { { 1,1,1,1,1,1,1,1,1,1 },
                   { 1,0,0,1,0,0,0,1,0,1 },
		   { 1,0,0,1,0,0,0,1,0,1 },
		   { 1,0,0,0,0,1,1,0,0,1 },
	           { 1,0,1,1,1,0,0,0,0,1 },
		   { 1,0,0,0,1,0,0,0,0,1 },
		   { 1,0,1,0,0,0,1,0,0,1 },
		   { 1,0,1,1,1,0,1,1,0,1 },
		   { 1,1,0,0,0,0,0,0,0,1 },
		   { 1,1,1,1,1,1,1,1,1,1 } };
typedef int status;
typedef struct
{
	int m;		//¿¿¿
	int n;		//¿¿¿
}postype;		//¿¿¿¿
typedef struct
{
	int ord;	//¿¿¿¿¿¿¿¿¿¿
	postype seat;	//¿¿¿¿¿¿¿¿¿¿¿¿
	int di;		//¿¿¿¿¿¿¿¿
}selemtype;		//¿¿¿¿¿¿
typedef struct
{
	selemtype *base;
	selemtype *top;
	int stacksize;
}stack;			//¿¿¿

status initstack(stack *s)	//¿¿¿¿
{
	s->base = (selemtype *)malloc(stack_init_size * sizeof(selemtype));
	if (!s->base)
		exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = stack_init_size;
	return OK;
}

status Push(stack *s, selemtype e)	//¿¿
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (selemtype *)realloc(s->base, (s->stacksize + increment) * sizeof(selemtype));
		if (!s->base)
			exit(OVERFLOW);
		s->top = s->base + s->stacksize;
		s->stacksize += increment;
	}
	*s->top++ = e;
	return OK;
}

status Pop(stack *s, selemtype *e)		//¿¿
{
	if (s->top == s->base)
		return ERROR;
	*e = *--s->top;
	return OK;
}

status pass(selemtype e, stack s)	//¿¿¿¿¿¿¿¿¿¿
{
	selemtype *p;
	if (!ma[e.seat.m][e.seat.n])
	{
		p = s.base;
		while (p != s.top)
		{
			if (p->seat.m == e.seat.m&&p->seat.n == e.seat.n)
				return 0;
			else
				p++;
		}
		return 1;
	}
	else
		return 0;
}

void print(stack s)             //¿¿¿¿¿
{
	selemtype *p;
	p = s.base;
	while (p != s.top)
	{
		printf("(%d,%d)->", p->seat.m, p->seat.n);
		p++;
	}
	printf("end");
	putchar(10);
}

status mazepath()		//¿¿¿¿
{
	stack s, l;
	selemtype e;
	postype start, end;
	start.m = 1;
	start.n = 1;
	end.m = 8;
	end.n = 8;
	initstack(&s);
	initstack(&l);
	e.ord = 1;
	e.seat = start;
	e.di = 1;
	do
	{
		if (pass(e, l))
		{
			Push(&s, e);
			Push(&l, e);
			if (e.seat.m == end.m&&e.seat.n == end.n)
			{
				print(s);
				return OK;
			}
			e.ord++;
			e.seat.n++;
			e.di = 1;
		}
		else
		{
			if (s.top != s.base)
			{
				Push(&l, e);
				Pop(&s, &e);
				Push(&s,e);
				e.di = (l.top - 1)->di;
				l.top++;
				while (s.top != s.base&&e.di == 4)
				{
					Push(&l, e);
					Pop(&s, &e);
				}
				if (e.di<4)
				{
					e.di++;
					Push(&l, e);
					switch (e.di)
					{
					case 2:
						e.seat.m++;
						break;
					case 3:
						e.seat.n--;
						break;
					case 4:
						e.seat.m--;
						break;
					default:
						break;
					}
				}
			}
		}
	} while (s.top != s.base);
	return FALSE;
}

int main()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf(" %d ",ma[i][j]);
		}
		putchar(10);
	}
	printf("load:\n");
	mazepath();
}
