// 链表习题13
// 将两个递增链表归并为一个递减链表，且使用原来两个链表的空间
// 算法思想：
// 头插入法

status merge(Linklist &A,Linklist &B) {
	LNode *p = A->next, *q = B->next, *r;
	A->next = NULL;

	while (p && q) {
		if (p->date < q->date) {
			r = p->next;
			p->next = A->next;
			A->next = p;
			p = r;
		}
		else {
			r = q->next;
			q->next = A->next;
			A->next = q;
			q = r;
		}
	}

	if (p) {
		q = p;
	}
	while (q) {
		r = q->next;
		q->next = A->next;
		A->next = q;
		q = r;
	}
	free(B);
	return 0;
}