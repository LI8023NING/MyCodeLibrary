//#include<iostream>
//using namespace std;
//
//
//char charTwo(char* str)
//{
//	if (str == NULL)
//	{
//		return '0';
//	}
//
//	char *pstr = str;
//	char a[256] = { 0 };
//	while (*pstr++ != '\0')
//	{
//		a[*pstr]++;
//	}
//
//	pstr = str;
//	while (*pstr != '\0')
//	{
//		if (a[*pstr] == 2)
//		{
//			return *pstr;
//		}
//		pstr++;
//	}
//}
//
//
//int main()
//{
//	char* str = NULL;
//	cout << charTwo(str) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num = 12345;
//	char string[7] = {0};
//
//	itoa(num,string,10);
//	printf("integer = %d string = %s\n",num,string);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//char* strcpy_my(char *strDest, const char* strSrc)
//{
//	char *res = strDest;
//	while ((*strDest++ = *strSrc++) != '\0')
//	{
//		;
//	}
//	return res;
//}
//int main()
//{
//	const volatile int i = 0;
//	char a[] = "asdfdgfgfdgfkhfgklfdgfdg";
//	char *b = "123456789";
//	strcpy_my(a,b);
//	printf("%s %d\n",a,i);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//
//template<typename T>
//class Foo {
//public:
//	void print();
//	//...其他操作 
//private:
//	static int i;
//};
//
//template<typename T>
//void Foo<T>::print()
//{
//	cout << ++i << endl;
//}
//
//template<typename T>
//int Foo<T>::i = 10; // 初始化为10 
//
//int main()
//{
//	Foo<int> f1;
//	Foo<int> f2;
//	Foo<int> f4;
//	Foo<float> f3;   //类型不同  实例出来的实例也不同  在此是两个
//	Foo<float> f5;
//	f1.print();  // 输出11 
//	f2.print();  // 输出12 
//	f4.print();  // 输出11 
//	f3.print();  // 输出11
//	f5.print();
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//struct Comper
//{
//	bool operator()(int& a, int &b)
//	{
//		return a < b;
//	}
//}Comper;
//
//
//int main()
//{
//	//Comper Comper;
//	int a = 10;
//	int b = 20;
//
//	cout << sizeof(Comper) << endl;
//
//	if (Comper(a,b))
//	{
//		cout << "仿函数结果为真" << endl;
//	}
//	else
//	{
//		cout << "仿函数返回为假的" << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<class T>
//class Less
//{
//public:
//	bool operator()(const T& left, const T& right)
//	{
//		return left < right;
//	}
//};
//
//template<class T, class Compare = Less>
//class  A
//{
//public:
//	A()
//		:a(0)
//		,b(0)
//	{}
//
//	bool Is(T& a, T& b)
//	{
//		return Compare()(a, b);
//	}
//
//	
//
//public:
//	T a;
//	T b;
//};
//
//int main()
//{
//	A<int,Less<int>> s1;
//	s1.a = 20;
//	s1.b = 10;
//
//	int a = 10;
//	int b = 20;
//
//	if (s1.Is(a, b))
//	{
//		cout << "仿函数结果为真" << endl;
//	}
//	else
//	{
//		cout << "仿函数返回为假的" << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//void SelectSort(int *a, int size)
//{
//	int j = 0;
//	for (int i = 0; i < size - 1; ++i)
//	{
//		int minIndex = i;
//		for (j = i + 1; j < size; ++j)
//		{
//			if (a[minIndex] > a[j])
//				minIndex = j;
//		}
//
//		if (minIndex != i)
//		{
//			swap(a[minIndex],a[i]);
//		}
//	}
//}
//
//int main()
//{
//	int a[] = {2,3,4,5,8,0,1,9};
//	SelectSort(a,8);
//	for (int i = 0; i < 8; ++i)
//	{
//		printf("%d->", a[i]);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//};
//
//class B
//{
//public:
//	A b;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void Test(char *b)
//{
//	cout << *b << endl;
//}
//
//
//int main()
//{
//	const char *b = "fdsfsdfs";
//
//	char *a = const_cast<char*>(b);
// 
//	Test(a);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class B
//{
//public:
//	virtual void  print()
//	{
//		cout << " fsdkfjsdlkjflsfjslfjslflfslfslfsllsfls" << endl;
//	}
//};
//
//class A :public B
//{
//public:
//	void print()
//	{
//		cout << " fdfljsdlfjsdlfjslf" << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	B b = a;
//	b.print();
//	return 0;
//}

//#include<stdio.h>  
//#include<stdarg.h>  
//
//int test(int num, ...)
//{
//	int i, result = 0;
//
//	va_list ap;//这里写的什么list，（搞得好像是得到可变参数列表头一样）其实它就是个字符指针:char *   
//	va_start(ap, num);// 这里把上面得到的字符指针，后移动4个字节，就是跳过num的内存地址  
//	printf("num:%d,*ap:%d\n", num ,*ap);// 这里打印下就会看出，*ap 跳过了num指向了下一个参数  
//	     
//	for (i = 0; i < num; i++)//这里num表示可变参数列表中有多少个参数（num本身算不算，由自己觉得，这里是不算入参数个数的）  
//	{
//		result = va_arg(ap, int);//这里把ap往后跳过4个字节（sizeof(int)大小）指向下一个参数，返回的是当前参数（而非下一个参数）  
//		printf("in for  result:%d,  *ap:%d\n", result, *ap);//这里打印下，可以看出，ap总是指向result后面的那个参数  
//	}
//	va_end(ap);//结束标志  
//
//	return result;
//}
////下面是测试函数  
//int main()
//{
//	int i = 4, j = 1, k = 2, g = 3, z = 4, m = 1;
//	printf("result:%d\n", test(i, j, k, g, z, m));
//	return 0;
//}

//#include <iostream>
//#include <iomanip>//不要忘记包含此头文件
//using namespace std;
//int main()
//{
//	int a;
//	cout << "input a:";
//	cin >> a;
//	cout << "dec:" << dec << a << endl;  //以十进制形式输出整数
//	cout << "hex:" << hex << a << endl;  //以十六进制形式输出整数a
//	cout << "oct:" << setbase(8) << a << endl;  //以八进制形式输出整数a
//	char *pt = "China";  //pt指向字符串"China"
//	cout << setw(10) << pt << endl;  //指0域宽为,输出字符串
//	cout << setfill('*') << setw(10) << pt << endl;  //指定域宽,输出字符串,空白处以'*'填充
//	double pi = 22.0 / 7.0;  //计算pi值
//	//按指数形式输出,8位小数
//	cout << setiosflags(ios::scientific) << setprecision(8);
//	cout << "pi=" << pi << endl;  //输出pi值
//	cout << "pi=" << setprecision(4) << pi << endl;  //改为位小数
//	cout << "pi=" << setiosflags(ios::fixed) << pi << endl;  //改为小数形式输出
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 10, int b = 20)
//		:_a(a)
//		, _b(b)
//	{}
//private:
//	int _a;
//	int _b;
//};

//// 全缺省参数
//int Add1(int a = 0, int b = 0)
//{
//	return a + b;
//}
//
//// 半缺省参数
//int Add2(int a, int b = 0)
//{
//	return a + b;
//}
//
//void Test()
//{
//	Add1();
//	Add1(1);
//	Add1(1, 1);
//	Add2(2);
//	Add2(2, 2);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//void Test1()
//{
//	int a = 1;
//	int& b = a;
//
//	cout << "a:address->" << &a << endl;
//	cout << "b:address->" << &b << endl;
//
//	a = 2;
//	b = 3;
//	int& c = b;  // 引用一个引用变量，别名的别名
//	c = 4;
//}
//
//
//void Test2()
//{
//	//int d1 = 4;
//	//const int & d2 = d1;
//
//	//d1 = 5;          // d1改变 d2的值也会改变。
//	////d2 = 6;        // 不能给常量（不能被修改的量）赋值
//
//	//const int d3 = 1;
//	//const int & d4 = d3;
//
//	////int&d5 = d3;
//
//	//const int & d6 = 5;  // 常量具有常性，只有常引用可以引用常量
//
//	//double d7 = 1.1;
//
//	////int& d8 = d7; //d7是double类型，d8是int，d7赋值给 d8时要生成一个临时变量
//	//// 也就是说d7引用的是这个带有常性的临时变量，所以不能赋值。
//
//	//const int& d9 = d7;
//
//	char *p = "fdsdflkjkjasfj";
//	int h = 1;
//	int& b = h;
//	cout << p++ << endl;
//	//cout << h++ << endl;
//	cout << b++ << endl;
//}
//
//
//
//int& Add(int d1, int d2)
//	// int Add ( int d1 , int d2)
//{
//	int ret;
//	ret = d1 + d2;
//	return ret;
//}
//
//void Test3()
//{
//
//	int a = 3, b = 4;
//	int& c = Add(a, b);
//	*((int*)0x00CFFA68) = 100;
//	cout << "c:" << c << endl;
//}
//
//
//void Swap(int& l, int& r)
//{
//	int temp = l;
//	l = r;
//	r = temp;
//}
//
//void Test4()
//{
//	int* p = 0;
//	int& a = *p;
//	int b = 2;
//	Swap(a, b);
//}
//
//int main()
//{
//	//Test1();
//	//Test2();
//	//Test3();
//	Test4();
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string a{ "fdsfjlkfslf;kds;kfdskfld" };
//	for (auto x : a)
//	{
//		cout << x << endl;
//	}
//
//	std::vector<std::string> str_vec = { "i", "like", "google"};  
//	for (auto& it : str_vec) {
//		it ="c++";
//	}
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//bool FindNum(int a[][4], int num)
//{
//	if (a == NULL || num < 0)
//		return false;
//
//	int i = 3;
//	int j = 0;
//	
//	while (j < 4 && i > -1)
//	{
//		int base = a[i][j];
//		if (num > base)
//			++j;
//		else if (num < base)
//			--i;
//		else
//			return true;
//	}
//	return false;
//}
//
//
//int main()
//{
//	int a[4][4] = 
//	{
//		{1,2,8,9},
//		{2,4,9,12},
//		{4,7,10,13}, 
//		{6,8,11,15} 
//	};
//
//	cout << FindNum(a, 12) << endl;;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//
//	/*void print()
//	{
//		cout << "非 const print()" << endl;
//	}
//*/
//	void print() const
//	{
//		cout << "const print()" << endl;
//	}
//
//
//	void Display()
//	{
//		cout << "非const" << endl;
//		print();
//
//	}
//
//	/*void Display() const
//	{
//		cout << "const" << endl;
//		print();
//	}*/
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//
//void Test()
//{
//	Date d1;
//	d1.Display();
//
//	//const Date d2;
//	//d2.Display();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date ()" << endl;
//		++sCount;
//	}
//
//	void Ptinr()
//	{
//
//	}
//
//	// 静态成员函数
//	static void PrintCount()
//	{
//		cout << "Date count:" << sCount << endl;
//		Ptinr();
//		
//	}
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//private:
//	static int sCount; // 静态成员变量，统计创建时间个数
//};
//
//
//// 定义并初始化静态成员变量
//int Date::sCount = 0;
//void Test()
//{
//	Date d1, d2;
//	// 访问静态成员
//	Date::PrintCount();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//
//
//#include<stdio.h>
//
//int main()
//{
//	int m;
//	int n;
//	scanf("%d %d", &m, &n);
//	int g = 0;
//	int s = 0;
//	int b = 0;
//	int flag = 0;
//	for (int i = m; i <= n; ++i)
//	{
//		g = i % 10;
//		s = (i / 10) % 10;
//		b = i / 100;
//
//		int num = g*g*g + b*b*b + s*s*s;
//
//		if (num == i)
//		{
//			flag = 1;
//			printf("%d ", i);
//		}
//	}
//	if (!flag)
//	{
//		printf("no");
//	}
//	return 0;
//}

//#define CRTDBG_MAP_ALLOC 
//#include <stdlib.h>    
//#include <crtdbg.h>    
//int main()
//{
//	int *p = new int[10]();
//	_CrtDumpMemoryLeaks();
//	delete p;
//
//	
//	p = nullptr;
//	return 0;
//}
//
//class Base
//{
//public:
//	Base()
//	{}
//
//	int print()
//	{
//		return a;
//	}
//
//protected:
//	int a;
//};
//
//int main()
//{
//	Base b;
//	b.print();
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string a;
//	int N;
//	cin >> N;
//
//	int left = -90;
//	int right = 90;
//
//	while (a.size() != 6)
//	{
//		int mid = left + (right - left) / 2;
//
//		if (N > mid)
//		{
//			left = mid;
//			a += '1';
//		}
//		else if (N < mid)
//		{
//			right = mid - 1;
//			a += '0';
//		}
//		else
//			break;
//	}
//
//	cout << a.c_str() << endl;
//	return 0;
//}

//素数对
//input：7  两个素数的和 是输入

//#include<iostream>
//#include<math.h>
//using namespace std;
//
//bool IsPrimer(int n)
//{
//	if (n < 2)
//		return false;
//
//	for (int j = 2; j <= sqrt(n); ++j)
//	{
//		if (!(n%j))
//			return false;
//	}
//	return true;
//}
//
//void Primer(int n)
//{
//	int count = 0;
//	for (int i = 2; i <= n; ++i)
//	{
//		if (IsPrimer(i))
//		{
//			for (int j = 2; j <= n; j++)
//			{
//				if (IsPrimer(j) && (i + j) == n)
//				{
//					cout << i << " + " << j << " = " << n << endl;
//					count++;
//				}
//			}
//		}
//	}
//	cout << "合计：" << count / 2 << " 对 " << endl;;
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//	Primer(N);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int HuiWen(string str)
//{
//	int count = 0;
//	int left = 0;
//	int right = str.length() - 1;
//	int mid = left + (right - left)/2;
//
//	int i = mid;
//	int j = mid;
//
//	while (j - i != str.length()-1)
//	{
//		if (str[i--] == str[j++])
//			count++;
//		else
//		{
//			break;
//		}
//	}
//	return count-1;
//}
//
//int main()
//{
//	string a;
//	cin >> a;
//	int num = HuiWen(a);
//	cout << num << endl;
//	return 0;
//}
//
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> Primer(int m, int n)
//{
//	vector<int> a;
//	
//
//	for (int i = m; i <= n; i++)
//	{
//		int num = 0;
//		for (int j = 1; j <= i; j++)
//		{
//			if (i%j == 0)
//				num++;
//		}
//
//		if (num == 2)
//		{
//			a.push_back(i);
//		}
//	}
//	return a;
//}
//
//
//int Sum(vector<int>& a)
//{
//	int count = 0;
//
//	vector<int> c1 = Primer(a[0], a[1]);
//	vector<int> c2 = Primer(a[1], a[2]);
//	vector<int> c3 = Primer(a[0], a[2]);
//
//	count = c1.size() + c2.size() + c3.size();
//	 
//	return count;
//}
//
//int main()
//{
//	int a;  //个数
//	int b;
//	vector<int> v;
//	cin >> a;
//	for (int i = 0; i < a; ++i)
//	{
//		cin >> b;
//		v.push_back(b);
//	}
//	int num =Sum(v);
//	cout << num << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class B
//{
//public:
//	B()
//		:b(0)
//	{
//		cout << "我是B构造" << endl;
//	}
//
//	~B()
//	{
//		cout << "我是B析构" << endl;
//	}
//
//private:
//	int b;
//};
//
//
//class Base
//{
//public:
//	Base()
//		:b(0)
//	{
//		cout << "我是Base(父类) 构造" << endl;
//	}
//
//	~Base()
//	{
//		cout << "我是Base(父类) 析构" << endl;
//	}
//
//private:
//	int b;
//};
//
//class Drice:public Base
//{
//public:
//	Drice()
//		:d(0)
//	{
//		cout << "我是Drice(子类) 构造" << endl;
//	}
//
//	~Drice()
//	{
//		cout << "我是Drice(子类) 析构" << endl;
//	}
//
//
//
//private:
//	int d;
//	B D;
//	Base e;
//};
//
//
//int main()
//{
//	Drice a;
//	//printf("123"+1);
//	//Base d;
//	return 0;
//}

////字符转16进制
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
////10->16
//string DecToHex(int a)
//{
//	string ret;
//
//	while (a != 0)
//	{
//		ret.push_back(a%16);
//		a /= 16;
//	}
//	reverse(ret.begin(), ret.end());
//
//	for (int i = 0; i < ret.size(); ++i)
//	{
//		switch (ret[i])
//		{
//		case 10:ret += 'A';
//			break;
//		case 11:ret += 'B';
//			break;
//		case 12:ret += 'C';
//			break;
//		case 13:ret += 'D';
//			break;
//		case 14:ret += 'E';
//			break;
//		case 15:ret += 'F';
//			break;
//		default:break;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	char *str = "12456";
//	int i = 0;
//	int a = 0;
//	a = atoi(str);
//	string ret = DecToHex(a);
//	for (int i = 0; i < ret.size(); ++i)
//	{
//		cout << ret[i]<< " ";
//	}
//	cout << endl;
//	return 0;
//}

//
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int i = 0;
//	int n;
//	string b;
//	vector<int> a;
//	while ((n = getchar()) != '\n')
//	{
//		while (n != '\n' && n != ',')
//		{
//			b+=n;
//		}
//
//		a.push_back(atoi(b.c_str()) - 48);
//	}
//	
//	int max = a[0];
//	int min = a[0];
//
//	for (int i = 1; i < a.size(); i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//		}
//
//		if (min > a[i])
//		{
//			min = a[i];
//		}
//	}
//
//	cout << max - min << endl;
//	return 0;
//}

//#include<stdio.h>
//
//#include<assert.h>
//int BinarySearch(int *a, int x,int size)
//{
//	int left = 0;
//	int right = size;
//	assert(a);
//
//	while (left < right)
//	{
//		int mid = left + (right - left) / 2;
//		if (a[mid] < x)
//		{
//			left = mid + 1;
//		}
//		else if (a[mid] > x)
//		{
//			right = mid;
//		}
//		else
//		{
//			return a[mid];
//		}
//	}
//
//	return -1;
//}
//
//int main()
//{
//	int a;
//	int b;
//	int c[100];
//	int p;
//	scanf("%d",&a);
//	scanf("%d", &b);
//	for (int i = 0; i < b; i++)
//	{ 
//		scanf("%d",&p);
//		c[i] = p;
//	}
//
//	int num = BinarySearch(c, a, b);
//	printf("%d\n",num);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char *str[] = {"LINING","SHIHAO","AQI","AHAO"};
//	for (int i = 0; i < sizeof(str) / sizeof(char*); i++) //str数组中装的是char*
//	{
//		cout << str[i] << endl;
//	}
//
//	cout <<endl;
//
//	cout << *(str+1) << endl;
//
//	cout << endl;
//	char *q = *str;
//	cout << *(++q) << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char a[10];
//	memset(a,'1',10);
//
//	int b[10];
//	memset(b,1,10);  //以字节为单位，这里瞎了
//	return 0;
//
//}

////去除所有的给定字符
//#include<stdio.h>
//
//void delChar(char *str, char c) {
//	int i, j = 0;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] != c)
//		{
//			str[j] = str[i];
//			j++;
//		}
//	}
//	str[j] = '\0';
//}
//
//int main()
//{
//	char str[] = "abcdefgh"; // 注意，此处不能写成char *str = "abcdefgh";
//	printf("%s\n", str);
//	delChar(str, 'c');
//	printf("%s\n", str);
//}

//int jiecheng(int a)
//{
//	int ret = 1;
//	for (int i = 1; i <= a; i++)
//	{
//		ret = ret*i;
//	}
//	return ret;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//vector<int> jiecheng(int n)
//{
//	vector<int> ret;
//	ret.push_back(1);
//	for (int i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (auto& it : ret)
//		{
//			int pro = it * i + j;
//			it = pro % 1000;
//			j = pro / 1000;
//		}
//		if (j > 0)
//		{
//			ret.push_back(j);
//		}
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int a;
//	cin >> a;
//	vector<int> num = jiecheng(a);
//
//	int count = 0;
//	for (int i = 0; i < num.size(); i++)
//	{
//		while (num[i] % 10 == 0)
//		{
//			count++;
//			num[i] = num[i] / 10;
//		}
//		if (count < 3)
//		{
//			break;
//		}
//	}
//
//	cout << count << endl;
//	return 0;
//}

//#include<iostream>
//#include<stack>
//#include<assert.h>
//using namespace std;
//
////获取迷宫数字
//void GetMazeMap(int* a, int row, int col)
//{
//	FILE* fOut = fopen("Map.txt", "r"); //只读的方式打开
//	assert(fOut);
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col;)
//		{
//			char ch = fgetc(fOut);
//			if (ch == '0' || ch == '1')
//			{
//				a[i*col + j] = ch - '0';//将所有的字符 转换为数字 col由外部传来
//				j++;
//			}
//		}
//	}
//	fclose(fOut);
//}
//
////打印迷宫
//void PrintMaze(int* a, int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cout << a[i*col + j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//struct pos//入口
//{
//	int row;
//	int col;
//};
//
////检查迷宫是否有入口
//bool CheckIsAccess(int* a, int rowSize, int colSize, pos cur)
//{
//	if (cur.row < rowSize && cur.col < colSize
//		&&cur.row >= 0 && cur.col >= 0
//		&& a[cur.row * colSize + cur.col] == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//stack<pos> GetMazePath(int* a, int rowSize, int colSize, pos entry)
//{
//	stack<pos> paths;
//	pos cur = entry; //入口坐标付给 cur；
//	paths.push(entry); //入口坐标入栈
//
//	while (!paths.empty())  //如果栈不为空
//	{
//		pos cur = paths.top();//cur 指向栈顶坐标；
//		pos next = cur;
//
//		if (next.row == rowSize - 1)
//		{
//			return paths;
//		}
//
//		/************************************************
//		//每个左边的上下左右均判断，如果通路 坐标入栈，如果
//		//不同就放弃
//		//
//		//***********************************************/
//		//坐标左
//		next = cur;
//		if (next.col == entry.col && next.row == entry.row)
//		{
//			a[next.row * colSize + next.col] = 2;
//		}
//		next.col--; //此处可能将列减成负的了 之后判断
//		if (CheckIsAccess(a, 10, 10, next))
//		{
//			a[next.row * colSize + next.col] = 2;
//			paths.push(next);
//			continue;
//		}
//
//		// 右
//		next = cur;
//		next.col++;
//		if (CheckIsAccess(a, 10, 10, next))
//		{
//			a[next.row * colSize + next.col] = 2;
//			cur = next;
//			paths.push(next);
//			continue;
//		}
//
//		// 上
//		next.row--;
//		if (CheckIsAccess(a, 10, 10, next))
//		{
//			a[next.row * colSize + next.col] = 2;
//			paths.push(next);
//			continue;
//		}
//
//		// 下
//		next = cur;
//		next.row++;
//		if (CheckIsAccess(a, 10, 10, next))
//		{
//			a[next.row * colSize + next.col] = 2;
//			paths.push(next);
//			continue;
//		}
//
//		pos top = paths.top();
//		a[top.row* colSize + top.col] = 3;
//		paths.pop();
//	}
//
//	cout << "没有" << endl;
//	return paths;
//}
//
//
//void Test()
//{
//	int a[10][10] = {};
//	GetMazeMap((int*)a, 10, 10);
//	PrintMaze((int*)a, 10, 10);
//
//	pos entry = { 2, 0 };  //入口是 第三行 第零列
//	GetMazePath((int*)a, 10, 10, entry);
//	PrintMaze((int*)a, 10, 10);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//#include <stdio.h>  
//
//int total;
//int pre[1001];
//
//void init(int n){
//	int i;
//
//	for (i = 1; i <= n; ++i){
//		pre[i] = i;
//	}
//}
//
//int root(int x){
//
//	if (x != pre[x]){
//		pre[x] = root(pre[x]);
//	}
//	return pre[x];
//}
//
//void merge(int a, int b){
//
//	int x = root(a);
//	int y = root(b);
//	if (x != y){
//		pre[x] = y;
//		--total;
//	}
//}
//
//int main()
//{
//	int N, M, i, st, end;
//	while (scanf("%d", &N) && N){
//
//		scanf("%d", &M);
//
//		init(N);
//
//		total = N - 1;
//
//		for (i = 0; i<M; ++i){
//			scanf("%d %d", &st, &end);
//			merge(st, end);
//		}
//		printf("%d\n", total);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//int n1 = scanf("%d",&n1);
//	int n1;
//    cin >> n1;
//	int n = printf("lining\n\n");
//	cout << n << endl;
//	cout << n1 << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Get(int n)
//{
//	n = n < 0 ? -n : n;
//	if (n == 0)
//	{
//		return 0;
//	} 
//
//	else
//	{
//		int step = 1;
//		int length = 1;
//		int sum = 1;
//		int ds = 0;
//		while (sum <= n)
//		{
//			if (sum == n)
//				return step;
//			else if (sum < n)
//			{
//				if (sum + length + 1 > n)
//				{
//					ds = (sum + length + 1 - n) > (n - sum) ? (n - sum) : (sum + length + 1 - n);
//					return step + 2 * ds;
//				}
//				else
//				{
//					++step;
//					++length;
//					sum += length;
//				}
//			}
//		}
//		return step;
//	}
//}
//int main()
//{
//	int a;
//	vector<int> b;
//	int i = 0;
//	while (~scanf("%d", &a))
//	{
//		b.push_back(a);
//	}
//
//	for (int j = 0; j < b.size(); j++)
//	{
//		printf("%d\n", Get(b[j]));
//	}
//	
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	//int i = 5;
//	//printf("%d",i+++++i);
//	char *a[] = {"ab","cde"};
//	char **p = a;
//
//	printf("%c",*(*(a+1)+1));
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<queue>
//#include<stack>
//#include<list>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string a1;
//	queue<int> a2;
//	stack<int> a3;
//	list<int > a4;
//	vector<long long> a0;
//	a0.push_back(1);
//	
//	cout << sizeof(a0) << endl;
//	cout << sizeof(a1) << endl;
//	cout << sizeof(a2) << endl;
//	cout << sizeof(a3) << endl;
//	cout << sizeof(a4) << endl;
//	return 0;
//}




//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct pos
//{
//	int left;
//	int right;
//};
//
//vector<pos> FindPath(pos& start, pos& end)
//{
//	vector<pos> position;
//	int n = 0;
//	for (int i = start.left; i <= end.left; i += 1)
//	{
//		int j;
//		for (j = start.right; j <= end.right; j += 2)
//		{
//			position[n].left = i;
//			position[n].right = j;
//			n++;
//		}
//
//		if (j != end.right)
//		{
//			for (j = j-2; j <= end.right; j += 1)
//			{
//				for (int p = i; p <= end.left; i += 2)
//				{
//					position[n].left = i;
//					position[n].right = j;
//					n++;
//				}	
//			}
//		}
//	}
//	return position;
//}
//
//
//int main()
//{
//	pos start;
//	pos end;
//	int p,q;
//	int p1, q1;
//	cin >> p >> q;
//	start.left = p;
//	start.right = q;
//	cin >> p1 >> q1;
//	end.left = p1;
//	end.right = q1;
//	vector<pos> path = FindPath(start, end);
//	for (int i = 0; i < path.size(); i++)
//	{
//		cout << "(" << path[i].left << "," << path[i].right << ")" << endl;
//	}
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//using namespace std;
//
////是否进位
//bool Is(char *number)
//{
//	bool overfloat = false;
//	int takeover = 0;  //进位
//	int length = strlen(number);
//	
//	// 3 : 2 1 0
//	for (int i = length - 1; i >= 0; i--)
//	{
//		int sum = number[i] - '0' + takeover;
//		if (i == length - 1)
//		{
//			sum++;
//		}
//
//		if (sum >= 10)
//		{
//			if (i == 0)
//			{
//				//最后一位不在进位
//				overfloat = true;
//			}
//			else
//			{
//				sum -= 10;
//				number[i] = sum + '0';
//				takeover = 1;
//			}
//		}
//		else
//		{
//			number[i] = sum + '0';
//			break;
//		}
//	}
//	return overfloat;
//}
//
//void print(char *number)
//{
//	bool is = true;
//	int len = strlen(number);
//
//	for (int i = 0; i < len; i++)
//	{
//		if (is && number[i] != '0')
//			is = false;   //巧的很  只有第一个 0 不打印；
//
//		if (!is)
//		{
//			printf("%c",number[i]);
//		}
//	}
//	cout << ",";
//}
//
//
//void Prin(int n)
//{
//	if (n < 0)
//	{
//		return;
//	}
//
//	char *number = new char[n + 1];
//	memset(number,'0',n);
//	number[n] = '\0';
//
//	while (!Is(number))
//	{
//		print(number);
//	}
//
//	delete[] number;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	Prin(n);
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//int main()
//{
//	string s;
//	string p;
//	
//	while (getline(cin,p))
//	{
//		s += p;
//		s += '\n';
//	}
//
//	int size = s.size();
//
//	
//	string n;
//	
//		stack<string> t;
//		int i;
//		for (i = 0; i < size; i++)
//		{
//			if (s[i] == ' ')
//			{
//				t.push(n);
//				n.clear();
//			}
//			else if (s[i] == '\n')
//			{
//				t.push(n);
//				n.clear();
//
//				while (!t.empty())
//				{
//					cout << t.top()<<" ";
//					t.pop();
//				}
//				cout << endl;
//			}
//			else
//			{
//				n += s[i];
//			}
//		}
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//int main()
//{
//	//int n;
//	//cin >> n; //节点个数
//	//string s;
//	//for (int i = 0; i < n - 1; i++)
//	//{
//	//	getline(cin,s);
//	//	s += '\n';
//	//}
//
//	int a[10] = {0};
//	cout << sizeof(a) << endl;
//	cout << sizeof(&a[1]) << endl;
//
//
//	return 0;
//}

//循环数组右移
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char a[20];
//	int n;
//	cin >> a;
//	int len = strlen(a);
//	cin >> n;
//	int j = len - 1;
//	
//	for (int i = 0; i < n; i++)
//	{
//		int k = j - 1;
//		char tmp = a[j];
//		while (k >= 0)
//		{
//			a[k + 1] = a[k];
//			k--;
//		}
//		a[0] = tmp;
//	}
//
//	cout << a << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//
//void FindMax(string& a, int n)
//{
//	string::const_iterator it;
//	string::const_iterator it1;
//	string::const_iterator it2;
//	char m = a[0];
//	if (n == 1)
//	{
//		for (it = a.begin(); it != a.end(); ++it)
//		{
//			if (*it < m)
//				m = *it;
//		}
//
//		for (it = a.begin(); it != a.end(); ++it)
//		{
//			if (*it == m)
//			{
//				a.erase(it);
//				return;
//			}	
//		}
//	}
//
//	char max = a[0];
//	//找到最大的值
//	for (it = a.begin(); it != a.end(); ++it)
//	{
//		if (*it > max)
//			max = *it;
//	}
//
//	int count = 0;
//	char min = a[0];
//
//	while (count != n)
//	{
//		for (it1 = a.begin(); *it1 != max; ++it1)
//		{
//			if (*it1 < min)
//			{
//				min = *it1;
//			}
//		}
//
//		for (it2 = a.begin(); *it2 != max; ++it2)
//		{
//			if (*it2 == min)
//			{
//				it2 = a.erase(it2);
//				count++;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int n = 0;b 
//	string str;
//	cin >> str;
//	cin >> n;
//
//	FindMax(str, n);
//	cout << str << endl;
//		
//	return 0;
//}

//#include<iostream>
//#include<array>
//using namespace std;
//
//enum strin
//{
//	a = 18446744,
//}v;
//
//int main()
//{
//	//array<int, 20> a;
//	//array<int, 20>::iterator it = a.begin();
//	//
//	//cout << a.size() << endl;
//	//cout << a.max_size() << endl;
//
//	//cout << endl;
//
//	//a.fill(1);  //指的是全部填充
//
//	//for (int i = 0; i < a.size(); i++)
//	//{
//	//	a[i] = i;
//	//	cout << a[i] << endl;
//	//}
//
//	//cout << endl;
//
//	//for (; it != a.end(); it++)
//	//{
//	//	cout << *it << endl;
//	//}
//
//	//cout << a.back() << endl;
//	//cout << a.front() << endl;
//
//	cout << v << endl;
//	cout << sizeof(v) << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//struct a
//{
//	char g;  //821蹦
//	//int h;   //823蹦
//}b;
//
//int main()
//{
//	int *p = (int*)&b;
//
//	for (int i = 200; i <= 824; i++)
//	{
//		p[i] = i;
//		cout << p[i] << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//struct b
//{
//	int a;
//};
//
//int main()
//{
//	cout<<sizeof(b) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main(int argc,char* argv[])
//{
//	char *s = "abcdefg";
//	s += 2;
//	fprintf(stderr, "%s\n", s);
//	return 0;
//}

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
////非递归二分查找
//int binary_search(int *a, int size, int tar)
//{
//	int left = 0;
//	int right = size;
//	while (left < right)
//	{
//		int mid = left + (right - left) / 2;
//		if (a[mid] > tar)
//		{
//			right = mid;
//		}
//		else if (a[mid] < tar)
//		{
//			left = mid+1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int a[2] = { 0 };
//	for (int i = 0; i < 2; i++)
//	{
//		cin >> a[i];
//	}
//
//	int *p = new int[a[0]];
//	for (int i = 0; i < a[0]; i++)
//	{
//		cin >> p[i];
//	}
//
//	int position = binary_search(p, a[0], a[1]);
//	cout << position << endl;
//
//	delete[] p;
//	return 0;
//}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool Is(int a)
//{
//	return (a&(a - 1));
//}
//
//int main()
//{
//	int n;
//	vector<int> p;
//	while (cin >> n)
//	{
//		p.push_back(n);
//	}
//
//	for (int i = 0; i < p.size(); i++)
//	{
//		bool flag = Is(p[i]);
//		if (flag)
//		{
//			cout << "false" << endl;
//		}
//		else
//		{
//			cout << "true" << endl;
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Is(vector<int>& p)
//{
//	int size = p.size();
//	int num = size - 1;  //酒店个数
//
//	int money = p[size - 1]; //我有的钱
//	int count = 0;
//	int sum = 0;
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (p[i] <= money)
//		{
//			sum += p[i];
//			count++;
//		}
//	}
//
//	if (count == 0)
//	{
//		return -1;
//	}
//	else
//	{
//		return count;
//	}
//}
//
//int main()
//{
//	int n;
//	vector<int> p;
//	while (cin >> n)
//	{
//		p.push_back(n);
//	}
//
//	int n1 = Is(p);
//	cout << n1 << endl;
//	
//	return 0;
//}

#include<iostream>
using namespace std;

int main()
{

	return 0;
}



























//去掉一个数，留下数最大
//双向链表的逆置
//蛇形打印二叉树





