// 习题2.13

int LOCATE(LinkList L, ElemType X)
// 定位X在L中的位置
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