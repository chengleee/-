// 在中序线索二叉树中查找结点的前驱结点
// 算法思想：
// 利用线索二叉树中序遍历算法寻找

ThreadNode *FirstNode(ThreadNode *T){
    while(T->ltag == 0)
        T = T->lchild;
    return T;
}
ThreaNode *NextNode(ThreadNode *T){
    if(T->rtag == 1)
        return T->rchild;
    else
        return FirstNode(T->rchild);
}
ThreadNode InOder(ThreadNode *T, ThreadNode e){
    for(ThreadNode *p = FirsNode(T); NextNode(p) != e; p = NextNode(p));
    return p;
}

// 查找结点的后序前驱，即后序遍历序列中的前趋结点
BiThrTree InPostPre(BiThrTree t, BiThrTree p){
    BiThrTree q;
    if(p->rtag == 0)    // 若p有右子女，则右子女是其后序前驱
        q = p->rchild;
    else if(p->ltag == 0)   // 若p只有左子女，左子女是其后序前驱
        q = p->lchild;
    else if(p->lchild == NULL)  // p是中序序列上第一个结点，无后序前驱
        q = NULL;
    else{   // 顺左线索向上找p的祖先，若存在，再找祖先的左子女
        while(p->ltag == 1 && p->lchild != NULL)
            p = p->lchild;
        if(p->ltag == 0)
            q = p->lchild;
        else
            q = NULL; // 已找到根结点，无后序前趋
    }
    return q;
}
