// 树的中序遍历
void InOrder(BiTree T){
    Stack s;
    InitStack(s);
    BiTree p = T;
    while(p || !isEmpty(s)){
        if(p){ //根指针进栈，遍历左子树
            Push(s,p);  
            p = p->lchild;  
        }
        else{ // 根指针退栈，访问根结点，遍历右子树
            Pop(s,p);
            visit(p);
            p = p->rchild;
        }
    }

}
