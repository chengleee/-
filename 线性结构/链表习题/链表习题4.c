// ����ϰ��4
// ɾ����ͷ��㵥����L��ֵ��С�Ľ�㣨������С���Ψһ��

// �㷨˼�룺
// 1������ֵ��С�Ľ�㼰��ǰ�����
// 2��ɾ���ý��

void del_minvalue(Linklist &L) {
	if (L->next == NULL)
		return;
	Elemtype min = L->next->date; // Ĭ�ϵ�һ�����ֵΪ��Сֵ
	LNode *p, *minnode;
	p = L->next;
	pre = L;
	while (p) {	// Ѱ����Сֵ�Ľ��
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
		// ɾ����С���ĺ�̽�㣬������̽���ֵ������С���
		p = minnode->next;
		minnode->next = p->next;
		minnode->date = p->date;
		free(p);
	}
}