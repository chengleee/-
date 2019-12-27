// 链表习题3
// 从尾到头输出带头结点的单链表L的值
// 算法思想：递归，即利用了栈先进后出的思想
int print_inverse(Linklist L) {
	if (L->next != NULL) {
		print_inverse(L->next->date);
	}
	print(L->date);
}