// 往复找到循环单结点最小值，删除直到空链表为止
void del_min(Linklist &L){
    LNode *p, *pre, *premin;
    Elemtype min = L->next->date;
    while(L->next != L){
        p = L->next;
        pre = L;
        while(p){
            if(p->date < min){
                min = p->date;
                premin = pre;
            }
            p = p->next;
            pre = pre->next;
        }
        p = premin->next;
        print(p->date);
        premin->next = p->next;
        free(p);
    }
    free(L);
}
