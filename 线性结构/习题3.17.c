// ϰ��3.17
// �ж���@Ϊ��β���ַ����Ƿ���a+b&b+a��ʽ

bool isMode(char *a)
{
	stack s;
	initstack(s);
	int i = 0;
	while (a[i] != '&')
	{
		push(a[i], s);
		++i;
	}
	++i;
	while (a[i] != '@')
	{
		pop(s, e);
		if (a[i] != e)
			return false;
		i++;
	}
	return true;
}