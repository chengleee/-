// 查找值为x的结点，打印其所有祖先，假设值为x的结点不多于一个
// 算法思想：
// 采用后序遍历查找结点，当找到结点时，栈内剩余的结点都是其祖先

void search(BiTree T,Elemtype x){
    stack s;
    InitStack s;
    BiTree p = T, r = NULL;
    while(p || !isEmpty(T)){
        if(p){
            Push(T,p);
            p = p->next;
        }
        else{
            p = GetTop(s);
            if(p->rchild && p->rchild != r){
                Push(s,p->rchild);
                p = p->lchild;
            }
            else{
                Pop(s,p);
                if(p->data == x){
                    print(stack);
                    break;
                }
                r = p;
                p = NULL;
            }
        }
    }
}
