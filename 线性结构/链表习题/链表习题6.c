// ����ϰ��6
// ���ͷ���ĵ�����L��������
// �㷨˼�룺
// ֱ�Ӳ�������
void Sort(Linklist &L) {
	LNode *p = L->next, *pre;
	LNode *r = p->next; // r����p�ĺ�̽��
	p->next = NULL;
	p = r;
	while (p != NULL) {
		r = p->next;
		pre = L;
		// ����Ҫ�����ǰ��λ��
		while (pre->next != NULL && pre->next->date < p->date)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}