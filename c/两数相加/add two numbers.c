/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deeltail(struct ListNode * pre,struct ListNode * r,int carry);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * head ,*p,*q,*pre;
    int carry = 0;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    head = l1;
    p = head;
    
    while(l1 && l2){
        pre = p;//指向p指针的前向指针
        p->val = l1->val + l2->val + carry;
        carry = 0;
        if(p->val > 9){
            p->val -= 10;
            carry = 1;
        }
        l1 = l1->next;
        l2 = l2->next;
        p = p->next;
    }
    if(!l1 && !l2){//l1与l2都只有一个数
        if(carry){
            q= (struct ListNode *)malloc(sizeof(struct ListNode));
            q->val = carry;
            q->next = NULL;
            pre->next = q;
        }
    }
    else if(l2){//l1的长度小于l2,由于head最初是指向l1的，特殊处理
       deeltail(pre,l2,carry);
    }
    else{//l1的长度大于l2
       deeltail(pre,l1,carry);
    }
    return head;
}
void deeltail(struct ListNode * pre,struct ListNode * r,int carry){
    struct ListNode * q;
    pre->next = r;
    q = pre->next;
    while(q){
        q->val +=carry;
        if(q->val>9){
            q->val -= 10;
            carry = 1;
        }else{
            carry =0;
            
        }
        pre = q;
        q = q->next;
    }
    if(carry){//最后一个节点加上进位大于10需处理多出来的节点，val=1
        q= (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = carry;
        q->next = NULL;
        pre->next = q;
    }
}