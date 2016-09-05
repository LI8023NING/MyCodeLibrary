/************************************
 ** Auth: 李宁
 ** Date: 2016/9/2
 ** Desc: 异常
/************************************/

#pragma once

#include<string>

//异常类
class A
{
public:
	A(string str)
		:_str(str)
	{
		cout << str << endl;
	}

	void T()
	{
		cout <<"捕获成功！" << endl;
	}

public:
	string _str;
};



void Test()
{
    int a = 0;
	try
	{
		try
		{
			if (a == 0)
			{
				throw int();
				throw A("dfsfsfsdfsfsfsffffffffffffffffffffffffff");
			}
		}
		catch (int)
		{
			cout << "lining " << endl;
		}
	}
	catch (A)
	{
		cout << "zhi shi lei xing" << endl;
		//s.T();
	}

	cout << "正常执行" << endl;
}