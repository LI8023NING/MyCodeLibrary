#pragma once

void Prime()
{
	int k;
	int j;
	for (int i = 11; i <= 20; i = i + 2)
	{
		k = (int)sqrt(i);
		for (j = 2; j <= k; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}

		if (j >= k + 1)
		{
			cout << i << endl;
		}
	}
}

void Test()
{
	Prime();
}

//方案二
//1-100内的素数
void Prime()
{
	int i, j;
	int n;
	for (i = 1; i <= 100; i++)
	{
		for (j = 1, n = 0; j <= i; j++)
		{
			if (i%j == 0)
				n++;
		}
		if (n == 2)
		{
			printf("%d  ", i);
		}
	}
}