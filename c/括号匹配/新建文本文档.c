bool isValid(char* s) 
{
    char c[10000];
    int i = 0;
    c[i] = *s;
    s += 1;
    while(*s)
    {
        if(i >= 0 && (*s == c[i] + 1 || *s == c[i] + 2))    //�������ƥ�䣬���������е�Ԫ��
        {
            c[i] = '\0';
            -- i;
            ++ s;
        }
        else    //ѹ������
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