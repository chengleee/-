    /* ͼ���ڽӾ����ʾ����C����ʵ�֣� */
    #define  MaxVertexNum  100      /* ��󶥵�����Ϊ100 */
    #define  INFINITY  65535     /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
    typedef  char  VertexType;      /* ����������Ϊ�ַ��� */
    typedef  int  EdgeType;         /* �ߵ�Ȩֵ��Ϊ���� */
    enum GraphType { DG, UG, DN, UN };  
    /* ����ͼ,����ͼ,������ͼ,������ͼ*/
      
    typedef  struct {
        VertexType  Vertices[ MaxVertexNum ];  /* ����� */
        EdgeType  Edges[ MaxVertexNum ][ MaxVertexNum ]; 
    /* �ڽӾ��󣬼��߱�  */
        int  n, e;   /* ������n�ͱ���e */
        enum GraphType GType;   /* ͼ�����ͷ�4�֣�UG��DG��UN��DN */
    } MGraph;    /* MGragh�����ڽӾ���洢��ͼ���� */
      
    void  CreateMGraph ( MGraph *G )
    {  
        int  i, j, k, w;
        G-> GType = UN;    /* Undirected Network  ������ͼ  */
        printf( "�����붥�����ͱ���(�����ʽΪ:������, ����):\n" );
        scanf( "%d, %d",&(G->n), &(G->e) ); /* ���붥�����ͱ��� */
        printf("�����붥����Ϣ(�����ʽΪ:�����<CR>):\n");
        for ( i = 0; i < G->n; i++ ) 
           scanf( "%c",&(G-> Vertices[i]) ); /*  ���붥����Ϣ�����������  */
        for ( i = 0; i < G->n; i++ )
           for ( j = 0; j < G->n; j++ )  
               G->Edges[i][j] = INFINITY; /* ��ʼ���ڽӾ��� */
        printf( "������ÿ���߶�Ӧ�������������ź�Ȩֵ�������ʽΪ:i, j, w:\n" );
        for ( k = 0; k < G->e; k++ ) {
           scanf("%d,%d,%d ",&i, &j, &w); /* ����e�����ϵ�Ȩ�������ڽӾ��� */
           G->Edges[i][j] = w; 
           G->Edges[j][i] = w; /* ��Ϊ������ͼ���ڽӾ����ǶԳƵ� */
        }
    }