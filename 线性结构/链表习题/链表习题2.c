// ����ϰ��2
// ɾ����ͷ���ĵ�����������ֵΪx�Ľ�㣬���ͷ���ռ�
typedef struct LNode {
	Elemtype date;
	struct LNode *next;
}LNode, *Linklist;

void Del_x(Linklist &L, Elemtype x) {
	LNode *p, *pre;
	// Ѱ��ֵΪx�Ľ�㼰��ǰ�����
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
