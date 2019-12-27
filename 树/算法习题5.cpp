// 算法习题5
// 非递归算法求二叉树的高度
// 算法思想：
// 利用层序遍历算法

int Btdepth(Bitree T){
    if(!T){
        return 0;
    }
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while(front < rear){
        p = Q[++front];
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rchild] = p->rchild;
        if(front == last){
            level++;
            last = rear;
        }
    }
    return level;
}
