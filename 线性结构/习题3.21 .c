// 习题3.21

Status RPN(char *c1, char *c2)
// 以#开头和结尾
// 将c1变成逆波兰式
{
	*c2 = '#';
	while (*c1)
	{
		if (!isNum(*c1))	// 是运算符
		{
			if (prior(*c1, getStack(S)))
			// 优先级*/ > +- > #
			// 优先级大于栈顶元素
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