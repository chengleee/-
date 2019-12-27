// 链表习题23
// 将链中绝对值相等的结点，仅保留第一次出现的结点
// 算法思想：
// 空间换时间思想，利用一个长为N＋1的数组的下标表示链表中出现的数
typedef struct LNode{
    Elemtype data;
    LNode *link;
}LNode, *Linklist;

void del_e(Linklist &L, int N){
    int *p = (int *)malloc(sizeof(int) * (N + 1));
    LNode *q = L->link, *pre = L;
    int i;
    // 为p初始化
    for(i = 0; i <= N; ++i){
        *(p + i) = 0;
    }
    while(q != NULL){
        if(q->data < 0)
            i = -p->data;
        else
            i = p->data;
        // 如果第一次出现
        if(p[i] == 0){
            ++p[i];
            q = q->link;
            pre = pre->link;
        }
        else{
            pre->link = q->link;
            free(q);
            q = pre->link;
        }
    }
    free(p);
}
