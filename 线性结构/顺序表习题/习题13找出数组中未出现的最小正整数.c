/*
算法思想：
用一个数组B来记录A中是否出现了1-n的整数，只需查询B中第一个未被标记的下标+1，即为解
*/

int findMissMin(int A[], int n) {
	int i, *B;
	B = (int *)malloc(sizeof(int) * n);
	memset(B, 0, sizeof(int) * n); // 给B赋初值0
	for (i = 0; i < n; ++i) 
		if (A[i] > 0 && A[i] <= n)
			B[A[i] - 1] = 1;
	for (i = 0; i < n; i++)
		if (B[i] == 0)
			break;
	return i + 1;
			
}