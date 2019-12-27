// prim算法
void MiniSpanTree_PRIM(MGraph G, VertexType u)
// 用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边
// 记录从顶点集U到V-U的代价最小的边的辅助数组定义：
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
		k = minimum(closedge);	// 求出T的下一个结点：第k个结点
		printf(closedge[k].adjvex, G.vexs[k]);	// 输出生成树的边
		closedge[k].lowcost = 0;	// 第k顶点并入U集
		for (j = 0; j < G.vexnum; ++j)
			if (G.arcs[k][j].adj < closedge[j].lowcost)	// 新顶点并入U后重新选择最小边
				closedge[j] = { G.vexs[k], G.arcs[k][j].adj };
	}
}