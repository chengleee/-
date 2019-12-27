#include <stdio.h>
#define MAXSIZE 1000
typedef char ElemType;
typedef struct
{
    ElemType data;
	int cur;
}component,SLinkList;
//��һά����space�и���������һ����������
void InitSpace(SLinkList space[MAXSIZE])
{
    int i;
	for(i=0;i<MAXSIZE;i++)
	{
	    space[i].cur=i+1;
		space[MAXSIZE-1].cur=0;
	}
}
//Ϊ��������ַ
int Malloc_SL(SLinkList space[])
	//�����ÿռ�����ǿգ��򷵻ط���Ľ���±�
{
    int i;
	i=space[0].cur;
	if(space[0].cur)
		space[0].cur=space[i].cur;
	return i;
}
//��������
void Free_SL(SLinkList space[],int k)
//���±�Ϊk�Ľ�����
{
    space[k].cur=space[0].cur;
	space[0].cur=k;
}
//ʵ��(A-B)U(B-A)
void difference(SLinkList space[])
{
    int i,j,k,m,n,p,r,s;
	char b;
    InitSpace(space);
	s=Malloc_SL(space);//����s��ͷ���
	r=s;
	printf("������a,b�ĳ���\n");
	scanf("%d %d",&m,&n);//����A��B�ĳ���
	printf("������a��ֵ\n");
	for(j=1;j<=m;++j)
	{
	    i=Malloc_SL(space);
		getchar();
		scanf("%c",&space[i].data);
		space[r].cur=i;
		r=i;
	}
	space[r].cur=0;//β���ָ��Ϊ��
	printf("����������b��ֵ\n");
	for(j=1;j<=n;++j)
	{
	    getchar();
		scanf("%c",&b);//��������b��Ԫ��
		p=s;
		k=space[s].cur;//kָ��A�е�һ�����
		while(k!=space[r].cur&&space[k].data!=b)
		{
		    p=k;
			k=space[k].cur;
		}
		if(k==space[r].cur)
		{
		    i=Malloc_SL(space);
			space[i].data=b;
			if(i<r)
			{
			    space[i-1].cur=i;
				space[i].cur=i+1;
			}
			if(i>=r)
			{
			space[r].cur=i;
			space[i].cur=0;
			r=i;
			}
		}
		else
		{
		    space[p].cur=space[k].cur;
			Free_SL(space,k);
			if(r==k)
				r=p;
		}
	}
	
}
//������
main()
{
	int i;
    SLinkList space[MAXSIZE];
	difference(space);
	for(i=2;space[i-1].cur!=0;i++)
	{
	    printf("%c ",space[i].data);
	}
}