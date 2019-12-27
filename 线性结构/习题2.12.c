// 习题2.12
// 比较两顺序表大小

int cmp_sql(SqList A, SqList B)
// A>B 返回1，A=B 返回0，A<B 返回-1
{
	for (int i = 0; i < min(A.length, B.length); ++i)
	{
		if (A.elem[i] > B.elem[i])
			return 1;
		if (A.elem[i] < B.elem[i])
			return -1;
	}
	if (i < A.length)
		return 1;
	if (i < B.length)
		return -1;
	if (A.length == B.length)
		return 0;
}