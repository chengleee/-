#include <stdio.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    int i,j;
    char c[1000];
    for(j = 0;; ++j)
    {
        for(i = 0;i < strsSize; ++i)
        {
            if((*(strs + i))[j] != strs[0][j])
                break;
        }
        if(i == 0)
        {
            c[0] = ' ';
        }
        if(i != strsSize)
        {
            break;
        } 
        c[j] = strs[0][j];
    }
    return c;
}

int main()
{
	char *s[] = {"flower","flow","flight"};
	char *result = longestCommonPrefix(s,3);
	//printf("%c",(*(s+2))[2]);
	printf("result = %s\n",result);
}