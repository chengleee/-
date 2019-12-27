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
	int i,a;
	char *c;
	for(i=0,c=chars;*c;++i,++c);		//求chars的长度
	if(!i)
	{
		T.h=NULL;
		T.length=0;
	}
	else
	{
		T.h=(char *)malloc(i*sizeof(char));
		if(!T.h)
			exit(OVERFLOW);
		for(a=0;a<=i-1;a++)
		{
			T.h[a]=chars[a];
		}
		T.length=i;
	}	
	return OK;
}

int StrLength(String s)
{
	return s.length;
}

int StrCompare(String s,String T)
{
	int i;
	for(i=0;i<s.length&&i<T.length;++i)
	{
		if(s.h[i]!=T.h[i])
			return s.h[i]-T.h[i];
	}
	return s.length-T.length;
}

status SubString(String &sub,String s,int pos,int len)
{
	int i,j;
	if(pos<1||pos>s.length||len<0||len>s.length-pos+1)
		return ERROR;
	if(!len)
	{
		sub.h=NULL;
		sub.length=0;
	}
	else
	{
		sub.h=(char *)malloc(len*sizeof(char));
		for(i=0,j=pos-1;i<=sub.length-1&&j<=pos+len-2;i++,j++)
		{
			sub.h[i]=s.h[j];
		}
		sub.length=len;
	}

}

int index(String s,String t,int pos)
{
	int m,n,i;
	String sub;
	if(pos>0)
	{
		n=StrLength(s);
		m=StrLength(t);
		i=pos;
		while(i<=n-m+1)
		{
			SubString(sub,s,i,m);
			if(StrCompare(sub,t)!=0)
				++i;
			else 
				return i;
		}
	}
	return 0;
}

int main()
{
	String s,t;
	int pos=1;
	StrAssign(s,"abcd");
	StrAssign(t,"bcd");
	printf("%d\n",index(s,t,pos));
}

