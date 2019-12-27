// 树的非递归后序遍历
void PostOder(BiTree T){
    stack s;
    InitStack(s);
    BiTree p = T,pre = NULL;// pre指示上一个被访问的结点
    Push(s, T);
    while(p || !isEmpty(s)){
        p = s->data[top];
        // 如果不存在子结点或者子结点已访问，则访问根结点
        if((p->lchild == NULL && p->rchild == NULL) || (pre != NULL && (pre == p->lchild || pre == p->rchild))){
            visit(p);
            Pop(s,e);
            pre = p;
        }
        else{
            if(p->rchild != NULL){
                Push(s,p->rchild);
            }
            if(p->lchild != NULL){
                Push(s,p->lchild);
            }
        }
    }
}
