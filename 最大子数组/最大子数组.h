/************************************
 ** Auth: ����
 ** Date: 2016/9/5
 ** Desc: ��������飬�����±�
 ************************************/

#pragma once

bool MostBigSubArray(int *a, int size, int& BigSum,int& first, int& second)
{
	if (a == NULL || size < 0)
	{
		return false;
	}

	int CurSum = 0; //��ǰ�ĺ�
	int curfirst = 0;
	int cursecond = 0;

	for (int i = 0; i < size; ++i)
	{
		CurSum += a[i];
		cursecond = i;    

		//ֻҪ��С�����ˣ���ǰ�׺�β�ϲ�
		//��С���㣬��ôβһֱ�ں��ƶ�
		if (CurSum < 0)
		{
			CurSum = 0;
			curfirst = cursecond = i + 1;
		}

		//ֻҪ���ִ�� �͵ø���ǰ��ָ��
		if (CurSum > BigSum)
		{
			BigSum = CurSum;
			first = curfirst;
			second = cursecond;
		}
	}

	//û��������������� Ҳ�������������
	if (BigSum == 0)
	{
		BigSum = a[0];
		for (int i = 1; i < size; ++i)
		{
			if (a[i] > BigSum)
			{
				BigSum = a[i];
				first = second = i;
			}
		}
	}
	return true;
}

void Test()
{
	int a[] = {-2,-2,-2,-8,-9,-5,-1,-2,-4,-8};
	int BigSum = 0;
	int first = 0; 
	int second = 0;
	MostBigSubArray(a,10,BigSum,first,second);
	cout << BigSum << endl; 
	cout << "����Ϊ �� " << first << " �� " << second << endl;
}