// 链表习题10
// 将带头结点的链表L分为2个链表A、B，A中存储L中序号为奇数的结点，B中存储序号为偶数的结点。
// 算法思想：
// 遍历L结点，交替插入A、B中

void discreat(Linklist L, Linklist &A, Linklist &B) {
	LNode *p,*q,*Arear = A, *Brear = B;
	int n = 1;
	A->next = NULL;
	B->next = NULL;
	p = L->next;
	while (p) {
		q = p->next
		if (n % 2 == 1) {
			p->next = Arear->next;
			Arear->next = p;
			Arear = p;
			p = q;
			n++;
		}
		else {
			p->next = Brear->next;
			Brear->next = p;
			Brear = p;
			p = q;
			n++;
		}
	}
}