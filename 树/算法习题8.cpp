// 算法习题8
// 计算二叉树的所有双分支结点个数
// 算法思想：
// 若根结点度为2，则度为2的结点数为其子孙度为2的结点数＋1
// 否则为其子孙度为2的结点数

int DsonNodes(BiTree T){
    if(T == NULL)
        return 0;
    else if(T->lchild && T->rchild)
        return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
    else
        return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}
