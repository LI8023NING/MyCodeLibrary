#pragma once

//C++�е��麯����������Ҫ��ʵ���˶�̬�Ļ���

//ͨ��Base��ʵ�����õ��麯����

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

	cout << "�麯�����ַ��" << (int*)(&b) << endl;
	cout << "�麯���� �� ��һ��������ַ��" << (int*)*(int*)(&b) << endl;

	for (int i = 0; i < 3; ++i)   //�ֱ������������
	{
		pFun = (Fun)*((int*)*(int*)(&b)+i);  //����ָ���һ��ʾ����һ�������ĵ�ַ
		pFun();
	}
}



