#pragma once

#include"MergerSort.h"
/*
*问题描述：给定一个无序数组和一个数字，要求找出第一个，两个元素的和是这个数的元素下标
*/

//方案一：
bool FindTwoNumberOfSum(int* a,int n,int Sum,int& left,int& right)
{
	if (a == NULL)
		return false;

	MergeSort(a,n);  //首先归并排序

	while (left != right)
	{
		int tmp = a[left] + a[right];
		if (tmp < Sum)
			 ++left;
		else if (tmp > Sum)
			--right;
		else
			return true; //找到第一个符合条件的
	}
	return false;        //没有符合条件的元素在数组中
}


//方案二：
bool FindTwoNumberOfSumSceond(int* a, int n, int Sum, int& left, int& right)
{
	bool flag = true;
	if (a == NULL)
		return false;

	int max = a[0];
	int min = a[0];
	//找最大最小数：
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}

	int size = max - min + 1;

	//辅助空间
	int *arr = new int[size]();

	for (int i = 0; i < size; ++i)
	{
		if (min <= (Sum - a[i]) && (Sum - a[i]) <= max)
		{
			arr[Sum - a[i]] = i;
		}
		else
			continue;  //不存在符合条件的数
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[a[i]] != 0)
		{
			left = arr[a[i]];
			right = i;
			if (left == right)
			{
				continue;
			}
			flag = true;
			break;
		}
		else
			continue;
	}

	return flag;
}

void Test1()
{
	int num1 = 0, num2 = 9;
	int SumNumber = 0;
	cout << "请输入你需要找元素的和:)" << endl;
	cin >> SumNumber;
	
	int a[10] = {3,5,9,1,6,3,7,8,0,2};
	bool flag = FindTwoNumberOfSum(a, 10, SumNumber, num1, num2);
	if (flag)
		cout << "你要的元素下标分别为：" << num1 << "和" << num2 << endl;
	else
		cout << "没有符条件的元素" << endl;
}


void Test2()
{
	int num1 = 0, num2 = 9;
	int SumNumber = 0;
	cout << "请输入你需要找元素的和:)" << endl;
	cin >> SumNumber;

	int a[10] = { 3, 5, 9, 1, 6, 3, 7, 8, 0, 2 };
	bool flag = FindTwoNumberOfSumSceond(a, 10, SumNumber, num1, num2);
	if (flag)
		cout << "你要的元素下标分别为：" << num1 << "和" << num2 << endl;
	else
		cout << "没有符条件的元素" << endl;
}

void Test()
{
	//Test1();
	Test2();
}