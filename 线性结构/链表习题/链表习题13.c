// ����ϰ��13
// ��������������鲢Ϊһ���ݼ�������ʹ��ԭ����������Ŀռ�
// �㷨˼�룺
// ͷ���뷨

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