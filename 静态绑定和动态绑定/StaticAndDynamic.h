#pragma once

//��̬�󶨣�����ʱ�󶨣�ͨ���������
//��̬�󶨣�����ʱ�󶨣�ͨ����ַʵ��

//ֻ�в��á�ָ��->����()�������ñ���.����()���ķ�ʽ����C++���е��麯���Ż�ִ�ж�̬�󶨡�
//����C++�еķ��麯������Ϊ�䲻�߱���̬�󶨵����������Բ��ܲ���ʲô���ķ�ʽ���ã�������ִ�ж�̬�󶨡�

class CBase
{
public:
	virtual int func() const    //�麯��
	{
		cout << "CBase function! ";
		return 100;
	}
};
class CDerive : public CBase
{
public:
	int func() const        //�������������¶����麯��
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

	obj1.func();     //��̬�󶨣����ö�����������CDerive���󣩵� func ����
	p1->func();      //��̬�󶨣����ñ����ö��������ࣨ������CDerive���� func ����
	p2.func();       //��̬�󶨣����ñ����ö��������ࣨ������CDerive���� func ����
	obj2.func();     //��̬�󶨣����ö���������CBase���󣩵ĺ���
}
