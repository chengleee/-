// œ∞Ã‚3.10

void test(int &sum)
{
	int x;
	stack s;
	InitStack(s);
	scanf(x);
	while (x)
	{
		push(x, s);
		scanf(x);
	}
	sum = 0;
	printf(sum);
	while(!StackEmpty)
	{
		pop(s, &c);
		sum += c;
		printf(sum);
	}
	DestoryStack(s);
}
}