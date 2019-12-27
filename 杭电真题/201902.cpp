/*
算法思想:
    先序遍历
*/
int Isomorphic(Tree R1, Tree R2)
{
    if ((R1 == Null) && (R2 == Null)){
        return 1;
    }

    //对应一个树存在某个节点，而另一个树没有该节点
    else if ((R1 == Null && R2 != Null) || (R2 == Null && R1 != Null)){
        return 0;
    }

    else if (T1[R1].Element != T2[R2].Element)
    {
        return 0;
    }

    else if (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right)) {
        return 1;
    }
    else if (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left)){
        return 1;
    }

    return  0;
}
