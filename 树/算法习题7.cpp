// 算法习题7
// 判别二叉树是否是完全二叉树
// 算法思想：
// 利用层序遍历，将所有结点都插入队列（包括空结点），出现空结点时，查看其后是否有非空结点，若有，则二叉树不是完全二叉树。

bool IsComplete(BiTree T){
    InitQueue(Q);
    if(!T)
        return 1; // 空树为满二叉树
    EnQueue(Q,T);
    while(!isEmpty(Q)){
        DeQueue(Q,p);
        if(p){
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else{
            while(!isEmpty(Q)){
                DeQueue(Q,p);
                if(p)
                    return 0;
            }//while
        }//else
    }//while
}
