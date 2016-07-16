#pragma once

#include"MergerSort.h"
/*
*��������������һ�����������һ�����֣�Ҫ���ҳ���һ��������Ԫ�صĺ����������Ԫ���±�
*/

//����һ��
bool FindTwoNumberOfSum(int* a,int n,int Sum,int& left,int& right)
{
	if (a == NULL)
		return false;

	MergeSort(a,n);  //���ȹ鲢����

	while (left != right)
	{
		int tmp = a[left] + a[right];
		if (tmp < Sum)
			 ++left;
		else if (tmp > Sum)
			--right;
		else
			return true; //�ҵ���һ������������
	}
	return false;        //û�з���������Ԫ����������
}


//��������
bool FindTwoNumberOfSumSceond(int* a, int n, int Sum, int& left, int& right)
{
	bool flag = true;
	if (a == NULL)
		return false;

	int max = a[0];
	int min = a[0];
	//�������С����
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}

	int size = max - min + 1;

	//�����ռ�
	int *arr = new int[size]();

	for (int i = 0; i < size; ++i)
	{
		if (min <= (Sum - a[i]) && (Sum - a[i]) <= max)
		{
			arr[Sum - a[i]] = i;
		}
		else
			continue;  //�����ڷ�����������
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
	cout << "����������Ҫ��Ԫ�صĺ�:)" << endl;
	cin >> SumNumber;
	
	int a[10] = {3,5,9,1,6,3,7,8,0,2};
	bool flag = FindTwoNumberOfSum(a, 10, SumNumber, num1, num2);
	if (flag)
		cout << "��Ҫ��Ԫ���±�ֱ�Ϊ��" << num1 << "��" << num2 << endl;
	else
		cout << "û�з�������Ԫ��" << endl;
}


void Test2()
{
	int num1 = 0, num2 = 9;
	int SumNumber = 0;
	cout << "����������Ҫ��Ԫ�صĺ�:)" << endl;
	cin >> SumNumber;

	int a[10] = { 3, 5, 9, 1, 6, 3, 7, 8, 0, 2 };
	bool flag = FindTwoNumberOfSumSceond(a, 10, SumNumber, num1, num2);
	if (flag)
		cout << "��Ҫ��Ԫ���±�ֱ�Ϊ��" << num1 << "��" << num2 << endl;
	else
		cout << "û�з�������Ԫ��" << endl;
}

void Test()
{
	//Test1();
	Test2();
}