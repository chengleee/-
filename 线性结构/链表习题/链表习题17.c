// ����ϰ��17
// �жϴ�ͷ����ѭ��˫�����Ƿ�Գ�

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