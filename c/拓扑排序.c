// ��������
Status TopologicalSort(ALGraph G)
// ����ͼG���ڽӱ�洢�ṹ
// ��G�޻�·�������G�Ķ����һ���������в�����OK,���򷵻�ERROR
{
	FindInDegree(G, indegree);	// �Ը���������� indegree[0...vernum-1]
	InitStack(S);
	for (i = 0; i < G.vexnum; ++i)	//������ȶ���ջ
		if (!degree[i])
			Push(S, i);	//	���Ϊ0�߽�ջ
	count = 0;
	while (!StackEmpty(s))
	{
		Pop(S, i);
		printf(i, G.vertices[i].data);
		++count;
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;	// ��i�Ŷ����ÿ���ڽӵ����ȼ�1
			if (!(--indegree[k]))
				Push(S, k);	// ����ȼ�Ϊ0������ջ
		}
	}
	if (count < G.vexnum)
		return ERROR;	// ������ͼ�л�·
	else
		return OK;
}