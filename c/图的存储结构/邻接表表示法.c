    /* 图的邻接表表示法（C语言实现） */
    #define  MaxVertexNum  100     /* 最大顶点数为100 */
    enum GraphType { DG, UG, DN, UN }; 
    /* 有向图,无向图,有向网图,无向网图*/
    typedef  struct  node{   /* 边表结点 */
        int AdjV;            /* 邻接点域 */
        struct  node  *Next;  /* 指向下一个邻接点的指针域 */
        /* 若要表示边上的权值信息，则应增加一个数据域Weight */
    } EdgeNode;
    typedef  char  VertexType;   /* 顶点用字符表示 */
    typedef  struct  Vnode{      /* 顶点表结点 */
        VertexType  Vertex;      /* 顶点域 */
        EdgeNode  *FirstEdge; /* 边表头指针 */
    } VertexNode; 
    typedef VertexNode AdjList[ MaxVertexNum ]; /* AdjList是邻接表类型 */
    typedef  struct{  
        AdjList  adjlist;    /* 邻接表 */
        int  n, e;               /* 顶点数和边数 */
        enum GraphType GType;    /* 图的类型分4种：UG、DG、UN、DN */
    } ALGraph;  /*ALGraph是以邻接表方式存储的图类型 */
      
    void CreateALGraph( ALGraph *G )
    {
        int i, j, k;
        EdgeNode *edge;
        G-> GType = DG;  /* Directed Graph  有向图  */
        printf( "请输入顶点数和边数(输入格式为:顶点数,边数)：\n" );
        scanf( "%d,%d", &(G->n), &(G->e) ); /* 读入顶点数和边数 */ 
        printf( "请输入顶点信息(输入格式为:顶点号<CR>)：\n" );
        for ( i=0; i < G->n; i++ ) {   /* 建立有n个顶点的顶点表 */
            scanf( " %c", &(G->adjlist[i].Vertex) );  /* 读入顶点信息 */
           G->adjlist[i].FirstEdge = NULL; /* 顶点的边表头指针设为空 */
        }
        printf( "请输入边的信息(输入格式为: i, j <CR>)：\n" );
        for ( k=0; k < G->e; k++ ){   /* 建立边表 */
           scanf( "\n%d,%d", &i, &j); /* 读入边<vi,vj>的顶点对应序号*/
           edge = (EdgeNode*)malloc(sizeof(EdgeNode)); /* 生成新边结点edge */
           edge->AdjV = j; /* 邻接点序号为j */
           edge->Next = G->adjlist[i].FirstEdge;
           /* 将新边表结点edge插入到顶点vi的边表头部 */
           G->adjlist[i].FirstEdge = edge;
           /* 若是无向图，还要生成一个结点，用来表示边< vj, vi>  */
        }
    }