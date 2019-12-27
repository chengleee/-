// ��������ͼG�������������ɭ��
void DFSForeast(Graph G, CSTree &T)
{
	T = NULL;	
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = FALSE;
	for (v = 0; v < G.vexnum; ++v)
		if(!visited[v])
		{
			p = (CSTree)malloc(sizeof(CSNode));	// ��v����Ϊ�µ��������ĸ����
			*p = { GetVex(G, v), NULL, NULL };	// ��������
			if (!T)	// �ǵ�һ���������ĸ���T�ĸ���
				T = p;
			else // �������������ĸ�
				q->nextsibling = p;
			q = p;	// qָʾ��ǰ�������ĸ�
			DFSTree(G, v, p);	// ������pΪ����������
		}
}

void DFSTree(Graph G, int v, CSTree &T)
{
	visited[v] = TRUE; first = TRUE;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode));	// ���亢�ӽ��
			*p = { GetVex(G, w), NULL, NUll };	
			if (first)	// w��v�ĵ�һ��δ�����ʵ��ڽӶ���
			{
				T->lchild = p; first = FALSE; // �Ǹ������ӽ��
			}
			else
			{
				q->nextsibling = p;	// ����һ�ڽӶ�������ֵܽ��
			}
			q = p;
			DFSTree(G, w, q);	// �ӵ�w���������������ȱ���ͼG,������������q
		}
	}
}