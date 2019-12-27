// ����ϰ��5
// ����ͷ���ĵ�����͵�����
// �㷨˼��1��ʹ��ͷ�巨

void inverse_link(Linklist &L) {
	LNode *p,*q;
	p = L->next;
	L->next = NULL;
	while (p) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

// �㷨˼��2��
// ��ÿһ������next��ָ��ǰ�����,��һ�����nextָ��NULL

void inverse_link(Linklist &L)
{
	LNode *pre, *p, *r;
	p = L->next;
	r = p->next;
	p->next = NULL;
	while (r) {
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	L->next = p;
}