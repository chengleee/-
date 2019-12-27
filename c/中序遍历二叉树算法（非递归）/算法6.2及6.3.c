Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e))
	//�������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
{
	InitStack(S);
	Push(S,T);					//��ָ����ջ
	while(!StackEmpty(S))
	{
		while(GetTop(S,p)&&p)
			Push(S,p->lchild);	//�����ߵ���ͷ
		Pop(S,p);				//��ָ����ջ
		if(!StackEmpty(S))		//���ʽ�㣬������һ��
		{
			Pop(S,p);
			if(!Visit(p->data))
				return ERROR;
			Push(S,p->rchild);
		}
	}
	return OK;
}

//��һ��������������ķǵݹ��㷨
Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType e))
{
	InitStack(S);
	p=T;
	while(p||!StackEmpty(S))
	{
		if(p)					//��ָ���ջ������������
		{
			Push(S,p);
			p=p->lchild;
		}
		else					//��ָ����ջ�����ʸ���㣬����������
		{
			Pop(S,p);
			if(!Visit(p->data))
				return ERROR;
			p=p->rchild;
		}
	}
	return OK:
}