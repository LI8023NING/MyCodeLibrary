#pragma once

//һ��̳У����麯�����ǣ�
class Base
{
public:  //�����麯��
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

//�޸��� ���м̳�
class Derive :public Base
{
public:
	virtual void f1() { cout << "Derive::f1" << endl; }
	virtual void g1() { cout << "Derive::g1" << endl; }
	virtual void h1() { cout << "Derive::h1" << endl; }
};

void Test()
{
	Derive d;   //�̳�֮��������麯�����У�ǰ�ߴ�Ż�����麯���������Ŵ�������麯����ַ
}
