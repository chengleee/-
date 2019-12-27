// 链表习题21
// 已知带表头结点单链表，只给出了头指针list，在不改变链表的前提下，查找链表中倒数第k个位置上的结点，成功输出该结点的值，并返回1，否则返回0

// 算法思想：
// 设置2个指针p,q
// p先访问k个结点
// p,q同时访问剩余结点，p访问结束时，q为所需结点

typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    LNode *link;
}LNode, *Linklist;

bool search_k(Linklist L,int k){
    LNode *p = L->link,*q = L->link;
    int count=0;
    while(p != NULL){
        if(count < k)
            count ++;
        else
            q = q-link;
        p = p->link;
    }
    if(count < k)
        return 0;
    else{
        printf("%d",q->data);
        return 1;
    }
}
