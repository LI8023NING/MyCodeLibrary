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