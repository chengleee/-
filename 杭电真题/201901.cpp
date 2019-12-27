/*
    算法思想：
        p1、p2指数递减，逐项将指数相同的结点系数相加
*/
Polynomial add_poly(Polynomial p1, Polynomial p2){
    Polynomial result = (Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial p = result;
    p->link = NULL;
    while(p1 && p2){
        q = (Polynomial)malloc(sizeof(struct PolyNode));
        if(p1->expon > p2->expon){
            q->coef = p1->coef;
            q->expon = p1->expon;
            p->link = q;
            p = q;
            p1 = p1->link;
        }
        else if(p1->expon < p2->expon){
            q->coef = p2->coef;
            q->expon = p2->expon;
            p->link = q;
            p = q;
            p2 = p2->link;
        }
        else{
            q->coef = p1->coef + p2->coef;
            q->expon = p1->expon;
            p->link = q;
            p = q;
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    if(p1){
        while(p1){
            q = (Polynomial)malloc(sizeof(PolyNode));
            q->coef = p1->coef;
            q->expon = p1->expon;
            p->link = q;
            p = q;
            p1 = p1->link;
        }
    }
    if(p2){
        q = (Polynomial)malloc(sizeof(PolyNode));
        q->coef = p2->coef;
        q->expon = p2->expon;
        p->link = q;
        p = q;
        p2 = p2->link;
    }
    p->link = NULL;
    return result->link;
}
