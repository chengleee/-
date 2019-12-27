//最简单的visit函数
//调用实例:PreOrderTraverse(T,PrintElement);
Status PrintElement(TElemType e)
//输出e
{
	printf(e);
	return OK;
}

Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e))
//采用二叉链表存储结构，Visit是对数据元素操作的应用函数
//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
{
	if(T)
	{
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if((PreOrderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}