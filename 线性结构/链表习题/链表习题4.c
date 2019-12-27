// 链表习题4
// 删除带头结点单链表L中值最小的结点（假设最小结点唯一）

// 算法思想：
// 1、查找值最小的结点及其前趋结点
// 2、删除该结点

void del_minvalue(Linklist &L) {
	if (L->next == NULL)
		return;
	Elemtype min = L->next->date; // 默认第一个结点值为最小值
	LNode *p, *minnode;
	p = L->next;
	pre = L;
	while (p) {	// 寻找最小值的结点
		if (p->date < min) {
			min = p->date;
			minnode = p;
			p = p->next;
		}
	}
	if (minnod->next == NULL) {
		free(minnode);
		minnode = NULL;
	}
	else {
		// 删除最小结点的后继结点，并将后继结点的值赋予最小结点
		p = minnode->next;
		minnode->next = p->next;
		minnode->date = p->date;
		free(p);
	}
}