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
//����˳���
Status Init(Sq *L)
{
	(*L).elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!(*L).elem)
		exit(OVERFLOW);
	(*L).length=0;
	(*L).listsize=LIST_INIT_SIZE;
	return OK;
}
//�ж�Ԫ�ع�ϵ
Status equal(ElemType c1,ElemType c2)
{
	if(c1==c2)
		return TRUE;
	else 
		return FALSE;
}
//���ر�
int Listlength(Sq L)
{
	return L.length;
}
//����Ԫ��
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
//��ӡԪ��
void print(Sq L,int len)
{
	int i;
	int *p;
	p=L.elem;
	for (i=1;i<=len;i++)
        printf("%d ",*(p+i-1));
}
//ȡL�ĵ�i������Ԫ�ظ�ֵ��e
Status GetElem(Sq L,int i,ElemType *e)
{
	if(i<1||i>L.length)
		exit(ERROR);
	else
		*e=*(L.elem+i-1);
	return OK;
}
//��˳���L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
int LocateElem(Sq L,ElemType e,Status (*compare)(ElemType,ElemType))
{
    //���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
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
//ʵ��A=AUB
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
			Insert(La,++La_len,e);//La�в����ں�e��ͬ������Ԫ�أ������֮
	}
}

//������
int main()
{
    Sq La,Lb;
	Status i;
	int j,k;
	int La_len,Lb_len;
	i=Init(&La);
	Init(&Lb);
	if(i==1)//����˳���ɹ�
		//����Ԫ�أ�����Ϊ0��ʾ��ֹ����
		printf("������La��Ԫ�أ�����0��ʾ��ֹ���룩��\n");
	//����La��Ԫ��
	for(j=1,k=1;j!=0;k++)
	{
		scanf("%d",&j);
		if(j!=0)
			i=Insert(&La,k,j);
	}
	printf("������Lb��Ԫ�أ�����0��ֹ���룩��\n");
	for(j=1,k=1;j!=0;k++)
	{
	    scanf("%d",&j);
		if(j!=0)
			i=Insert(&Lb,k,j);
	}
	La_len=Listlength(La);
	Lb_len=Listlength(Lb);
	//���La��Lb��Ԫ��
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