/************************************
 ** Auth: 李宁
 ** Date: 2016/9/2
 ** Desc: 排序
 ************************************/

#pragma once

class RAII
{
public:
	RAII(int size)
		:tmp(new int[size])
	{
		memset(tmp,0,size*sizeof(int));
	}

	~RAII()
	{
		if (tmp)
		{
			delete[] tmp;
			tmp = NULL;
		}
	}

	int& operator[](int a)
	{
		return tmp[a];
	}

public:
	int *tmp;
};

void Count(int *a,int size)
{
	//1.找到最大和最小
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < size; ++i)
	{
		if (max <= a[i])
			max = a[i];
		else if (min > a[i])
			min = a[i];
	}

	//2.根据最大最小开辟需要的空间
	//int *tmp = new int[max - min + 1]();

	RAII tmp(max-min+1);

	//3.统计
	for (int i = 0; i < size; ++i)
	{
		tmp[a[i]-min]++;
	}

	//4.返回
	int j = 0;
	for (int i = 0; i < max-min+1; ++i)
	{
		while (tmp[i] >= 1)
		{
			a[j++] = i+min;
			tmp[i]--;
		}
	}
}

void Test()
{
	int a[] = { 3, 5, 6, 4, 5, 8, 9, 10, 2, 12, 15 };
	int size = sizeof(a) / sizeof(int);
	Count(a, size);
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << "->";
	}
	cout << endl;
}