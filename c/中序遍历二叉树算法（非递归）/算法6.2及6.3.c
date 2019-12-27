Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e))
	//中序遍历二叉树T的非递归算法，对每个数据元素调用函数Visit
{
	InitStack(S);
	Push(S,T);					//根指针入栈
	while(!StackEmpty(S))
	{
		while(GetTop(S,p)&&p)
			Push(S,p->lchild);	//向左走到尽头
		Pop(S,p);				//空指针退栈
		if(!StackEmpty(S))		//访问结点，向右走一步
		{
			Pop(S,p);
			if(!Visit(p->data))
				return ERROR;
			Push(S,p->rchild);
		}
	}
	return OK;
}

//另一中序遍历二叉树的非递归算法
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e))
{
	InitStack(S);
	p=T;
	while(p||!StackEmpty(S))
	{
		if(p)					//根指针进栈，遍历左子树
		{
			Push(S,p);
			p=p->lchild;
		}
		else					//根指针退栈，访问根结点，遍历右子树
		{
			Pop(S,p);
			if(!Visit(p->data))
				return ERROR;
			p=p->rchild;
		}
	}
	return OK:
}