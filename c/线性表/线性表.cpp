#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType date;
	struct LNode *next;
}LinkList;
//创建链表
void CreateList_L(LinkList *&L,int n)
	//逆序位输入n个元素，建立带表头结点的单链线性表L。
{
	int i,a;
	LinkList *p;
	L=(LinkList *)malloc(sizeof(struct LNode));//建立一个带头结点的单链表
	L->next=NULL;
	for(i=n;i>0;--i)
	{
        p=(LinkList *)malloc(sizeof(struct LNode));
	    scanf("%d",&a);
		p->date=a;
		p->next=L->next;
	    L->next=p;
	}
}
//输出链表
void print(LinkList *L)
{
	LinkList *p;
	p=L->next;
	while(p)
	{
		printf("%d ",p->date);
		p=p->next;
	}
	printf("\n");
}
//实现将两个有序表并为一个有序表
void MergeList_L(LinkList *La,LinkList *&Lb,LinkList *&Lc)
{
	LinkList *pa,*pb,*pc;
	pa=La->next;pb=Lb->next;
	Lc=pc=La;
	while(pa&&pc)
	{
	    if(pa->date<=pb->date)
		{
		    pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(Lb);
}
//链表长度
int length()
{
	int n;
    printf("输入La链表的长度:");
	scanf("%d",&n);
	printf("\n");
	return n;
}
//主函数
int main()
{
	int a,b,c;
    LinkList *La,*Lb,*Lc;
	a=length();
	printf("请按递减顺序输入La的元素\n");
	CreateList_L(La,a);
	b=length();
	printf("请按递减顺序输入Lb的元素\n");
	CreateList_L(Lb,b);
	c=a+b;	
	printf("链表La=");
	print(La);
	printf("链表Lb=");
	print(Lb);
	MergeList_L(La,Lb,Lc);
	printf("链表Lc=");
	print(Lc);
}