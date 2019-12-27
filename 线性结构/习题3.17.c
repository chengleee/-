// 习题3.17
// 判断以@为结尾的字符串是否如a+b&b+a格式

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