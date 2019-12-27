#include <stdio.h>
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
#define MAXRC 100
typedef int status;
typedef int elemtype;
typedef struct
{
	int i,j;
	elemtype e;
}triple;		//三元数组元素
typedef struct
{
	triple data[MAXSIZE+1];			//非零元三元组表
	int rpos[MAXRC+1];				//各行第一个非零元的位置表
	int mu,nu,tu;					//矩阵的行数、列数和非零元个数
}rlsmatrix;

status multsmatrix(rlsmatrix m,rlsmatrix n,rlsmatrix *Q)	//求矩阵Q=mXn乘积，采用行逻辑链接存储表示
{
	int p,t,tp,arow,brow,ccol,ctemp[];
	if(m.nu!=n.mu)
		return ERROR;
	//q初始化
	Q->mu=m.mu;
	Q->nu=n.nu;
	Q->tu=0;
	if(m.tu*n.tu!=0)		//q是非零矩阵
	{
		for(arow=1;arow<=m.mu;++arow)		//处理m的每一行
		{
			ctemp[]=0;		//当前行各元素累加器清零
			Q->rpos[arow]=Q->tu+1;
			if(arow<m.mu)
				tp=m.rpos[arow+1];
			else
				tp=m.tu+1;
			for(p=m.rpos[brow];p<tp;++p)
				//对当前行中每一个非零元找到对应元在n中的行号
			{
				brow=m.data[p].j;
				if(brow<n.mu)
					t=n.rpos[brow+1];
				else
					t=n.tu+1;
				for(q=m.rpos[arow];q<t;++q)
				{	
					ccol=n.data[q].j;		//乘积元素在Q中列号
					ctemp[ccol]+=m.data[p].e*n.data[q].e;
				}	
			}
			for(ccol=1;ccol<=Q->nu;++ccol)	//压缩存储该行非零元素
			{
				if(ctemp[ccol])
				{
					if(++Q->nu>MAXSIZE)
						return ERROR;
					Q->data[Q->tu]=(arow,ccol,ctemp[ccol]);
				}
			}
		}
	}
	return OK;
}
