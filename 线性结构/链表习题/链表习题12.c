// ����ϰ��12
// ȥ���������������е���ͬԪ��

void delsamenode(Linklist *L) {
	LNode *p = L->next, *pre = L, *q;
	while (p) {
		q = p->next
		if (p->date == pre->date) {
			pre->next = q;
			free(p);
		}
		else {
			pre = pre->next;

		}
		p = q;
	}
}