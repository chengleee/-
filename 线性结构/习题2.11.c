Status add_elem(ElemType x, SqList *L)
// ��x����ǵݼ�����L�У�ʹ��������Ȼ�ǵݼ�
{
	if (L->length + 1 > L->listsize)
	{
		(*L).elem = (ElemType *)realloc((*L).elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		(*L).listsize += LISTINCREMENT;
	}
	int i = L->length - 1;
	for (; i >= 0 && x < L->elem[i]; i--)
	{
		(*L).elem[i + 1] = L->elem[i];
	}
	(*L).elem[i + 1] = x;
	(*L).length++;
	return 1;
}
