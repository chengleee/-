// ����ϰ��9
// �㷨˼�룺
// ����ֱ�Ӳ��뷨��������������Ȼ�󰴴���������ݲ�ɾ��

void sortprintanddel(Linklist &L) {
	LNode *pre, *p = head->next, *r = p->next; // preָ��ǰһ��㣬pָ��ǰ��㣬r�ݴ��̽��
	p->next = NULL; // ������ֻ����һ�����
	p = r;
	while (p) {
		pre = head;
		r = r->next;
		while (pre->next && pre->next->date < p->date) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	p = head->next;
	r = p->next;
	while (p) {
		print(p->date);
		free(p);
		p = r;
		r = r->next;
	}
	free(head);
}