#include <stdio.h>
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 12500		//非零元个数最大值
typedef int status;
typedef int elemtype;
typedef struct 
{
	int i,j;			//该非零元的行下标和列下标
	elemtype e;
}triple;				
typedef struct
{
	triple data[MAXSIZE+1];		//非零元三元数组表,data[0]未使用
	int mu,nu,tu;		//矩阵的行数、列数、和非零元个数
}tsmatrix;					

/*status transposesmatrix(tsmatrix m,tsmatrix *t)
	//采用三元组表存储表示，求稀疏矩阵m的转置矩阵t.
{
	int p,q,col;
	t->mu=m.nu;
	t->nu=m.mu;
	t->tu=m.tu;
	if(t->tu)
	{
		q=1;
		for(col=1;col<=m.nu;++col)
		{
			for(p=1;p<=m.tu;p++)
			{
				if(m.data[p].j==col)
				{
					t->data[q].j=m.data[p].i;
					t->data[q].i=m.data[p].j;
					t->data[q].e=m.data[p].e;
					++q;
				}
			}
		}
	}
	return OK;
}*/

status fasttransposesmatrix(tsmatrix m,tsmatrix *t)
{
	int T,p,q,col,num[m.nu+1],cpot[m.nu+1];
	t->mu=m.nu;
	t->nu=m.mu;
	t->tu=m.tu;
	if(t->tu)
	{
		for(col=1;col<=m.nu;++col)
			num[col]=0;
		for(T=1;T<=m.tu;++t)
			++num[m.data[T].j];			//求m中每一列含非零元个数
		cpot[1]=1;
	//求第col列中第一个非零元在b.data中的序号
		for(col=2;col<=m.nu;++col)
		{
			cpot[col]=cpot[col-1]+num[col-1];
		}
		for(p=1;p<=m.nu;++p)
		{
			col=m.data[p].j;
			q=cpot[col];
			t->data[q].i=m.data[p].j;
			t->data[q].j=m.data[p].i;
			t->data[q].e=m.data[p].e;
			++cpot[col];
		}
	}
	return OK;
}
