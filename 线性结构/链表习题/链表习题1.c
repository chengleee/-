// ����ϰ��1
// ���һ���ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪx�Ľ��

// �㷨˼�룺
// ��LΪ�ձ�����
// ��L->date == x, ɾ��L��Del��L->next, x);
// ��L->date != x,Del��L->next, x);

void Del_x(Linklist &L, Elemtype x) {
	// ����L�õ������ã�Ӧ���Ϊ��һ����L->next�����Բ�����ֶ���
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