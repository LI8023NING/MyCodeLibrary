#include <iostream>  
using namespace std;

class A
{
public:
	A(void)
	{}

	/*void func(void)
	{
		cout << "���Ƿ�const" << endl;
	}*/


	void func(void) const
	{
		cout << "����const" << endl;
	}
};

int main()
{
	//const�������const��Ա����   
	const A obj;
	obj.func();

	//const�������const��Ա����   

	A obj_const;
	obj_const.func();

	return 0;
}