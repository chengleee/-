// 链表习题9
// 算法思想：
// 先用直接插入法将链表重新排序，然后按次序输出数据并删除

void sortprintanddel(Linklist &L) {
	LNode *pre, *p = head->next, *r = p->next; // pre指向前一结点，p指向当前结点，r暂存后继结点
	p->next = NULL; // 链表中只保留一个结点
	p = r;
	while (p) {
		pre = head;
		r = r->next;
		while (pre->next && pre->next->date < p->date) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	p = head->next;
	r = p->next;
	while (p) {
		print(p->date);
		free(p);
		p = r;
		r = r->next;
	}
	free(head);
}