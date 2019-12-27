// 二叉树的带权路径长度WPL是二叉树中所有叶结点的带权路径长度之和。求WPL
// 算法思想：
// 先序遍历树，遇到叶结点更新WPL值

typedef struct BiTNode{
    int weight;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
int wpl = 0;
int WPL(BiTree root){
    return wpl_PreOrder(root, 0);
}

int wpl_PreOrder(BiTree root, int deep){
    if(root->left == NULL && root->right == NULL)
        wpl += deep * root->weight;
    if(root->left)
        wpl_PreOrder(root->left,deep+1);
    if(root->right)
        wpl_PreOrder(root->right,deep+1);
    return wpl;
}
