// 每次执行Locate算法时，令元素x的频度增1，并根据频度重新排序，最近访问的结点在同频度元素前，链表为非循环单链表
// 算法思想：
// 1、找到结点
// 2、将结点前移
// 返回结点地址
*LNode Locate(DLinklist &L,Elemtype x){
    DLNode *p = L->next;
    while(p && p->data != x){
        p = p->next;
    }
    if(p = NULL){
        return NULL;
    }
    ++p->frep;
    while(p->frep >= p->pred->frep){
        p->data <-> p->pred->data;
        p->frep <-> p->pred->frep;
        p = p->pred;
    }
    return p;
}
