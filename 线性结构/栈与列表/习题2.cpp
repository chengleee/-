// 火车调度
// 算法思想:
// 用两个数组模拟入口与出口，软座车厢直接进入出口，硬座车厢先进栈，最后再进入出品

#include <iostream>
using namespace std;

void train_arrange(char *en, char *ex){
    char *p = en;
    int i = 0, top = -1;
    char stack[50]; 
    while(*p != '\0'){
        if(*p == 'S'){
            ex[i++] = *p;
        }
        if(*p == 'H'){
            stack[++top] = *p;
        }
        p++;
    }
    while(top != -1){
        ex[i++] = stack[top--];
    }
}

int main(){
    char train[10] = "HSSSSHHHH", ex[10];
    char *p = ex;
    train_arrange(train, ex);
    while(*p == 'H' || *p == 'S')
        cout << *p++;
    cout << endl;
    return 0;
}
