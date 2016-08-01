#include <iostream>  
using namespace std;

class A
{
public:
	A(void)
	{}

	/*void func(void)
	{
		cout << "我是非const" << endl;
	}*/


	void func(void) const
	{
		cout << "我是const" << endl;
	}
};

int main()
{
	//const对象调用const成员函数   
	const A obj;
	obj.func();

	//const对象调用const成员函数   

	A obj_const;
	obj_const.func();

	return 0;
}