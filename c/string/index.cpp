/*************************************************************************
    > File Name: c/string/index.c
    > Author: cheng
    > Mail:
    > Created Time: 2018年05月30日 星期三 10时12分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define OVERFLOW -1
typedef int status;
//－－－－－串的定义－－－－－
typedef struct
{
	char *h;
	int length;
}String;
//－－－－－串的操作－－－－－
status StrAssign(String &T,char *chars)
{
	int i;
	char *c
	if(T.h)
		free(T.h);
	for(i=0,c=chars;*c;++i,++c);		//求chars的长度
	if(!i)
	{
		T.h=NULL;
		T.length=0;
	}
	else
	{
		if(!T.h=(char *)malloc(i*sizeof(char)))
			exit(OVERFLOW);
		T.h[0..i-1]=chars[0..i-1];
		T.length=i;
	}	
	return OK;
}



