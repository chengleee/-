// 链表习题17
// 判断带头结点的循环双链表是否对称

bool issymmetry(DLinklist L) {
	DLNode *p = L, *q = L->prior;
	while (p != q && p->next != q) {
		if (p->date != q->date)
			return false;
		p = p->next;
		q = q->prior;
	}
	return true;
}