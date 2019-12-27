// DFS非递归算法,采用临接表
void DFS_Non_RC(AGrapht &G, int v){
    int w;
    InitStack(s);
    for(i = 0; i < G.vexnum; ++i){
        visited[i] = FALSE;
    }
    Push(s,v);visted[v] = TRUE; // 已经进入过栈的顶点不能再次进栈
    while(!empty(S)){
        k = Pop(S);
        visit(k);
        // 每次从邻接点选一个顶点进行访问
        for(w = FirstNeighbor(G,k); w >= 0; w = NextNeighbor(G,k,w)){
            if(!visited[w]){
                Push(S,w);
                visited[w] = TRUE;
            }
        }
    }
}
