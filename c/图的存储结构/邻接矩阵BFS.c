/* 邻接矩阵存储的图 – BFS（C语言实现） */
void  BFS ( MGraph G )
{   /* 按广度优先遍历图G。使用辅助队列Q和访问标志数组Visited */
    Queue  *Q;    
    VertexType  U, V, W;
    for ( U = 0; U < G.n; ++U )  
       Visited[U] = FALSE;
    Q = CreatQueue( MaxSize ); /* 创建空队列Q */
    for ( U = 0; U<G.n; ++U )
       if ( !Visited[U] ) { /* 若U尚未访问 */
           Visited[U] = TRUE; 
           printf( "visit vertex: %c\n", G.Vertices[U] );
           /* 相当于访问顶点U */
           AddQ (Q, U);    /* U入队列 */
           while ( ! IsEmptyQ(Q) ) {
              V = DeleteQ( Q );  /*  队头元素出队并置为V */
              for( W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W) )
                  if ( !Visited[W] ) {
                     Visited[W] = TRUE;
                     printf( "visit vertex: %c\n", G.Vertices[W] );
                     /* 相当于访问顶点W */
                     AddQ (Q, W);
                  }
           } /* while结束*/
} /* 结束从U开始的BFS */
}