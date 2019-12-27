#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

//线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LISTINCREMENT    // 线性表存储空间的分配增量
typedef struct
{
	ElemType *elem;  // 存储空间基址
	int length;  // 当前长度
	int listsize;    // 当前分配的存储容量
}SqList;

//  构造空的线性表
Status InitList_Sq(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);  //分配失败
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListLength_Sq(SqList L)
{
	return L.length;
}

// 在顺序线性表L中第i个位置之前插入新的元素e
// i 的合法值为 1 <= i <= ListLength_Sq(L) + 1
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > ListLength_Sq(L) + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ELemType));
		if (!newbase)
			exit(OVERFLOW);	// 存储失败
		L.elem = newbase;	// 新基址	
		L.listsize += LISTINCREMENT;	// 增加存储容量
	}
	q = &(L.elem[i - 1];	// q为插入位置
	for (p = &(L.elem[L.length - 1]); p >= 1; --p)
		*(p + 1) = *p;	// 插入位置及之后的元素右移
	*q = e;	// 插入e
	++L.length;	// 表长增1
	return OK;
}

// 在顺序线性表中删除第i个元素，并用e返回其值
Status ListDelete_Sq(SqList &L, int i, ElemType e&)
{
	if ((i < 1) || (i >= L.length))
		return ERROR;
	p = &(L.elem[i - 1]);	// p为被删除的位置
	e = *p;	// 被删除的元素赋给e
	q = L.elem + L.length - 1;	// 表尾元素的位置
	for (++p; p <= q; ++p)	// 被删除元素之后的元素左移
		*(p - 1) = *p;
	--L.length;	// 表长减1
	return OK;
}

Status equal(ElemType a, ElemType b)
{
	if (a == b)
		return TRUE;
	else
		return FALSE;
}

// 在顺序线性表中查找第1个值与e满足compare()的元素的位序
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 1;	// i的初值为第1个元素的位序
	ElemType *p = L.elem;	// p的初值为第1个元素的存储位置
	while (i <= L.length && !(*compare)(*p++, e))
		++i;
	if (i < L.length)
		return i;
	else
		return 0;
}

// 已知顺序线性表La和Lb的元素按值非递减排列，合并得到新的非递减Lc表
void MergeList_Sq(SqList La, SqList Lb, SqList Lc)
{
	ElemType *pa, *pb, *pc;
	pa = La.elem;
	pb = La.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);
	ElemType *pa_last = La.elem + La.length - 1;
	ElemType *pb_last = Lb.elem + Lb.length - 1;
	// 归并
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;
}