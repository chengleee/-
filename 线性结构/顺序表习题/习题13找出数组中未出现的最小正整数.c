/*
�㷨˼�룺
��һ������B����¼A���Ƿ������1-n��������ֻ���ѯB�е�һ��δ����ǵ��±�+1����Ϊ��
*/

int findMissMin(int A[], int n) {
	int i, *B;
	B = (int *)malloc(sizeof(int) * n);
	memset(B, 0, sizeof(int) * n); // ��B����ֵ0
	for (i = 0; i < n; ++i) 
		if (A[i] > 0 && A[i] <= n)
			B[A[i] - 1] = 1;
	for (i = 0; i < n; i++)
		if (B[i] == 0)
			break;
	return i + 1;
			
}