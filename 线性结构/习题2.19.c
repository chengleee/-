// ϰ��2.19

Status delete_range(LinkList &L)
// ɾ��������С��maxk���Ҵ���mink��Ԫ��
// ����Ԫ�ص�������
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