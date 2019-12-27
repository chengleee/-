/* �ڽӾ���洢��ͼ �C BFS��C����ʵ�֣� */
void  BFS ( MGraph G )
{   /* ��������ȱ���ͼG��ʹ�ø�������Q�ͷ��ʱ�־����Visited */
    Queue  *Q;    
    VertexType  U, V, W;
    for ( U = 0; U < G.n; ++U )  
       Visited[U] = FALSE;
    Q = CreatQueue( MaxSize ); /* �����ն���Q */
    for ( U = 0; U<G.n; ++U )
       if ( !Visited[U] ) { /* ��U��δ���� */
           Visited[U] = TRUE; 
           printf( "visit vertex: %c\n", G.Vertices[U] );
           /* �൱�ڷ��ʶ���U */
           AddQ (Q, U);    /* U����� */
           while ( ! IsEmptyQ(Q) ) {
              V = DeleteQ( Q );  /*  ��ͷԪ�س��Ӳ���ΪV */
              for( W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W) )
                  if ( !Visited[W] ) {
                     Visited[W] = TRUE;
                     printf( "visit vertex: %c\n", G.Vertices[W] );
                     /* �൱�ڷ��ʶ���W */
                     AddQ (Q, W);
                  }
           } /* while����*/
} /* ������U��ʼ��BFS */
}