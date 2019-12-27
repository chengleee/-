#include <stdio.h>
#include <stdarg.h>				//提供宏va_start、va_arg和va_end，用于存取变长参数表
#include <stdlib.h>
#define	TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAX_ARRAY_DIM 8			//假设数组维数的最大值为8
typedef unsigned char elemtype;
typedef int status;
typedef struct
{
	elemtype *base;				//数组元素基址，由initarray分配
	int dim;					//数组维数
	int *bounds;				//数组维界基址，由initarray分配,是存放每维长度的数组，bounds[0]存第一维长度（例如a[3][4]),bounds[0]=3
	int *constants;				//数组映像函数常量基址，由initarray分配,用于辅助定位的数组
}Array;

status initarray(Array *a,int dim,...)		//若维数dim和随后的各维长度合法，则构造相应的数组a,并返回OK
{
	int i,elemtotal;
	va_list ap;
	if(dim<1||dim>MAX_ARRAY_DIM)
		return ERROR;
	a->dim=dim;
	a->bounds=(int *)malloc(dim*sizeof(int));
	if(!a->bounds)
		exit(OVERFLOW);
	elemtotal=1;
	va_start(ap,dim);			//ap为va_list类型，是存放变长参数表信息的数组
	for(i=0;i<dim;i++)
	{
		a->bounds[i]=va_arg(ap,int);
		if(a->bounds[i]<0)
			return ERROR;
		elemtotal*=a->bounds[i];		//若维数合法，则存入a->bounds，并求出a的元素总数elemtotal
	}
	va_end(ap);
	a->base=(elemtype *)malloc(elemtotal*sizeof(elemtype));
	if(!a->base)
		exit(OVERFLOW);
	//求映像函数的常数c，并存入a->constants[i-1],i=1,...,dim
	a->constants=(int *)malloc(dim*sizeof(int));
	a->constants[dim-1]=1;
	for(i=dim-2;i>=0;--i)
	{
		a->constants[i]=a->bounds[i+1]*a->constants[i+1];
	}
	return OK;
}

status destroyarray(Array *a)		//销毁数组
{
	if(!a->base)
		return ERROR;
	free(a->base);
	a->base=NULL;
	if(!a->bounds)
		return ERROR;
	free(a->bounds);
	a->bounds=NULL;
	if(!a->constants);
		return ERROR;
	free(a->constants);
	a->constants=NULL;
	return OK;
}

status locate(Array a,va_list ap,int *off)		//若ap指示的各下标值合法，则求出该元素在a中相对地址off
{
	int i,ind;
	off=0;
	for(i=0;i<a.dim;++i)
	{
		ind=va_arg(ap,int);
		if(ind<0||ind>=a.bounds[i])
			return OVERFLOW;
		off+=a.constants[i]+ind;
	}
	return OK;
}

status value(Array a,elemtype *e,...)			//a是n维数组，e为元素变量，随后是n个下标值。若各下标值不超界，则赋值为所指定的a的元素值
{
	int result,off;
	va_list ap;
	va_start(ap,*e);
	if((result=locate(a,ap,&off))<=0)
		return result;
	*e=*(a.base+off);
	return OK;
}

status assign(Array *a,elemtype e,...)			//若下标不超界，将e的值赋给所指定的a的元素
{
	int result,off;
	va_list ap;
	va_start(ap,e);
	if((result=locate(*a,ap,&off))<=0)
		return result;
	*(a->base+off)=e;
	return OK;
}