// ϰ��2.22

Status reverse(LinkList &L)
// ������͵�����
{
	LinkList p, q;
	p = L;
	p = p->next;
	L->next = NULL;
	while (p) {
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
	return OK;
}