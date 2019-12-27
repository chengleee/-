// 算法习题4
// 试给出二叉树的自下而上、从右到左的层次遍历算法
// 算法思想：
// 与常规层次遍历正好相反，只要将原来对列出来的元素都放到一个栈中，只有队列空了才从栈的最上层元素开始访问

bool InvertLever(BiTree T){
    if(!T)
        return 0;
    InitQueue(Q);
    InitStack(s);
    p = T;
    while(!isEmpty(Q)){
        s->data[s.top++] = p->data;
        if(p->lchild != NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild != NULL)
            EnQueue(Q,p->rchild);
        if(!isEmpty(Q)){
            DeQueue(Q,p);
        }
    }
    while(s->top != -1){
        visit(s->data[--s->top]);
    }
    return 1;
}
