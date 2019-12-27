#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALUSE 0
#define OVERFLOW -1
typedef int Status;
typedef struct
{
    float coef;  //ϵ��
	int expn;  //ָ��
}term; 

typedef struct LNode 
{
	term data;
	struct LNode *next;
}*Link,*Position;

typedef struct
{
    Link head,tail;
	int len;
}Polynomial;

Status InitPoly(Polynomial &L)  //����������
{
    L.head=(Link)malloc(sizeof(LNode));
	L.tail=L.head;
	L.len=0;
	return OK;
}

void CreatPoly(Polynomial &L)
{
	Link p,q,r;
	p=(Link)malloc(sizeof(LNode));
	scanf("%f,%d",&p->data.coef,&p->data.expn);
	L.head->next=p;
	q=p;
	L.tail=p;
	L.len++;
	do
	{
		r=(Link)malloc(sizeof(LNode));
		scanf("%f,%d",&r->data.coef,&r->data.expn);
		q->next=r;
		q=r;
		L.tail=r;
		r->next=NULL;
		L.len++;
	}while(r->data.coef||r->data.expn);
}

Position GetHead(Polynomial L)
{
    return L.head;
}

int GetCurElem(Link L)  //����ָ��
{
    return L->data.expn;
}

int compare(int a,int b)
{
    if(a<b)
		return -1;
	if(a==b)
		return 0;
	else
		return 1;
}

void AddPolyn(Polynomial &La,Polynomial &Lb,int (*com)(int,int))
{
	int a,b;
    Link p,q,r,m;
	r=La.head;
	p=La.head->next;
	q=Lb.head->next;
	while(p->next&&q->next)
	{
	a=GetCurElem(p);
	b=GetCurElem(q);
	switch((*com)(a,b))
	{
	case -1:
		p=p->next;
		r=r->next;
		break;
	case 0:
		p->data.coef+=q->data.coef;
		p=p->next;
		r=r->next;
		q=q->next;
		Lb.len--;
		break;
	case 1:
	    m=q->next;
		r->next=q;
		r=q;
		q->next=p;
		q=m;
		Lb.len--;
		La.len++;
		break;
	}  //switch
    }  //while
	if(q)
	{
		if(r->next->data.coef)
		    p->next=q;
	    else
		    r->next=q;
	}
	La.len=La.len+Lb.len-2;
	free(Lb.head);
}

void print(Polynomial L)
{
	int i;
    Link q;
	q=L.head->next;
	printf("La=");
	for(i=1;i<=L.len;i++)
	{
	    printf("%f x^ %d + ",q->data.coef,q->data.expn);
		q=q->next;
	}
	printf("0\n");
}

int main()
{
    Polynomial La,Lb;
	InitPoly(La);
	InitPoly(Lb);
	printf("������һԪ����ʽ��Laϵ����ָ���������ʽa,b������0,0��������\n");
	CreatPoly(La);
	printf("������һԪ����ʽ��Lbϵ����ָ���������ʽa,b������0,0��������\n");
	CreatPoly(Lb);
	AddPolyn(La,Lb,compare);
	print(La);
}