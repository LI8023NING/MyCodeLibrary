#pragma once

//���麯�����ǵ�һ��̳�
//�и����Ǳ�Ȼ�ģ������麯����ʧȥ����

class Base
{
public:  //�����麯��
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};

//һ������ ���м̳�
class Derive :public Base
{
public:
	virtual void f() { cout << "Derive::f" << endl; }  //ע�⣺���ﺯ�������˻������ͬ������
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
	b->f();  //���õ��������е�f(); ʵ�ֶ�̬�ı��֣�
}
