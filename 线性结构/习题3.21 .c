// ϰ��3.21

Status RPN(char *c1, char *c2)
// ��#��ͷ�ͽ�β
// ��c1����沨��ʽ
{
	*c2 = '#';
	while (*c1)
	{
		if (!isNum(*c1))	// �������
		{
			if (prior(*c1, getStack(S)))
			// ���ȼ�*/ > +- > #
			// ���ȼ�����ջ��Ԫ��
			{
				push(*c1, S);
				++c1;
			}
			else
			{
				pop(S, *(++c2));
				++c1;
			}
		}
		else
		{
			*(++c2) = *c1;
			c1++;
		}
	}
}