// 算法习题10
// 求先序遍历中的第k个结点的值
// 算法思想：
// 先序遍历

int i = 1;
ElemType search(BiTree T, int k){
    if(T == NULL)
        return Fail;
    if(i == k)
        return T->data;
    ++i;
    e = search(T->lchild,k)
    if(e != Fail)
        return e;
    return search(T->rchild,k);
}
