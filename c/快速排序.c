// 快速排序

// 一趟快速排序算法
int Partition(SqList &L, int low, int high)
// 交换顺序表L中子表L.r[low..high]的记录，使枢轴记录到位，并返回其所在位置，此时
// 在它之前（后）的记录均不大（小）于它
{
	L.r[0] = L.r[low];	//	用子表的第一个记录作枢轴记录
	pivotkey = L.r[low].key;	// 枢轴记录关键字
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[row].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];	// 枢轴记录到位
	return low;
}


// 递归形式快速排序
void QSort(SqList &L, int low, int high)
// 对顺序表L中的子序列L.r[low..high]作快速排序
{
	if (low < high)
	{
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

void QuickSort(SqList &L)
{
	QSort(L, 1, L.length);
}