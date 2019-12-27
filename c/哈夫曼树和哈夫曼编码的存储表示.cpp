// 哈夫曼树和哈夫曼树编码的存储表示
typedef struct 
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;	// 动态分配数组存储哈夫曼树

typedef char **HuffmanCode;	// 动态分配数组哈夫曼树编码表

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
// w存放n个字符的权值（均 > 0），构造哈夫曼树HT，并求出n个字符的哈夫曼编码HC
{
	if (n <= 1)
		return;
	m = 2 * n - 1;	// n个叶子结点有2n-1个结点
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));	// 0号单元未用
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w)
		*p = { *w, 0, 0, 0 };	// 给每个哈夫曼叶子结点赋初值
	for (; i <= m; ++i, ++p)
		*p = { 0, 0, 0, 0 };	// 给剩余结点赋初值
	for (i = n + 1; i < m; ++i)
	// 建哈夫曼树
	{
		Select(HT, i - 1, s1, s2);	// 在HT[1..i-1]选择parant为0且weight最小的两个结点，其序号分别为s1,s2;
		HT[s1].parant = i; HT[s2].parant = i;
		HT[i].lchild = s1; HT[i].rchilde = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	// 从叶子到根逆向求每个字符的哈夫曼编码
	HC = (HuffmanCode)malloc((n + 1) * sizeof(char *)); // 分配n个字符编码的头指针向量
	cd = (char *)malloc(n * sizeof(char));	// 分配求编码的工作空间
	cd[n - 1] = "\0";	// 编码结束符
	for (i = 1; i <= n; ++i)	// 逐个字符求哈夫曼编码
	{
		start = n - 1;	// 编码结束符位置
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)	// 从叶子到根逆向求编码
			if (HT(f).lchild == c)
				cd[--start] = "0";
			else
				cd[--start] = "1";
		HC[i] = (char *)malloc((n - start) * sizeof(char));	// 为第i个字符编码分配空间
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}

// 无栈非递归遍历哈夫曼树，求哈夫曼树编码
HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
p = m; cdlen = 0;
for (i = 1; i <= m; ++i)
	HT[i].weight = 0; // 遍历哈夫曼树时用作结点状态标志
while (p)
{
	if (HT[p].weight == 0)	// 向左
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
	else if (HT[p].weight == 1)	// 向右
	{
		HT[p].weight = 2;
		if (HT[p].rchild != 0)
		{
			p = HT[p].rchild;
			cd[cdlen++] = "1";
		}
	}
	else  // HT[p].weight == 2,退回
	{
		HT[p].weight = 0;
		p = HT[p].parent;
		--cdlen;
	}
}