    /* �ڽӱ�洢��ͼ �C DFS��C����ʵ�֣� */
    /* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��ΪFALSE */
    void  DFS( ALGraph *G,  int i )
    {   /* ��ViΪ��������ڽӱ�洢��ͼG����DFS���� */
        EdgeNode *W;
        printf( "visit vertex: %c\n", G->adjlist[i].Vertex );
        /* �൱�ڷ��ʶ���Vi */
        Visited[i] = TRUE;   /* ���Vi�ѷ��� */
        for( W = G->adjlist[i].FirstEdge;  W;  W = W->Next ) 
           if ( !Visited[ W->AdjV ] )
               DFS( G, W->AdjV );
    }