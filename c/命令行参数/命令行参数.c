#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void serror(int);
main(int argc,char *argv[]) 
{
    char opr;
	int error1,error2,error3;
	char strng[81];
	double result,first,second;
	if(argc<4) serror(1);
	first=atof(argv[1]);
	second=atof(argv[3]);
	strcpy(strng,argv[2]);
	opr=strng[0];
	if(opr!='+' && opr != '-' && opr != '*' && opr != '/')
		serror(2);
	if(opr == '/' && second == 0.0)  serror(3);
	switch(opr)
	{
	case '+':
		result = first + second;
		break;
	case '-':
		result = first - second;
		break;
	case '*':
		result = first * second;
		break;
	case '/':
		result = first / second;
		break;
	}
	printf("result=%lf\n\n",result);
}
void serror(int n)
{
	char *error[]={{"参数错误!"},{"运算错误!"},{"数据错!"}};
	printf("%s\n",error[n-1]);
	exit(1);
}