//��򵥵�visit����
//����ʵ��:PreOrderTraverse(T,PrintElement);
Status PrintElement(TElemType e)
//���e
{
	printf(e);
	return OK;
}

Status PreOrderTraverse(BiTree T,Status(* Visit)(TElemType e))
//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
{
	if(T)
	{
		if(Visit(T->data))
			if(PreOrderTraverse(T->lchild,Visit))
				if((PreOrderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}