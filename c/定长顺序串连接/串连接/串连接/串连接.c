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
	printf("������a��Ԫ��:\n");
	scanf("%s",a+1);
	getchar();
	a[0]=Strlen(a);
	printf("������b��Ԫ��:\n");
	scanf("%s",b+1);
	getchar();
	b[0]=Strlen(b);
	j=Concat(&L,a,b);
	i=(int)L[0];
	printf("���Ӻ��Ԫ��Ϊ:");
	for(m=1;m<=i;m++)
	{
		printf("%c",L[m]);
	}
	putchar(10);
	if(j)
	{
		printf("�޽ض�\n");
	}
	else
		printf("�нض�\n");
}