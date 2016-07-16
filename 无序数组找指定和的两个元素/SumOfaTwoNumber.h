#pragma once

#include"MergerSort.h"
/*
*��������������һ�����������һ�����֣�Ҫ���ҳ���һ��������Ԫ�صĺ����������Ԫ���±�
*/

//����һ��
bool FindTwoNumberOfSum(int* a,int n,int Sum,int& left,int& right)
{
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

void Test()
{
	Test1();
}