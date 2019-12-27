// 建立无向图G的深度优先生成森林
void DFSForeast(Graph G, CSTree &T)
{
	T = NULL;	
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = FALSE;
	for (v = 0; v < G.vexnum; ++v)
		if(!visited[v])
		{
			p = (CSTree)malloc(sizeof(CSNode));	// 第v顶点为新的生成树的根结点
			*p = { GetVex(G, v), NULL, NULL };	// 分配根结点
			if (!T)	// 是第一棵生成树的根（T的根）
				T = p;
			else // 是其他生成树的根
				q->nextsibling = p;
			q = p;	// q指示当前生成树的根
			DFSTree(G, v, p);	// 建立以p为根的生成树
		}
}

void DFSTree(Graph G, int v, CSTree &T)
{
	visited[v] = TRUE; first = TRUE;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode));	// 分配孩子结点
			*p = { GetVex(G, w), NULL, NUll };	
			if (first)	// w是v的第一个未被访问的邻接顶点
			{
				T->lchild = p; first = FALSE; // 是根的左孩子结点
			}
			else
			{
				q->nextsibling = p;	// 是上一邻接顶点的右兄弟结点
			}
			q = p;
			DFSTree(G, w, q);	// 从第w个顶点出发深度优先遍历图G,建立子生成树q
		}
	}
}