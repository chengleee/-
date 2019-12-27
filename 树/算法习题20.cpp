// 将二叉树转化为中缀表达式
// 算法思想：
// 中序遍历输出所有结点
typedef struct node{
    char data[10]; // 存储操作数或操作符
    struct node *left,*right;
}BTree;

void BTreeToExp(BTree *T){
    BTreeToE(T,1);
}

void BTreeToE(BTree *T, int deep){
    if(T==NULL)
        return;
    else if(T->left == NULL && T->right == NULL)
        printf("%s",T->data); //叶结点输出操作数
    else{
        if(deep > 1) // 非叶结点，为操作符，深度大于1时加一层括号
            printf("(");
        BTreeToE(T->left,deep+1);
        printf("s",T->data); // 输出操作符
        BTreeToE(T->right,deep+1);
        if(deep > 1)
            printf(")");
    }
}
