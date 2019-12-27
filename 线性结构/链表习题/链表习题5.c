// 链表习题5
// 将带头结点的单链表就地逆置
// 算法思想1：使用头插法

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

// 算法思想2：
// 令每一个结点的next都指向前趋结点,第一个结点next指向NULL

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