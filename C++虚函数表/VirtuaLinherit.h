#pragma once

//钻石型多重虚拟继承
//但B类在D中还是有两个实例，这种继承造成了数据的重复，我们叫这种继承为重复继承。
//重复的基类数据成员可能并不是我们想要的。所以，C++引入了虚基类的概念。
//虚拟继承的出现就是为了解决重复继承中多个间接父类的问题的。
//钻石型的结构是其最经典的结构。也是我们在这里要讨论的结构： 
//上述的“重复继承”只需要把B1和B2继承B的语法中加上virtual 关键，就成了虚拟继承

class B
{
public:
	int ib;
	char cb;
public:
	B()
		:ib(0)
		, cb('B')
	{}

	virtual void f() { cout << "B::f()" << endl; }
	virtual void Bf() { cout << "B::Bf()" << endl; }
};

class B1 :virtual public B
{
public:
	int ib1;
	char cb1;
public:
	B1() :ib1(11), cb1('1') {}

	virtual void f() { cout << "B1::f()" << endl; }
	virtual void f1() { cout << "B1::f1()" << endl; }
	virtual void Bf1() { cout << "B1::Bf1()" << endl; }

};

class B2 :virtual public B
{
public:
	int ib2;
	char cb2;
public:
	B2() :ib2(12), cb2('2') {}

	virtual void f() { cout << "B2::f()" << endl; }
	virtual void f2() { cout << "B2::f2()" << endl; }
	virtual void Bf2() { cout << "B2::Bf2()" << endl; }

};

class D : public B1, public B2
{
public:
	int id;
	char cd;
public:
	D() :id(100), cd('D') {}

	virtual void f() { cout << "D::f()" << endl; }
	virtual void f1() { cout << "D::f1()" << endl; }
	virtual void f2() { cout << "D::f2()" << endl; }
	virtual void Df() { cout << "D::Df()" << endl; }
};

void Test()
{
	typedef void(*Fun)(void);
	int** pVtab = NULL;
	Fun pFun = NULL;

	B1 bb1;

	pVtab = (int**)&bb1;
	cout << "[0] B1::_vptr->" << endl;
	pFun = (Fun)pVtab[0][0];
	cout << "     [0] ";
	pFun(); //B1::f1();
	cout << "     [1] ";
	pFun = (Fun)pVtab[0][1];
	pFun(); //B1::bf1();
	cout << "     [2] ";
	cout << pVtab[0][2] << endl;

	cout << "[1] = 0x";
	cout << (int*)*((int*)(&bb1) + 1) << endl; //B1::ib1
	cout << "[2] B1::ib1 = ";
	cout << (int)*((int*)(&bb1) + 2) << endl; //B1::ib1
	cout << "[3] B1::cb1 = ";
	cout << (char)*((int*)(&bb1) + 3) << endl; //B1::cb1

	cout << "[4] = 0x";
	cout << (int*)*((int*)(&bb1) + 4) << endl; //NULL

	cout << "[5] B::_vptr->" << endl;
	pFun = (Fun)pVtab[5][0];
	cout << "     [0] ";
	pFun(); //B1::f();
	pFun = (Fun)pVtab[5][1];
	cout << "     [1] ";
	pFun(); //B::Bf();
	cout << "     [2] ";
	cout << "0x" << (Fun)pVtab[5][2] << endl;

	cout << "[6] B::ib = ";
	cout << (int)*((int*)(&bb1) + 6) << endl; //B::ib
	cout << "[7] B::cb = ";

}
