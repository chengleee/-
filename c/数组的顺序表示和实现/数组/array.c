#include <stdio.h>
#include <stdarg.h>				//�ṩ��va_start��va_arg��va_end�����ڴ�ȡ�䳤������
#include <stdlib.h>
#define	TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAX_ARRAY_DIM 8			//��������ά�������ֵΪ8
typedef unsigned char elemtype;
typedef int status;
typedef struct
{
	elemtype *base;				//����Ԫ�ػ�ַ����initarray����
	int dim;					//����ά��
	int *bounds;				//����ά���ַ����initarray����,�Ǵ��ÿά���ȵ����飬bounds[0]���һά���ȣ�����a[3][4]),bounds[0]=3
	int *constants;				//����ӳ����������ַ����initarray����,���ڸ�����λ������
}Array;

status initarray(Array *a,int dim,...)		//��ά��dim�����ĸ�ά���ȺϷ���������Ӧ������a,������OK
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
	va_start(ap,dim);			//apΪva_list���ͣ��Ǵ�ű䳤��������Ϣ������
	for(i=0;i<dim;i++)
	{
		a->bounds[i]=va_arg(ap,int);
		if(a->bounds[i]<0)
			return ERROR;
		elemtotal*=a->bounds[i];		//��ά���Ϸ��������a->bounds�������a��Ԫ������elemtotal
	}
	va_end(ap);
	a->base=(elemtype *)malloc(elemtotal*sizeof(elemtype));
	if(!a->base)
		exit(OVERFLOW);
	//��ӳ�����ĳ���c��������a->constants[i-1],i=1,...,dim
	a->constants=(int *)malloc(dim*sizeof(int));
	a->constants[dim-1]=1;
	for(i=dim-2;i>=0;--i)
	{
		a->constants[i]=a->bounds[i+1]*a->constants[i+1];
	}
	return OK;
}

status destroyarray(Array *a)		//��������
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

status locate(Array a,va_list ap,int *off)		//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����a����Ե�ַoff
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

status value(Array a,elemtype *e,...)			//a��nά���飬eΪԪ�ر����������n���±�ֵ�������±�ֵ�����磬��ֵΪ��ָ����a��Ԫ��ֵ
{
	int result,off;
	va_list ap;
	va_start(ap,*e);
	if((result=locate(a,ap,&off))<=0)
		return result;
	*e=*(a.base+off);
	return OK;
}

status assign(Array *a,elemtype e,...)			//���±겻���磬��e��ֵ������ָ����a��Ԫ��
{
	int result,off;
	va_list ap;
	va_start(ap,e);
	if((result=locate(*a,ap,&off))<=0)
		return result;
	*(a->base+off)=e;
	return OK;
}