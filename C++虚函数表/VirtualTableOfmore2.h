#pragma once

//有虚函数覆盖的多重继承
#pragma once

//无覆盖，多重继承
class Base1
{
public:  //三个虚函数
	virtual void f() { cout << "Base1::f" << endl; }
	virtual void g() { cout << "Base1::g" << endl; }
	virtual void h() { cout << "Base1::h" << endl; }
};

class Base2
{
public:  //三个虚函数
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
	virtual void h() { cout << "Base2::h" << endl; }
};

class Base3
{
public:  //三个虚函数
	virtual void f() { cout << "Base3::f" << endl; }
	virtual void g() { cout << "Base3::g" << endl; }
	virtual void h() { cout << "Base3::h" << endl; }
};

//多重继承无覆盖
class Derive :public Base1, public Base2, public Base3
{
public:
	virtual void f() { cout << "Derive::f" << endl; }  //唯一一个覆盖的子类函数
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

void Test()
{
	Derive d;

	Base1 *b1 = &d;
	Base2 *b2 = &d;
	Base3 *b3 = &d;
	b1->f(); //Derive::f()
	b2->f(); //Derive::f()
	b3->f(); //Derive::f()

	b1->g(); //Base1::g()
	b2->g(); //Base2::g()
	b3->g(); //Base3::g()

}