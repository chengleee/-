// 算法习题6
// 根据先序及中序遍历序列创建二叉树
// 算法思想：
// 在先序序列中第一个为根结点
// 在中序序列中找到根结点，根结点左方全为左子树的结点，右方全为右子树的结点
// 利用递归即可创建二叉树

typedef struct BiNode{
    ElemType data;
    struct BiNode *lchild,*rchild;
}*BiTree,BiTNode;

// fir1、fir2分别为A和B的第一个结点下标，end1、end2分别为A、B最后一个结点的下标
BiTree PreInCreat(ElemType A[],B[],fir1,end1,fir2,end2){
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = A[fir1];
    for(i = fir2; B[i] != A[fir1]; ++i); // 在B中寻找根结点
    len1 = i - fir2; // 左子树长度
    len2 = end2 - i; // 右子树长度
    if(len1)
        root->lchild = PreInCreat(A,B,fir1 + 1, fir1 + len1, fir2, i - 1);
    else
        root->lchild = NULL;
    if(len2)
        root->rchild = PreInCreat(A,B,end1 - len2 + 1, end1, end2 - len2 + 1, end2);
    else
        root->rchild = NULL;
    return root;
}
