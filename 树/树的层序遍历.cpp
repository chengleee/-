// 树的层序遍历
void LevelOrder(BiTree T){
    Quene q;
    BiTree p;
    InitQuene(q);
    EnQuene(q, T);
    while(!isEmpty(q)){
        DeQuene(q, p);
        visit(p);
        if(p->lchild != NULL){
            EnQuene(q, p->lchild);
        }
        if(p->rchild != NULL){
            EnQuene(q, p->rchild);
        }
    }
}
