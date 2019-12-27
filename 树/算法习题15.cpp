// 已知满二叉树先序，求后序
// 算法思想：
// 后序遍历二叉树

void Tpretopost(ElemType pre[],ElemType &post[]){
    InitStack(s);
    int p = 0,r = -1,i = 0; // r为最近访问的结点下标
    while(p != -1 || !isEmpty(s)){
        if(p != -1 && tre[p]){
            Push(s, p);
            p = 2*(p+1)-1;
        }
        else{
            p = s->data[s->top];
            if(pre(2*(p+1)) && 2*(p+1) != r){
                p = 2*(p+1);
                Push(s,p);
                p = 2*(p+1)-1;
            }
            else{
                Pop(s,p);
                post[i++] = pre[p];
                r = p;
                p = -1;
            }
        }
    }
}
