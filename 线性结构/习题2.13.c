// ϰ��2.13

int LOCATE(LinkList L, ElemType X)
// ��λX��L�е�λ��
{
	int i = 1;
	LiinkList p = L->next;
	while (p)
	{
		if (p->data == X)
			return i;
		p = p->next;
		++i;
	}
	return 0;
}