// BFS
bool visited[VERTEX_MAX_NUM];
void BFSTraverse(Graph G){
    for(v = 0; v < G.vexnum; ++v)
        visited[v] = FALSE;
    InitQueue(Q);
    for(v = 0; v < G.vexnum; ++v)
        if(!visited[v])
            BFS(G,v);
}

void BFS(Graph G, int v){
    visit(v);
    visited[v] = TRUE;
    EnQueue(Q,v);
    while(!empty(Q)){
        DeQueue(Q,v);
        for(w = FirstNeighbor(G,v); w >= 0; w = NextNeighbor(G,v,w)){
            if(!visited[w]){
                visit(w);
                visited[w] = TRUE;
                EnQueue(Q,w);
            }
        }
    }
}
