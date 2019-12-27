#include <stdio.h>

int fac(int n)    //Çón!
{   
    if(n == 0)
        return 0;
    int i,s = 1;
    for(i = 1;i <= n; ++i)
        s *= i;
    return s;
}
int climbStairs(int n) 
{
    int a,s = 1;
    for(a = 1;a < n/2; ++a)
        s += fac(n - a) / (fac(a) * fac(n - 2 * a));
    if(n % 2 == 0)
        return s + 1;
    else
        return s + n - n/2;
}

int main()
{
	int n = 20;
	printf("%d\n",climbStairs(n));
	return 0;
}