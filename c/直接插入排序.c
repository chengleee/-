// ֱ�Ӳ�������
void InsertSort(Sqlist &L)
{
	for (i = 2; i <= L.length; ++i)
	{
		if (LT(L.r[i].key, L.r[i - 1].key))
		{
			L.r[0] = L.r[i];	// ����Ϊ�ڱ�
			L.r[i] = L.r[i - 1];
			for (j = i - 2; LT(L.r[0].key, L.r[j].key); --j)
			{
				L.r[j + 1] = L.r[j];	// ��¼����
			}
			L.r[j + 1] = L.r[0];	// ���뵽��ȷλ��
		}
	}
}
