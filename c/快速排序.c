// ��������

// һ�˿��������㷨
int Partition(SqList &L, int low, int high)
// ����˳���L���ӱ�L.r[low..high]�ļ�¼��ʹ�����¼��λ��������������λ�ã���ʱ
// ����֮ǰ���󣩵ļ�¼������С������
{
	L.r[0] = L.r[low];	//	���ӱ�ĵ�һ����¼�������¼
	pivotkey = L.r[low].key;	// �����¼�ؼ���
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[row].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];	// �����¼��λ
	return low;
}


// �ݹ���ʽ��������
void QSort(SqList &L, int low, int high)
// ��˳���L�е�������L.r[low..high]����������
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