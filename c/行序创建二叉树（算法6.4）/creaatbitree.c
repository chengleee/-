Status CreatBitree(Bitree &T)
//����������������н���ֵ���ո��ʾ����
//������������ʾ�Ķ�����
{
	scanf(&ch);
	if(ch==' ')
		T=NULL;
	else
	{
		if(!T=BiTNode *)malloc(sizeof(BiTNode)))
			exit(OVERFLOW);
		T->data=ch;						//���ɸ����
		CreatBitree(T->lchild);			//����������
		CreatBitree(T->rchild);			//����������
	}
	return OK;
}