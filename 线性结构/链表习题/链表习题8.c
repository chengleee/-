// ����ϰ��8
// �ҳ���������Ĺ������
// �㷨˼�룬���������ڸ���������������һ����

Linklist search_common(Linklist L1, Linklist L2) {
	int dist,len1 = length(L1), len2 = length(L2);
	Linklst longlist, shortlist;
	if (len1 > len2) {
		longlist = L1->next;
		shortlist = L2->next;
		dist = len1 - len2;
	}
	else {
		longlist = L2->next;
		shortlist = L1->next;
		dist = len2 - len1;
	}
	// �����곤�����ǰdist��
	while (dist--) {
		longlist = longlist->next;
	}
	// �������������ͬ������ʣ���ֱ���ҵ��������
	while (shortlist != NULL) {
		if (longlist == shortlist) {
			return longlist;
		}
		else {
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
	}// while
	return NULL;
}