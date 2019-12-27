// 算法习题11
// 将树中以元素值为x的结点为根结点的子树,并释放空间
// 算法思想：
// 删除子树用后序遍历，删除子树后要将其父结点左右指针置空，采用层序遍历查找
void Del_x(BiTree T){
    Del_x(T->lchild);
    Del_x(T->rchild);
    free(T);
}

void search(BiTree T, ElemType x){
    if(T->data == x){
        Del_x(T);
        exit(0);
    }
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!isEmpty(Q)){
        DeQueue(Q,p);
        if(p->lchild){
            if(p->lchild->data == x){
                Del_x(p->lchild);
                p->lchild = NULL;
            }
            else
                EnQueue(Q,p->lchild);
        }
        if(p->rchild){
            if(p->rchild->data = x){
                Del_x(p->rchild);
                p->rchild = NULL;
            }
            else
                EnQueue(Q,p->rchild);
        }
    }
}
