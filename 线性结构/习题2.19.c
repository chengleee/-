// 习题2.19

Status delete_range(LinkList &L)
// 删除链表中小于maxk并且大于mink的元素
// 链表元素递增排序
{
	LinkList p, q, pre = NULL;
	p = L;
	pre = p;
	p = p->next;
	while (p && p->data < maxk)
	{
		if (p->data > mink)
		{
			q = p;
			pre->next = p->next;
			free(q);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return OK;
}