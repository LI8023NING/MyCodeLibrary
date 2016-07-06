#pragma once

//利用位运算求两个数的平均值
int AverageForTwoNumber(int a,int b)
{
	return ((a&b) + ((a^b) >> 1));
}

//解释：a与b的结果是：a和b的二进制相同位，有相同的值，与的结果就是本身
//   也可以是两个相同值的平均值，a^b的结果：即不同为1，相当相加，右移1，相当除二；

void Test()
{
	cout << AverageForTwoNumber(2,4)<< endl;  //3
	cout << AverageForTwoNumber(2,5)<< endl;  //4
}