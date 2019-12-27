// ����������

// �����������洢��ʾ
typedef enum PointerTag {Link, Thread};	// Link == 0:ָ��; Thread == 1: ����
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;	// ���Һ���ָ��
	PointerTag LTag, RTag;	// ���ұ�־
}BiThrNode, *BiThrTree;

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
// Tָ��ͷ��㣬ͷ��������lchild ָ�����㣬�ɲμ��������㷨
// �����������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
{
	p = T->lchild;	// pָ������
	while (p != T)	// �������������ʱ��p == T
	{
		while (p->LTag == Link)
			p = p->lchild;
		if (!Visit(p->data))
			return ERROR;
		while (p->RTag == Thread && p->rchild != T)	// ���ʺ�̽��
		{
			p = p->rchild;
			Visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}

Status InOrderThreading(BiThrTree &Thrt, BiThrTree T)
// ���������������������������������Thrtָ��ͷ���
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		exit(OVERFLOW);
	Thrt->LTag = Link; Thrt->RTag = Thread;	// ��ͷ���
	Thrt->rchild = Thrt;	// ��ָ���ָ
	if (!T) Thrt->lchild = Thrt;	// ���������գ�����ָ���ָ
	else
	{
		Thrt->lchild = T;	pre = Thrt;
		InThreading(T);	// ���������������������
		pre->rchild = Thrt; pre->RTag = Thread;	// ���һ�����������
		Thrt->rchild = pre;
	}
	return OK;
}

void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);	// ������������
		if (!p->lchild)	// ǰ������
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)	// �������
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;	// ����preָ��p��ǰ��
		InThreading(p->rchild); // ������������
	}
}