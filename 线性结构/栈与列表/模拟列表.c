// 用两个栈模拟列表的入栈与出栈
int EnQueue(Stack &s1, Stack &s2, Elemtype e){
    // 如果s1未溢出
    if(!StackOverflow(s1)){
        Push(s1, e);
        return 1;
    }
    // s1满，s2不空，则队列满
    if(StackOverflow(s1) && !StackEmpty(s2)){
        printf("队列满");
        return 0;
    }
    // s1满,s2为空，则将s1元素插入s2中，再将e插入s1
    if(StackOverflow(s1) && StackEmpty(s2)){
        while(!StackEmpty(s1)){
            Pop(s1, x);
            Push(s2, x);
        }
    }
    Push(s1, e);
    return 1;
}


// 出栈算法
int DeQueue(Stack &s1, Stack &s2, Elemtype &x){
    // s2非空，将s2中元素出栈
    if(!StackEmpty(s2)){
        Pop(s2, x);
        return 1;
    }
    // s2空，s1空,列表为空
    else if(StackEmpty(s1)){
        printf("列表为空");
        return 0;
    }
    // s2空，s1有元素,将s1中元素压入s2中，然后在pop(s2, x)
    else{
        while(!StackEmpty(s1)){
            Pop(s1, x);
            Push(s2, x);
        }
        Pop(s2, x);
    }
}
