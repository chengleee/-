// ����ϰ��3
// ��β��ͷ�����ͷ���ĵ�����L��ֵ
// �㷨˼�룺�ݹ飬��������ջ�Ƚ������˼��
int print_inverse(Linklist L) {
	if (L->next != NULL) {
		print_inverse(L->next->date);
	}
	print(L->date);
}