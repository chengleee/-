// 链表习题14
// 从递增有序的两个链表中的公共元素产生新链表，不破坏原有链表

Linklist get_common(Linklist La, Linklist Lb) {
	LNode *rear, *pa = La->next, *pb = Lb->next, *temp;
	Linklist Lc = (linklist)malloc(sizeof(LNode));
	rear = Lc;
	while (pa && pb) {
		if (pa->date < pb->date) {
			pa = pa->next;
		}
		else if (pa->date > pb->date) {
			pb = pb->next;
		}
		else {
			temp = (LNode *)malloc(sizeof(LNode));
			temp->date = pa->date;
			rear->next = temp;
			rear = temp;
			pa = pa->next;
			pb = pb->next;
		}
	}
	rear->next = NULL;
	return Lc;
}