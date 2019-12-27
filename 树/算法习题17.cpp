// 判断两棵二叉树是否相似
// 算法思想：
// 采用递归算法

bool similar(BiTree T1, BiTree T2){
    int left,right;
    if(!T1 && !T2)  // 两树都空
        return true;
    else if(!T1 || !T2) // 只有一树空
        return false;
    else{
        left = similar(T1->lchild, T2->lchild);
        right = similar(T1->rchild, T2->rchild);
        return left && right;
    }
}
