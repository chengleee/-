#include <stdio.h>
#define MAXSIZE 1000
typedef char ElemType;
typedef struct
{
    ElemType data;
	int cur;
}component,SLinkList;
//将一维数组space中各分量链成一个备用链表
void InitSpace(SLinkList space[MAXSIZE])
{
    int i;
	for(i=0;i<MAXSIZE;i++)
	{
	    space[i].cur=i+1;
		space[MAXSIZE-1].cur=0;
	}
}
//为链表分配地址
int Malloc_SL(SLinkList space[])
	//若备用空间链表非空，则返回分配的结点下标
{
    int i;
	i=space[0].cur;
	if(space[0].cur)
		space[0].cur=space[i].cur;
	return i;
}
//回收链表
void Free_SL(SLinkList space[],int k)
//将下标为k的结点回收
{
    space[k].cur=space[0].cur;
	space[0].cur=k;
}
//实现(A-B)U(B-A)
void difference(SLinkList space[])
{
    int i,j,k,m,n,p,r,s;
	char b;
    InitSpace(space);
	s=Malloc_SL(space);//生成s的头结点
	r=s;
	printf("请输入a,b的长度\n");
	scanf("%d %d",&m,&n);//输入A和B的长度
	printf("请输入a的值\n");
	for(j=1;j<=m;++j)
	{
	    i=Malloc_SL(space);
		getchar();
		scanf("%c",&space[i].data);
		space[r].cur=i;
		r=i;
	}
	space[r].cur=0;//尾结点指针为空
	printf("请依次输入b的值\n");
	for(j=1;j<=n;++j)
	{
	    getchar();
		scanf("%c",&b);//依次输入b的元素
		p=s;
		k=space[s].cur;//k指向A中第一个结点
		while(k!=space[r].cur&&space[k].data!=b)
		{
		    p=k;
			k=space[k].cur;
		}
		if(k==space[r].cur)
		{
		    i=Malloc_SL(space);
			space[i].data=b;
			if(i<r)
			{
			    space[i-1].cur=i;
				space[i].cur=i+1;
			}
			if(i>=r)
			{
			space[r].cur=i;
			space[i].cur=0;
			r=i;
			}
		}
		else
		{
		    space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k)
				r=p;
		}
	}
	
}
//主函数
main()
{
	int i;
    SLinkList space[MAXSIZE];
	difference(space);
	for(i=2;space[i-1].cur!=0;i++)
	{
	    printf("%c ",space[i].data);
	}
}