bool isValid(char* s) 
{
    char c[10000];
    int i = 0;
    c[i] = *s;
    s += 1;
    while(*s)
    {
        if(i >= 0 && (*s == c[i] + 1 || *s == c[i] + 2))    //如果扩号匹配，弹出数组中的元素
        {
            c[i] = '\0';
            -- i;
            ++ s;
        }
        else    //压入数组
        {
            c[++i] = *s;
            ++ s;
        }
    }
    if(c[0])
        return 0;
    else
        return 1;
}