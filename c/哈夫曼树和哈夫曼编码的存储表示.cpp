// ���������͹�����������Ĵ洢��ʾ
typedef struct 
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;	// ��̬��������洢��������

typedef char **HuffmanCode;	// ��̬��������������������

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
// w���n���ַ���Ȩֵ���� > 0���������������HT�������n���ַ��Ĺ���������HC
{
	if (n <= 1)
		return;
	m = 2 * n - 1;	// n��Ҷ�ӽ����2n-1�����
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));	// 0�ŵ�Ԫδ��
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w)
		*p = { *w, 0, 0, 0 };	// ��ÿ��������Ҷ�ӽ�㸳��ֵ
	for (; i <= m; ++i, ++p)
		*p = { 0, 0, 0, 0 };	// ��ʣ���㸳��ֵ
	for (i = n + 1; i < m; ++i)
	// ����������
	{
		Select(HT, i - 1, s1, s2);	// ��HT[1..i-1]ѡ��parantΪ0��weight��С��������㣬����ŷֱ�Ϊs1,s2;
		HT[s1].parant = i; HT[s2].parant = i;
		HT[i].lchild = s1; HT[i].rchilde = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	// ��Ҷ�ӵ���������ÿ���ַ��Ĺ���������
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *)); // ����n���ַ������ͷָ������
	cd = (char *)malloc(n * sizeof(char));	// ���������Ĺ����ռ�
	cd[n - 1] = "\0";	// ���������
	for (i = 1; i <= n; ++i)	// ����ַ������������
	{
		start = n - 1;	// ���������λ��
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)	// ��Ҷ�ӵ������������
			if (HT(f).lchild == c)
				cd[--start] = "0";
			else
				cd[--start] = "1";
		HC[i] = (char *)malloc((n - start) * sizeof(char));	// Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}

// ��ջ�ǵݹ���������������������������
HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
p = m; cdlen = 0;
for (i = 1; i <= m; ++i)
	HT[i].weight = 0; // ������������ʱ�������״̬��־
while (p)
{
	if (HT[p].weight == 0)	// ����
	{
		HT[p].weight = 1;
		if (HT[p].lchild != 0)
		{
			p = HT[p].lchild;
			cd[cdlen++] = "0";
		}
		else if (HT[p].rchild == 0)
		{
			HC[p] = (char *)malloc(cdlen + 1) * sizeof(char));
			cd[cdlen] = "\0"; strcpy(HC[p], cd);
		}
	}
	else if (HT[p].weight == 1)	// ����
	{
		HT[p].weight = 2;
		if (HT[p].rchild != 0)
		{
			p = HT[p].rchild;
			cd[cdlen++] = "1";
		}
	}
	else  // HT[p].weight == 2,�˻�
	{
		HT[p].weight = 0;
		p = HT[p].parent;
		--cdlen;
	}
}