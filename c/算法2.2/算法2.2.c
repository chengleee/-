#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LISTINCREMENT 2
#define LIST_INIT_SIZE 10
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType *elem;
	int length;
	int listsize;
}Sq;
//创建顺序表
Status Init(Sq *L)
{
    (*L).elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!(*L).elem)
		exit(OVERFLOW);
	(*L).length=0;
	(*L).listsize=LIST_INIT_SIZE;
	return OK;
}
//返回表长
int Listlength(Sq L)
{
	return L.length;
}
//插入元素
Status Insert(Sq *L,int i,ElemType e)
{
    ElemType *newbase;
	int *p,*q;
	if(i<1||i>(*L).length+1)
		exit(OVERFLOW);
	if((*L).length>=(*L).listsize)
	{
		newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*(sizeof(ElemType)));
		if(!newbase)
			exit(ERROR);
		(*L).elem=newbase;
		(*L).listsize+=LISTINCREMENT;
	}
	q=(*L).elem+i-1;
	for(p=(*L).length+(*L).elem-1;p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++(*L).length;
	return OK;
}
//取L的第i个数据元素赋值给e
Status GetElem(Sq L,int i,ElemType *e)
{
    if(i<1||i>L.length)
		exit(ERROR);
    else
        *e=*(L.elem+i-1);
	return OK;
}
//打印元素
void print(Sq L,int len)
{
	int i;
	int *p;
	p=L.elem;
	for(i=1;i<=len;i++)
		printf("%d ",*(p+i-1));
	printf("\n");
}

//实现算法2.2
void MergeList(Sq La,Sq Lb,Sq *Lc)
{
    int ai,bj;
	int i=1,j=1;
	int	k=0;
	int La_len=Listlength(La),Lb_len=Listlength(Lb); 
	Init(Lc);
	while((i<=La_len)&&(j<=Lb_len))
	{
	    GetElem(La,i,&ai);
		GetElem(Lb,j,&bj);
		if(ai<=bj)
		{
		    Insert(Lc,++k,ai);
			++i;
		}
		else
		{
			Insert(Lc,++k,bj);
			++j;
		}
	}
	while(i<=La_len)
	{
		GetElem(La,i++,&ai);
		Insert(Lc,++k,ai);
	}
	while(j<=Lb_len)
	{
	   GetElem(Lb,j++,&bj);
	   Insert(Lc,++k,bj);
	}
	(*Lc).length=k;
}
//主程序
main()
{
    Sq La,Lb,Lc;
	Status i;
	int j,k;
	int La_len,Lb_len,Lc_len;
	i=Init(&La);
	Init(&Lb);
	if(i==1)
		printf("请输入非递减有序数列La的元素（输入0表示终止输入）：\n");
	for(j=1,k=1;j!=0;k++)
	{
	   scanf("%d",&j);
       if(j!=0)
		   i=Insert(&La,k,j);
	}
	printf("请输入非递减有序数列Lb的元素（输入0表示终止输入）：\n");
	for(j=1,k=1;j!=0;k++)
	{
		scanf("%d",&j);
		if(j!=0)
			i=Insert(&Lb,k,j);
	}
	printf("\n");
	La_len=Listlength(La);
	Lb_len=Listlength(Lb);
	//输出La与Lb的元素
	printf("La = ");
	print(La,La_len);
	printf("\nLb = ");
	print(Lb,Lb_len);
	MergeList(La,Lb,&Lc);
	Lc_len=Listlength(Lc);
	printf("\nLc = ");
	print(Lc,Lc_len);
}