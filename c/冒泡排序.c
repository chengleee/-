// ð������

void bubble_sort(int a[], int n)
// ��a�����������������г���С�����������������
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