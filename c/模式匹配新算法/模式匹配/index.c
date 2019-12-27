#include <stdio.h>
#define	OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int status;
typedef unsigned char string[MAXSIZE+1];		//string[0]��Ŵ�����
int nextval[100];								//ģʽ����next����ֵ����,һ��Ҫ�������鳤�ȣ����򱨴�
void get_next(string t)							//��ģʽ����next����ֵ������ֵ�㷨
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

int index(string s,string t,int pos)			//����KMP�㷨����ģʽƥ��
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
			j=nextval[j];						//ģʽ������Ƶ�nextval[j]λ��
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
	//�����ĸ�ֵ
	printf("������������Ԫ��:\n");
	scanf("%s",s+1);
	s[0]=(char)get_length(s);
	printf("�������:\n");
	for(m=1;m<=s[0];m++)
	{
		printf("%d",m);
	}
	putchar(10);
	//�Ӵ��ĸ�ֵ
	printf("������ģʽ����Ԫ��:\n");
	t[0]=0;
	scanf("%s",t+1);
	t[0]=(char)get_length(t);
	printf("ģʽ�����:\n");
	for(m=1;m<=t[0];m++)
	{
		printf("%d",m);
	}
	putchar(10);
	//����ģʽƥ���㷨
	get_next(t);
	m=index(s,t,1);
	if(m)
		printf("ƥ����,�������е�λ��:%d\n",m);
	else
		printf("��ƥ����");
}
