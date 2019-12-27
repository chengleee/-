// 求非空二叉树的宽度
// 算法思想：
// 利用层序遍历，统计每一层的结点数

int BTWidth(BiTree b){
    Queue Q[MAXSIZE];
    int front = rear = 0,j,sum = 1; // sum统计每一层的结点数，第一层为1个
    Q[rear++] = b;
    j = 1; // j为从第二层开始每一层的第一个结点在队列中的位置
    BiTree p;
    while(rear != front){
        p = Q[front++];
        if(p->lchild)
            Q[rear++] = p->lchild;
        if(p->rchild)
            Q[rear++] = p->rchild;
        if(front == j){
            sum = (rear-j) > sum ? rear-j : sum;
            j = rear;
        }
    }
    return sum;
}
