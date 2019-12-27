// 算法习题9.cpp
// 将二叉树的所有结点的左右子树交换
// 算法思想：
// 后序遍历，从底层开始交换

void swap(BiTree T){
    if(T){
        swap(T->lchild);
        swap(T->rchild);
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
