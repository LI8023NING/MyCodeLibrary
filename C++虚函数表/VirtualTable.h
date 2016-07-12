#pragma once

//C++中的虚函数的作用主要是实现了多态的机制

//通过Base的实例来得到虚函数表

class Base 
{
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

typedef void(*Fun)(void);
void Test()
{
	Base b;

	Fun pFun = NULL;

	cout << "虚函数表地址：" << (int*)(&b) << endl;
	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

	for (int i = 0; i < 3; ++i)   //分别输出三个函数
	{
		pFun = (Fun)*((int*)*(int*)(&b)+i);  //函数指针加一表示找下一个函数的地址
		pFun();
	}
}



