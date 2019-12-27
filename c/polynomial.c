#include <stdio.h>
#include <stdlib.h>

#define OVERFLOW -1
#define OK 1
#define FALSE 0
typedef int status;
typedef struct node
{
	struct node *next;
	int e;
	float c;
}node;

typedef struct
{
	node *head;
	int length;
}polynomial;

status pol_init(polynomial *p)
{
	//p = (polynomial *)malloc(sizeof(polynomial));
	(*p).head = (node *)malloc(sizeof(node));
	if (!(*p).head)
		return OVERFLOW;
	(*p).length = 0;
	(*p).head->next = NULL;
	return OK;
}

status pol_creat(polynomial *p)
{
	float c;
	int e, i;
	node *q, *r;
	scanf("%d", &(*p).length);
	if ((*p).length < 1 || (*p).length >10)
		return OVERFLOW;
	scanf("%d %f", &e, &c);
	if (e > 1000 || e < 0)
		return OVERFLOW;
	q = (node *)malloc(sizeof(node));
	if (!q)
		return OVERFLOW;
	q->e = e;
	q->c = c;
	(*p).head->next = q;
	q->next = NULL;
	i = (*p).length - 1;
	if (!c)
		(*p).length -= 1;
	while (i--)	// 不考虑指数重复情况
	{
		scanf("%d %f", &e, &c);
		if (c)
		{
			r = (node *)malloc(sizeof(node));
			if (!r)
				return OVERFLOW;
			r->e = e;
			r->c = c;
			q->next = r;
			q = r;
			q->next = NULL;
		}
		else
			(*p).length -= 1;
	}
	return OK;

}

polynomial * poly_add(polynomial *p1, polynomial *p2)
{
	node *q, *r, *s, *t;	// t为临时指针,s指向q的前一个结点
	s = (*p1).head;
	q = (*p1).head->next;
	r = t = (*p2).head->next;
	if (!q)
		return p2;
	if (!r)
		return p1;
	if (q->e < r->e)	// 将比q->e大的结点插到q的前面
	{
		(*p1).head->next = r;
		if (r->c)
		{
			(*p1).length += 1;
			(*p2).length -= 1;
		}
		while (r->next && (q->e < r->next->e))
		{
			r = r->next;
			if (r->c)
			{
				(*p1).length += 1;
				(*p2).length -= 1;
			}
		}
		t = r->next;
		r->next = q;
		s = r;
		r = t;
	}
	while (q && r)
	{
		if (q->e > r->e)
		{
			s = q;
			q = q->next;
		}
		else if (q->e == r->e)
		{
			if (!q->c)
				(*p1).length += 1;
			if (!r->c)
				(*p2).length += 1;
			q->c += r->c;
			if (q->c == 0)
			{
				s->next = q->next;
				free(q);
				(*p1).length -= 1;
				(*p2).length -= 1;
				q = s->next;
				t = r;
				r = r->next;
				free(t);
			}
			else
			{
				t = r;
				r = r->next;
				free(t);
				(*p2).length -= 1;
			}
		}
		else
		{
			if (r->c != 0)
			{
				(*p1).length += 1;
				(*p2).length -= 1;
			}
			s->next = r;
			t = r->next;
			r->next = q;
			s = r;
			r = t;
		}
	}
	if (r)
	{
		s->next = r;
		(*p1).length += (*p2).length;
		return p1;
	}
	return p1;
}

void print(polynomial *p)
{
	printf("%d", p->length);
	if (p->length != 0)
	{
		node *q = p->head->next;
		while (q)
		{
			if (q->c)
				printf(" %d %.1f", q->e, q->c);
			q = q->next;
		}
	}
}

main()
{
	polynomial p1, p2, *q;
	pol_init(&p1);
	pol_init(&p2);
	pol_creat(&p1);
	getchar();
	pol_creat(&p2);
	q = poly_add(&p1, &p2);
	print(q);
}