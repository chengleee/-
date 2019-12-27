// 链表习题6
// 令带头结点的单链表L递增有序
// 算法思想：
// 直接插入排序
void Sort(Linklist &L) {
	LNode *p = L->next, *pre;
	LNode *r = p->next; // r保持p的后继结点
	p->next = NULL;
	p = r;
	while (p != NULL) {
		r = p->next;
		pre = L;
		// 查找要插入的前趋位置
		while (pre->next != NULL && pre->next->date < p->date)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}