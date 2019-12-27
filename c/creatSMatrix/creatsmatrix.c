status creatsmatrix_OL(CrossList *M)
	//创建稀疏矩阵，采用十字链表存储表示
{
	if(M)
	{
		free(M);
		M=NULL;
	}
	scanf("%d,%d,%d",&M->mu,&M->nu,&M->tu);
	if(!(M->rhead=(OLink *)malloc((M->mu+1)*sizeof(OLink))))
		exit(OVERFLOW);	
	if(!(M->chead=(OLink *)malloc((M->mu+1)*sizeof(OLink))))
		exit(OVERFLOW);
	M->rhead[]=M->chead[]=NULL;		//初始化行列头指针向量
	for(scanf(&i,&j,&e);i!=0;scanf(&i,&j,&e))
	{
		if(!(p=(OLNode *)malloc(sizeof(OLNode))))
		{
			p->i=i;
			p->j=j;
			p->e=e;
		}
		if(M->rhead[i]==NULL||M->rhead[i]->j>j)				//始终保持第一个结点为头结点
		{
			p->right=M->right;
			M->right=p;
		}
		else
		{
			for(q=M->rhead[i];(q->right)&&q->right->j<j;q=q->right);	//寻查在行表中的位置
			p->right=q->right;
			q->right=p;
		}
		if(M->chead[j]==NULL||M->chead[j]->i>i)
		{
			p->down=M->chead[j];
			M->chead[j]=p;
		}
		else
		{
			for(q=M->chead[j];(q->down)&&q->down->i<i;q=q->down);		//寻查在列表中的位置
			p->down=q->down;
			q->down=p;
		}
	}
}
