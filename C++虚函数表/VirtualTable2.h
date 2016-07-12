#pragma once

//有虚函数覆盖的一般继承
//有覆盖是必然的，否则，虚函数将失去作用

class Base
{
public:  //三个虚函数
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

//一个覆盖 公有继承
class Derive :public Base
{
public:
	virtual void f() { cout << "Derive::f" << endl; }  //注意：这里函数覆盖了基类的相同函数；
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

void Test()
{
	Base B;
	B.f();

	Derive d; 
	Base *b = new Derive();
	b->g();
	b->f();  //调用的是子类中的f(); 实现多态的表现；
}
