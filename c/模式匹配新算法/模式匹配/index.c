#include <stdio.h>
#define	OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int status;
typedef unsigned char string[MAXSIZE+1];		//string[0]存放串长度
int nextval[100];								//模式串的next函数值数组,一定要设置数组长度，否则报错
void get_next(string t)							//求模式串的next函数值，修正值算法
{
	int i,j;
	i=1;
	nextval[1]=0;								
	j=0;
	while(i<=t[0])							
	{
		if(j==0||t[i]==t[j])					//next[i]==0||t[i]==t[next[i]]
		{
			i++;
			j++;
			if(t[i]!=t[j])						//t[i+1]!=t[next[i]+1]
				nextval[i]=j;
			else								//t[i+1]==t[next[i]+1]
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j]; 
	}
}

int index(string s,string t,int pos)			//利用KMP算法进行模式匹配
{
	int i,j;
	i=pos;
	j=1;
	while(i<=s[0]&&j<=t[0])
	{
		if(j==0||s[i]==t[j])
		{
			++j;
			++i;
		}
		else
			j=nextval[j];						//模式串向后移到nextval[j]位置
	}
	if(j>t[0])
		return i-t[0];
	else
		return ERROR;
}

int get_length(string s)
{
	int i;
	for(i=1;s[i]!=0;i++);
	return i-1;
}

int main()
{
	int m;
	string s,t;
	s[0]=0;
	//主串的赋值
	printf("请输入主串的元素:\n");
	scanf("%s",s+1);
	s[0]=(char)get_length(s);
	printf("主串序号:\n");
	for(m=1;m<=s[0];m++)
	{
		printf("%d",m);
	}
	putchar(10);
	//子串的赋值
	printf("请输入模式串的元素:\n");
	t[0]=0;
	scanf("%s",t+1);
	t[0]=(char)get_length(t);
	printf("模式串序号:\n");
	for(m=1;m<=t[0];m++)
	{
		printf("%d",m);
	}
	putchar(10);
	//调用模式匹配算法
	get_next(t);
	m=index(s,t,1);
	if(m)
		printf("匹配结果,在主串中的位置:%d\n",m);
	else
		printf("无匹配项");
}
