#pragma once

//����λ��������������ƽ��ֵ
int AverageForTwoNumber(int a,int b)
{
	return ((a&b) + ((a^b) >> 1));
}

//���ͣ�a��b�Ľ���ǣ�a��b�Ķ�������ͬλ������ͬ��ֵ����Ľ�����Ǳ���
//       Ҳ������������ֵͬ��ƽ��ֵ��

void Test()
{
	cout << AverageForTwoNumber(2,4)<< endl;  //3
	cout << AverageForTwoNumber(3,5)<< endl;  //4
}