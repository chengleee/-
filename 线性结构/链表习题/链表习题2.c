// 链表习题2
// 删除带头结点的单链表中所有值为x的结点，并释放其空间
typedef struct LNode {
	Elemtype date;
	struct LNode *next;
}LNode, *Linklist;

void Del_x(Linklist &L, Elemtype x) {
	LNode *p, *pre;
	// 寻找值为x的结点及其前趋结点
	p = L->next;
	pre = L;
	while (p) {
		if (p->date == x) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			p = p->next;
			pre = pre->next;
		}
	}
}
