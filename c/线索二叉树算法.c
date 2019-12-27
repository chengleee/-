// 线索二叉树

// 线索二叉树存储表示
typedef enum PointerTag {Link, Thread};	// Link == 0:指针; Thread == 1: 线索
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;	// 左右孩子指针
	PointerTag LTag, RTag;	// 左右标志
}BiThrNode, *BiThrTree;

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
// T指向头结点，头结点的左链lchild 指向根结点，可参见线索化算法
// 中序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit
{
	p = T->lchild;	// p指向根结点
	while (p != T)	// 空树或遍历结束时，p == T
	{
		while (p->LTag == Link)
			p = p->lchild;
		if (!Visit(p->data))
			return ERROR;
		while (p->RTag == Thread && p->rchild != T)	// 访问后继结点
		{
			p = p->rchild;
			Visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}

Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
// 中序遍历二叉树，并将其中序线索化，Thrt指向头结点
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		exit(OVERFLOW);
	Thrt->LTag = Link; Thrt->RTag = Thread;	// 建头结点
	Thrt->rchild = Thrt;	// 右指针回指
	if (!T) Thrt->lchild = Thrt;	// 若二叉树空，则左指针回指
	else
	{
		Thrt->lchild = T;	pre = Thrt;
		InThreading(T);	// 中序遍历进行中序线索化
		pre->rchild = Thrt; pre->RTag = Thread;	// 最后一个结点线索化
		Thrt->rchild = pre;
	}
	return OK;
}

void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);	// 左子树线索化
		if (!p->lchild)	// 前驱线索
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)	// 后继线索
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;	// 保持pre指向p的前驱
		InThreading(p->rchild); // 右子树线索化
	}
}