// prim�㷨
void MiniSpanTree_PRIM(MGraph G, VertexType u)
// ������ķ�㷨�ӵ�u���������������G����С������T�����T�ĸ�����
// ��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨�壺
// struct
// {
//		VertexType adjvex;
//		VRType lowcost;
//	}closedge[MAX_VERTEX_NUM];
{
	k = LocateVex(G, u);
	for (j = 0; j < G.vexnum; ++j)
		if (j != k)
			closedge[j] = { u, G.arcs[k][j].adj };
	closedge.[k].lowcost = 0;
	for (i = 1; i < G.vexnum; ++i)
	{
		k = minimum(closedge);	// ���T����һ����㣺��k�����
		printf(closedge[k].adjvex, G.vexs[k]);	// ����������ı�
		closedge[k].lowcost = 0;	// ��k���㲢��U��
		for (j = 0; j < G.vexnum; ++j)
			if (G.arcs[k][j].adj < closedge[j].lowcost)	// �¶��㲢��U������ѡ����С��
				closedge[j] = { G.vexs[k], G.arcs[k][j].adj };
	}
}