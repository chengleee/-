    /* 邻接表存储的图 – DFS（C语言实现） */
    /* Visited[]为全局变量，已经初始化为FALSE */
    void  DFS( ALGraph *G,  int i )
    {   /* 以Vi为出发点对邻接表存储的图G进行DFS搜索 */
        EdgeNode *W;
        printf( "visit vertex: %c\n", G->adjlist[i].Vertex );
        /* 相当于访问顶点Vi */
        Visited[i] = TRUE;   /* 标记Vi已访问 */
        for( W = G->adjlist[i].FirstEdge;  W;  W = W->Next ) 
           if ( !Visited[ W->AdjV ] )
               DFS( G, W->AdjV );
    }