// 将二叉树的叶结点按从左到右顺序连接成一个单链表
// 算法思想：
// 寻找叶结点用中序遍历，构建链表采用尾插法

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTNode *head = (BiTNode *)malloc(sizeof(BiTNode)), *rear = head;
rear->rchild = NULL;
BiTree InOder(BiTree T){
    if(T){
        InOder(T->lchild);
        if(T->lchild == NULL && T->rchild == NULL){
            rear->rchild = T;
            rear = T;
        }
        InOder(T->rchild);
        rear->rchild = NULL;
    }
    return head;
}
