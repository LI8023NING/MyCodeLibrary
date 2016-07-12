#pragma once

//静态绑定：编译时绑定，通过对象调用
//动态绑定：运行时绑定，通过地址实现

//只有采用“指针->函数()”或“引用变量.函数()”的方式调用C++类中的虚函数才会执行动态绑定。
//对于C++中的非虚函数，因为其不具备动态绑定的特征，所以不管采用什么样的方式调用，都不会执行动态绑定。

class CBase
{
public:
	virtual int func() const    //虚函数
	{
		cout << "CBase function! ";
		return 100;
	}
};
class CDerive : public CBase
{
public:
	int func() const        //在派生类中重新定义虚函数
	{
		cout << "CDerive function! ";
		return 200;
	}
};

void Test()
{
	CDerive obj1;
	CBase* p1 = &obj1;
	CBase& p2 = obj1;
	CBase obj2;

	obj1.func();     //静态绑定：调用对象本身（派生类CDerive对象）的 func 函数
	p1->func();      //动态绑定：调用被引用对象所属类（派生类CDerive）的 func 函数
	p2.func();       //动态绑定：调用被引用对象所属类（派生类CDerive）的 func 函数
	obj2.func();     //静态绑定：调用对象本身（基类CBase对象）的函数
}
