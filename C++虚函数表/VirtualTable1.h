#pragma once

//一般继承（无虚函数覆盖）
class Base
{
public:  //三个虚函数
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

//无覆盖 公有继承
class Derive :public Base
{
public:
	virtual void f1() { cout << "Derive::f1" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

void Test()
{
	Derive d;   //继承之后，子类的虚函数表中，前边存放基类的虚函数，紧接着存子类的虚函数地址
}
