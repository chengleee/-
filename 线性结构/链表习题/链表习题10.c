// ����ϰ��10
// ����ͷ��������L��Ϊ2������A��B��A�д洢L�����Ϊ�����Ľ�㣬B�д洢���Ϊż���Ľ�㡣
// �㷨˼�룺
// ����L��㣬�������A��B��

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