// 链表习题12
// 去除递增有序链表中的相同元素

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