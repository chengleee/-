// 链表习题8
// 找出两个链表的公共结点
// 算法思想，公共结点必在更长链表多出来的那一段中

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
	// 遍历完长链表的前dist项
	while (dist--) {
		longlist = longlist->next;
	}
	// 长链表与短链表同步遍历剩余项，直到找到公共结点
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