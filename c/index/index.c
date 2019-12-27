#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
typedef int status;
typedef unsigned char string[MAXSIZE+1];

int evaluatelen(string s)
{
	int i=1;
	for(;s[i]!=0;i++);
	return i-1;
}

status strassign(string *s)
{
	(*s)[0]='0';
	scanf("%s",*s+1);
	(*s)[0]=(char)evaluatelen(*s);
}

int Index(string l,string s,int pos)
{
	int i,j;
	i=pos;
	j=1;
	while(i<=l[0]&&j<=s[0])
	{
		if(l[i]==s[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+2;
			j=1;	
		}
	}
	if(j>s[0])
		return i-s[0];
	else
		return 0;
}	

int main()
{
	string l,s;
	int i,pos;
	printf("请输入串的元素:\n");
	strassign(&l);
	printf("请输入子串的元素:\n");
	strassign(&s);
	printf("请指定字符位置:\n");
	scanf("%d",&pos);
	if(pos<0||pos>l[0])
		printf("ERROR");
	i=Index(l,s,pos);
	printf("%d",i);
}
