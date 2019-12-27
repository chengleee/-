// 布尔排序
void ShellInsert(SqList &L, int dk)
// 对顺序表L作一趟希尔插入排序，r[0]为暂存单元
{
	for (i = dk + 1; i <= L.length; ++i)
		if (LT(L.r[i].key, L.r[i - dk].key))
		{
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk)
				L.r[j + dk] = L.r[j];	// 记录后移,查找插入位置
			L.r[j + dk] = L.r[0];	// 插入
		}
}

void ShellSort(SqList &L, int dlta[], int t)
// 按增量序列dlta[0..t-1]对顺序表L作希尔排序
{
	for (k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);
}