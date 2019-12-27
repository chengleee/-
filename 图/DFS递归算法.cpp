bool visited[MAX_VERTEX_NUM]; // 记录每个顶点的访问情况
void DFSTraverse(Graph G){
    for(v = 0; v < G.vexnum; ++v)
        visited[v] = FALSE; // 初始化数组
    for(v = 0; v < G.vexnum; ++v)
        if(!visited[v])
            DFS(G,v);
}

void DFS(Graph G, int v){
    visit(v);
    visited(v) = TRUE;
    for(w = FirstNeighbor(G,v); w >= 0; w = NextNeighbor(G,v,w)){
        // 从v的邻接点中选择一个开始DFS
        if(!visited[w])
            DFS(G,w);
    }
}
