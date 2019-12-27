#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef unsigned char String[MAXSIZE+2];
typedef int status;
status Concat(String *L,String a,String b)
{
	int i,j;
	if(a[0]+b[0]<=MAXSIZE)
	{
		for(i=0;i<=a[0];i++)
		{
			(*L)[i]=a[i];
		}
		for(j=1;j<=b[0];j++,i++)
		{
			(*L)[i]=b[j];
		}
		(*L)[0]=(char)(i-1);
		return OK;
	}
	else if(a[0]<=MAXSIZE)
	{
		for(i=0;i<=a[0];i++)
		{
			(*L)[i]=a[i];
		}
		for(j=1;a[0]+j<=MAXSIZE;j++,i++)
		{
			(*L)[i]=b[j];
		}
		(*L)[0]=(char)(i-1);
		return ERROR;
	}
	else
	{
		for(i=0;i<=MAXSIZE;i++)
		{
			(*L)[i]=a[i];
		}
		(*L)[0]=(char)(i-1);
		return ERROR;
	}
}

int Strlen(String l)
{
	int i=1;
	for(;l[i]!=0;i++);
	return i-1;
}


int main()
{
	int i,j,m;
	String L,a,b;
	a[0]=b[0]='0';
	printf("请输入a的元素:\n");
	scanf("%s",a+1);
	getchar();
	a[0]=Strlen(a);
	printf("请输入b的元素:\n");
	scanf("%s",b+1);
	getchar();
	b[0]=Strlen(b);
	j=Concat(&L,a,b);
	i=(int)L[0];
	printf("连接后的元素为:");
	for(m=1;m<=i;m++)
	{
		printf("%c",L[m]);
	}
	putchar(10);
	if(j)
	{
		printf("无截断\n");
	}
	else
		printf("有截断\n");
}