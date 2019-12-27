Status CreatBitree(Bitree &T)
//按先序输入二叉树中结点的值，空格表示空树
//构造二叉链表表示的二叉树
{
	scanf(&ch);
	if(ch==' ')
		T=NULL;
	else
	{
		if(!T=BiTNode *)malloc(sizeof(BiTNode)))
			exit(OVERFLOW);
		T->data=ch;						//生成根结点
		CreatBitree(T->lchild);			//构造左子树
		CreatBitree(T->rchild);			//构造右子树
	}
	return OK;
}