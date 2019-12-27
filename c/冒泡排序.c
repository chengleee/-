// 冒泡排序

void bubble_sort(int a[], int n)
// 将a中整数序列重新排列成自小至大有序的整数序列
{
	for (i = n - 1, change = TRUE; i >= 2 && change; --i)
	{
		change = FALSE;
		for (j = 0; j < i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
				change = TRUE;
			}
		}
	}
}