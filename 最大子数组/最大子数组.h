/************************************
 ** Auth: 李宁
 ** Date: 2016/9/5
 ** Desc: 最大子数组，返回下标
 ************************************/

#pragma once

bool MostBigSubArray(int *a, int size, int& BigSum,int& first, int& second)
{
	if (a == NULL || size < 0)
	{
		return false;
	}

	int CurSum = 0; //当前的和
	int curfirst = 0;
	int cursecond = 0;

	for (int i = 0; i < size; ++i)
	{
		CurSum += a[i];
		cursecond = i;    

		//只要和小于零了，当前首和尾合并
		//不小于零，那么尾一直在后移动
		if (CurSum < 0)
		{
			CurSum = 0;
			curfirst = cursecond = i + 1;
		}

		//只要出现大和 就得更新前后指针
		if (CurSum > BigSum)
		{
			BigSum = CurSum;
			first = curfirst;
			second = cursecond;
		}
	}

	//没有最大子数组的情况 也处理负数最大的情况
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
	cout << "区间为 ： " << first << " 到 " << second << endl;
}