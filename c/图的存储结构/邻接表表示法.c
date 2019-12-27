    /* ͼ���ڽӱ��ʾ����C����ʵ�֣� */
    #define  MaxVertexNum  100     /* ��󶥵���Ϊ100 */
    enum GraphType { DG, UG, DN, UN }; 
    /* ����ͼ,����ͼ,������ͼ,������ͼ*/
    typedef  struct  node{   /* �߱��� */
        int AdjV;            /* �ڽӵ��� */
        struct  node  *Next;  /* ָ����һ���ڽӵ��ָ���� */
        /* ��Ҫ��ʾ���ϵ�Ȩֵ��Ϣ����Ӧ����һ��������Weight */
    } EdgeNode;
    typedef  char  VertexType;   /* �������ַ���ʾ */
    typedef  struct  Vnode{      /* ������� */
        VertexType  Vertex;      /* ������ */
        EdgeNode  *FirstEdge; /* �߱�ͷָ�� */
    } VertexNode; 
    typedef VertexNode AdjList[ MaxVertexNum ]; /* AdjList���ڽӱ����� */
    typedef  struct{  
        AdjList  adjlist;    /* �ڽӱ� */
        int  n, e;               /* �������ͱ��� */
        enum GraphType GType;    /* ͼ�����ͷ�4�֣�UG��DG��UN��DN */
    } ALGraph;  /*ALGraph�����ڽӱ�ʽ�洢��ͼ���� */
      
    void CreateALGraph( ALGraph *G )
    {
        int i, j, k;
        EdgeNode *edge;
        G-> GType = DG;  /* Directed Graph  ����ͼ  */
        printf( "�����붥�����ͱ���(�����ʽΪ:������,����)��\n" );
        scanf( "%d,%d", &(G->n), &(G->e) ); /* ���붥�����ͱ��� */ 
        printf( "�����붥����Ϣ(�����ʽΪ:�����<CR>)��\n" );
        for ( i=0; i < G->n; i++ ) {   /* ������n������Ķ���� */
            scanf( " %c", &(G->adjlist[i].Vertex) );  /* ���붥����Ϣ */
           G->adjlist[i].FirstEdge = NULL; /* ����ı߱�ͷָ����Ϊ�� */
        }
        printf( "������ߵ���Ϣ(�����ʽΪ: i, j <CR>)��\n" );
        for ( k=0; k < G->e; k++ ){   /* �����߱� */
           scanf( "\n%d,%d", &i, &j); /* �����<vi,vj>�Ķ����Ӧ���*/
           edge = (EdgeNode*)malloc(sizeof(EdgeNode)); /* �����±߽��edge */
           edge->AdjV = j; /* �ڽӵ����Ϊj */
           edge->Next = G->adjlist[i].FirstEdge;
           /* ���±߱���edge���뵽����vi�ı߱�ͷ�� */
           G->adjlist[i].FirstEdge = edge;
           /* ��������ͼ����Ҫ����һ����㣬������ʾ��< vj, vi>  */
        }
    }