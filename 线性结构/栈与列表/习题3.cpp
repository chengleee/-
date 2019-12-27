// 利用一个栈实现以下递归函数的非递归计算
#include <iostream>
using namespace std;

int P(int x, int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 2 * x;
    if(n > 1){
        int stack[50], top = -1, a, b, c, i;
        stack[++top] = 1;
        stack[++top] = 2 * x;
        for (i = 2; i <= n; i++){
            a = stack[top--];
            b = stack[top--];
            c = 2 * x * a - 2 *(i - 1) * b;
            stack[++top] = b;
            stack[++top] = c;
        }
        return stack[top];
    }
}

int main(){
    int x = 1, b;
    b = P(x, 4);
    cout << b << endl;
    return 0;
}
