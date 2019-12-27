// 后序遍历
void PostOrder(BiTree T){
    InitStack s;
    p = T;
    r = NULL;   // 指向最近访问的结点
    while(p || !isEmpty(s)){
        // 走到最左边
        if(p){
            Push(s,p);
            p = p->lchild;
        }
        else{
            p = Gettop(s);
            if(p->rchild && p->rchild != r){
                p = p->rchild;
                Push(s,p);
                p = p->lchild;
            }
            else{
                Pop(s,p);
                visit(p->data);
                r = p;
                p = NULL;
            }
        }
    }
}
