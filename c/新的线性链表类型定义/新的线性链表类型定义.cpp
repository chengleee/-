#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int Status;
typedef int ElemType;

typedef struct LNode  //结点类型
{
    ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct  //链表类型
{
    Link head,tail;
	int len;
}LinkList;

Status InitList(LinkList &L)  //构造一个空的线性表
{
    L.head=(Link)malloc(sizeof(LNode));
	L.tail=L.head;
	L.len=0;
	if(L.head)
	    return OK;
	else
		exit(OVERFLOW);
}

Status CreatList(Link &p,LinkList &L,int n)
{
   int i;
   Link q;
	p=(Link)malloc(sizeof(LNode));
   scanf("%d",&p->data);
   L.head->next=p;
   p->next=NULL;
   L.tail=p;
   L.len++;
   for(i=2;i<=n;i++)
   {
	   q=(Link)malloc(sizeof(LNode));
       scanf("%d",&q->data);
	   p->next=q;
	   q->next=NULL;
	   p=q;
	   L.tail=p;
	   L.len++;
   }
   return OK;
}

Position GetHead(LinkList L)  //返回链表中头结点位置
{
    return L.head;
}

Position NextPos(LinkList L,Link p)  //返回p所指结点的直接后继位置
{
    return p->next; 
}

ElemType GetCurElem(Link p)  //返回p所指结点中数据元素的值
{
    return p->data;
}

Status compare(int a,int b)  //比较元素a,b大小
{
    if(a<b)
		return -1;
	else if(a==b)
	    return 0;
	else
		return 1;
}

Status DelFirst(Link h,Link &q)  //已知h指向链表的头结点，删除链表中的第一个结点并以q返回
{
	q=h->next;
	h->next=q->next;
	return OK;
}

Status Append(LinkList &L,Link s)  //将指针s所指的一串结点链接在L的最后一个结点
{
    L.tail->next=s;
	return OK;
}

void FreeNode(Link &p)  //释放P所指的结点
{
    free(p);
}

Status MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc,int(*compare)(ElemType,ElemType))
{
   int a,b;
   Link ha,hb,pa,pb,q;
	if(!InitList(Lc))
		return ERROR;
	ha=GetHead(La);
	hb=GetHead(Lb);
	pa=NextPos(La,ha);
	pb=NextPos(Lb,hb);
	while(pa&&pb)
	{
	    a=GetCurElem(pa);
		b=GetCurElem(pb);
		if((*compare)(a,b)<=0)
		{
		    DelFirst(ha,q);
			Lc.tail->next=q;
			Lc.tail=q;
			Lc.tail->next=NULL;
			pa=NextPos(La,ha);
		}
		else
		{
		    DelFirst(hb,q);
			Lc.tail->next=q;
			Lc.tail=q;
			Lc.tail->next=NULL;
			pb=NextPos(La,hb);
		}
	}
		if(pa)
			Append(Lc,pa);
		else
		    Append(Lc,pb);
		FreeNode(ha);
		FreeNode(hb);
		return OK;
	
}

void print(LinkList L,int n)
{
	int i;
	Link p;
	p=L.head->next;
	for(i=1;i<=n;i++)
    {
		printf("%d ",p->data);
		p=p->next;
	}
}

int main()
{
	int n1,n2;
	LinkList La,Lb,Lc;
	Link p,q;
    InitList(La);
	InitList(Lb);
	printf("请输入La的长度:\n");
	scanf("%d",&n1);
	printf("请按递增顺序输入La的元素\n");
	CreatList(p,La,n1);
	printf("请输入Lb的长度：\n");
	scanf("%d",&n2);
	printf("请按递增顺序输入Lb的元素\n");
	CreatList(q,Lb,n2);
	MergeList_L(La,Lb,Lc,compare);
	printf("Lc的元素为：\n");
	print(Lc,n1+n2);
}