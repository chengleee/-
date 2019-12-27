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
//��������
void CreateList_L(LinkList *&L,int n)
	//����λ����n��Ԫ�أ���������ͷ���ĵ������Ա�L��
{
	int i,a;
	LinkList *p;
	L=(LinkList *)malloc(sizeof(struct LNode));//����һ����ͷ���ĵ�����
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
//�������
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
//ʵ�ֽ����������Ϊһ�������
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
//������
int length()
{
	int n;
    printf("����La����ĳ���:");
	scanf("%d",&n);
	printf("\n");
	return n;
}
//������
int main()
{
	int a,b,c;
    LinkList *La,*Lb,*Lc;
	a=length();
	printf("�밴�ݼ�˳������La��Ԫ��\n");
	CreateList_L(La,a);
	b=length();
	printf("�밴�ݼ�˳������Lb��Ԫ��\n");
	CreateList_L(Lb,b);
	c=a+b;	
	printf("����La=");
	print(La);
	printf("����Lb=");
	print(Lb);
	MergeList_L(La,Lb,Lc);
	printf("����Lc=");
	print(Lc);
}