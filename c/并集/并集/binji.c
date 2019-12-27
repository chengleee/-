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
//判断元素关系
Status equal(ElemType c1,ElemType c2)
{
	if(c1==c2)
		return TRUE;
	else 
		return FALSE;
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
	    newbase=(ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)
			exit(ERROR);
		(*L).elem=newbase;
		(*L).listsize+=LISTINCREMENT;
	}
	q=(*L).elem+i-1;
	for (p=(*L).length+(*L).elem-1;p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++(*L).length;
	return OK;
}
//打印元素
void print(Sq L,int len)
{
	int i;
	int *p;
	p=L.elem;
	for (i=1;i<=len;i++)
        printf("%d ",*(p+i-1));
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
//在顺序表L中查找第1个值与e满足compare()的元素的位序
int LocateElem(Sq L,ElemType e,Status (*compare)(ElemType,ElemType))
{
    //若找到，则返回其在L中的位序，否则返回0
	ElemType *p;
	int i=1;
	p=L.elem;
	while(i<=L.length&&!compare(*p++,e))
		++i;
	if(i<=L.length)
		return i;
	else 
		return 0;
}
//实现A=AUB
void Union(Sq *La,Sq Lb)
{
	ElemType e;
	int i;
	int La_len,Lb_len;
	La_len=Listlength(*La);
	Lb_len=Listlength(Lb);
	for(i=1;i<=Lb_len;i++)
	{
	    GetElem(Lb,i,&e);
		if(!LocateElem(*La,e,equal))
			Insert(La,++La_len,e);//La中不存在和e相同的数据元素，则插入之
	}
}

//主程序
int main()
{
    Sq La,Lb;
	Status i;
	int j,k;
	int La_len,Lb_len;
	i=Init(&La);
	Init(&Lb);
	if(i==1)//创建顺序表成功
		//输入元素，输入为0表示终止输入
		printf("请输入La的元素（输入0表示终止输入）：\n");
	//输入La的元素
	for(j=1,k=1;j!=0;k++)
	{
		scanf("%d",&j);
		if(j!=0)
			i=Insert(&La,k,j);
	}
	printf("请输入Lb的元素（输入0终止输入）：\n");
	for(j=1,k=1;j!=0;k++)
	{
	    scanf("%d",&j);
		if(j!=0)
			i=Insert(&Lb,k,j);
	}
	La_len=Listlength(La);
	Lb_len=Listlength(Lb);
	//输出La与Lb的元素
	printf("La = ");
	print(La,La_len);
	printf("\nLb = ");
	print(Lb,Lb_len);
	Union(&La,Lb);
	La_len=Listlength(La);
	printf("\nnew La = ");
	print(La,La_len);
	printf("\n**************programmed by DXH942***********************\n");
}