#pragma once

//�޸��ǣ����ؼ̳�
class Base1
{
public:  //�����麯��
	virtual void f() { cout << "Base1::f" << endl; }
	virtual void g() { cout << "Base1::g" << endl; }
	virtual void h() { cout << "Base1::h" << endl; }
};

class Base2
{
public:  //�����麯��
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
	virtual void h() { cout << "Base2::h" << endl; }
};

class Base3
{
public:  //�����麯��
	virtual void f() { cout << "Base3::f" << endl; }
	virtual void g() { cout << "Base3::g" << endl; }
	virtual void h() { cout << "Base3::h" << endl; }
};

//���ؼ̳��޸���
class Derive :public Base1 , public Base2 , public Base3 
{
public:
	virtual void f1() { cout << "Derive::f1" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

void Test()
{
	Derive d;
}