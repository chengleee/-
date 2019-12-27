// 链表习题1
// 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点

// 算法思想：
// 若L为空表，结束
// 若L->date == x, 删除L，Del（L->next, x);
// 若L->date != x,Del（L->next, x);

void Del_x(Linklist &L, Elemtype x) {
	// 由于L用的是引用，应理解为上一步的L->next，所以不会出现断链
	if (L == NULL)
		return;
	if (L->date == x) {
		LNode *p = L;
		L = L->next;
		free(p);
		Del_x(L, x);
	}
	else
		Del(L - next, x);
}