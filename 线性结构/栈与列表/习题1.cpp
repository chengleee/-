// 假设算术表达式中含有括号、方括号和花括号，编写算法判别括号是否匹配，字符“\0"作为结束符

// 是否是左括号
bool isleft(char c){
    switch(c){
        case '(': case '{': case '[':return 1;break;
        default: return 0;
    }
}
bool BracketsCheck(char *str){
    char *p; // p为工作指针
    InitStack(s);
    while(p != '\0'){
        // 如果符号是左括号，则压入栈中
        if(isleft(*p)){
            Push(s, *p);
        }
        else{
            switch(*p){
                case '}':
                    Pop(s ,e);
                    if(e != '{')
                        return 0;
                    break;
                case ')':
                    Pop(s, e);
                    if(e != '(')
                        return 0;
                    break;
                case ']':
                    Pop(s, e);
                    if(e != '[')
                        return 0;
                    break;
                default :
                    break;
            }
            p++;
        }
        if(!StackEmpty)
            return 0;
        else
            return 1;
    }
}
