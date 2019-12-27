/* 算法思想：
    1、寻找中间结点：
        设置两个指针p,q;p每次往后走一个结点，q往后走2个结点，当q到达链尾时，p为中间结点。
    2、将后面一半的结点逆置
    3、逐一将结点插入前一半结点中
*/
typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE * reverse(NODE &L);
NODE * insert(NODE &L, NODE &head);

void realign_link(NODE &L){
    // 寻找中间结点
    NODE *p = L, *q = L;
    while(q && q->next){
        p = p->next;
        q = q->next->next;
    }
    // 逆置后面一半结点
    NODE *head = reverse(p->next);
    p->next = NULL;
    // 将逆置后的结点插入前面的结点中
    return insert(L,head);
}

NODE * reverse(NODE &L){
    NODE *p = L, *q, *r;
    if(!p || !p->next)
        return L;
    q = p->next; r = q->next;
    p->next = NULL;
    while(q){
        q->next = p;
        p = q; q = r;
        r = q->next;
    }
    return p;
}

NODE * insert(NODE &L, NODE &head){
    NODE *p = L, *q = head, r , s;
    while(q){
        r = p->next;
        s = q->next;
        p->next = q;
        q->next = r;
        p = r;
        q = s;
    }
    return L;
}
