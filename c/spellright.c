#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char c[10];
}Base;
typedef struct
{
	int stacksize;
	Base *base;
	Base *top;
}stack;

void stack_init(stack *s)
{
	(*s).stacksize = 1000;
	(*s).base = (Base *)malloc(1000 * sizeof(Base));
	(*s).top = (*s).base;
}

void push_stack(stack *s, char *c)
{
	if (s->top - s->base >= s->stacksize)
	{
		(*s).base = (Base *)realloc((*s).base, ((*s).stacksize + 100) * sizeof(Base));
		(*s).top = (*s).base + (*s).stacksize;
		(*s).stacksize += 100;
	}
	int i;
	for (i = 0; *c; ++i)
	{
		(*s).top->c[i] = *c;
		c++;
	}
	(*s).top->c[i] = 0;
	(*s).top++;
}

void print_stack(stack s)
{
	if (s.top != s.base)
	{
		s.top--;
		for (int i = 0; s.top->c[i]; ++i)
		{
			printf("%c", s.top->c[i]);
		}
		while (s.top != s.base)
		{
			s.top--;
			printf(" ");
			for (int i = 0; s.top->c[i]; ++i)
			{
				printf("%c", s.top->c[i]);
			}
		}
	}
}

main()
{
	stack s;
	stack_init(&s);
	char N[101];
	int temp, sum = 0;
	char *c[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int i = 0;
	char a;
	do {
		scanf("%c", &a);
		N[i++] = a;
	} while (a != '\n');
	for (i = 0; N[i] != '\n'; ++i)
	{
		sum += N[i] - '0';
	}
	if (sum == 0 && N[0] != '\n')
	{
		push_stack(&s, c[0]);
	}
	while (sum)
	{
		temp = sum % 10;
		sum /= 10;
		push_stack(&s, c[temp]);
	}
	print_stack(s);
}