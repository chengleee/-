#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

//���Ա�Ķ�̬����˳��洢�ṹ
#define LIST_INIT_SIZE 100  // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT    // ���Ա�洢�ռ�ķ�������
typedef struct
{
	ElemType *elem;  // �洢�ռ��ַ
	int length;  // ��ǰ����
	int listsize;    // ��ǰ����Ĵ洢����
}SqList;

//  ����յ����Ա�
Status InitList_Sq(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);  //����ʧ��
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int ListLength_Sq(SqList L)
{
	return L.length;
}

// ��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
// i �ĺϷ�ֵΪ 1 <= i <= ListLength_Sq(L) + 1
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > ListLength_Sq(L) + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		ElemType *newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ELemType));
		if (!newbase)
			exit(OVERFLOW);	// �洢ʧ��
		L.elem = newbase;	// �»�ַ	
		L.listsize += LISTINCREMENT;	// ���Ӵ洢����
	}
	q = &(L.elem[i - 1];	// qΪ����λ��
	for (p = &(L.elem[L.length - 1]); p >= 1; --p)
		*(p + 1) = *p;	// ����λ�ü�֮���Ԫ������
	*q = e;	// ����e
	++L.length;	// ����1
	return OK;
}

// ��˳�����Ա���ɾ����i��Ԫ�أ�����e������ֵ
Status ListDelete_Sq(SqList &L, int i, ElemType e&)
{
	if ((i < 1) || (i >= L.length))
		return ERROR;
	p = &(L.elem[i - 1]);	// pΪ��ɾ����λ��
	e = *p;	// ��ɾ����Ԫ�ظ���e
	q = L.elem + L.length - 1;	// ��βԪ�ص�λ��
	for (++p; p <= q; ++p)	// ��ɾ��Ԫ��֮���Ԫ������
		*(p - 1) = *p;
	--L.length;	// ����1
	return OK;
}

Status equal(ElemType a, ElemType b)
{
	if (a == b)
		return TRUE;
	else
		return FALSE;
}

// ��˳�����Ա��в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i = 1;	// i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	ElemType *p = L.elem;	// p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
	while (i <= L.length && !(*compare)(*p++, e))
		++i;
	if (i < L.length)
		return i;
	else
		return 0;
}

// ��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����У��ϲ��õ��µķǵݼ�Lc��
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
	// �鲢
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