// ϰ��2.12
// �Ƚ���˳����С

int cmp_sql(SqList A, SqList B)
// A>B ����1��A=B ����0��A<B ����-1
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