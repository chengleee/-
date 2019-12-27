// ��������
void ShellInsert(SqList &L, int dk)
// ��˳���L��һ��ϣ����������r[0]Ϊ�ݴ浥Ԫ
{
	for (i = dk + 1; i <= L.length; ++i)
		if (LT(L.r[i].key, L.r[i - dk].key))
		{
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && LT(L.r[0].key, L.r[j].key); j -= dk)
				L.r[j + dk] = L.r[j];	// ��¼����,���Ҳ���λ��
			L.r[j + dk] = L.r[0];	// ����
		}
}

void ShellSort(SqList &L, int dlta[], int t)
// ����������dlta[0..t-1]��˳���L��ϣ������
{
	for (k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]);
}