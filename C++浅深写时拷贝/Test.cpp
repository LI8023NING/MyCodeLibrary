#include <iostream>
#include <assert.h>
using namespace std;


namespace A
{
	////////////////////////////////////
	// 浅拷贝 
	/////////////////////////////////////

	class String
	{
	public:
		String(const char* str)
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str,str);
		}

		String(const String& str)
			:_str(str._str)
		{}

		String& operator=(const String& str)
		{
			if(this != &str)
			{
				_str = str._str;
			}
		}
		
		~String()
		{
			if(_str)
			{
				delete[] _str;
			}
		}

	private:
		char* _str;
	};


	void Test()
	{
		// 浅拷贝问题就是两个指针指向了同一块内存;
		String s1("li ning yi qie jie you ke neng");
		String s2 = s1;
		//析构时崩溃
	}

	int main()
	{
		Test();
		return 0;
	}
}

//深拷贝
namespace B
{
	/////////////////////////////////////////
	//面试中的string这样写
	//////////////////////////////////////////
#include<iostream>
#include<string.h>
	using namespace std;

	class String
	{
	public:
		String()
			:_data(new char[1])
		{
			*_data = '\0';
		}

		String(const char* str)
			:_data(new char[strlen(str) + 1])
		{
			strcpy(_data, str);
		}

		String(const String& str)
			:_data(new char[str.size() + 1])
		{
			strcpy(_data, str.c_str());
		}

		~String()
		{
			delete[] _data;
		}

		// Traditional:
		/*String& operator=(const String& str)
		{
		string tmp(str._data);
		swap(tmp._data);
		return *this;
		}*/
		String& operator=(const &String str) //value
		{
			swap(str);
			return *this;
		}

		size_t size() const
		{
			return strlen(_data);
		}

		const char* c_str() const
		{
			return _data;
		}

		void swap(String& str)
		{
			std::swap(_data, str._data);
		}
	private:
		char* _data;
	};

	void Test()
	{
		string str;
		str.append(1, 'f');
		cout << str << endl;
	}

	int main()
	{
		Test();
		return 0;
	}
}


namespace C
{
	//class String
	//{
	//public:
	//	String(const char* str)
	//		:_str(new char[strlen(str) + 1])
	//		,_pCount(new int(1))
	//	{
	//		strcpy(_str, str);
	//	}

	//	String(String& s)
	//		:_str(s._str)
	//		,_pCount(s._pCount)
	//	{
	//		++(*_pCount);
	//	}

	//	String& operator=(const String& s)
	//	{
	//		if (_str != s._str)
	//		{
	//			// 释放原对象
	//			if (--(*_pCount) == 0)
	//			{
	//				delete _pCount;
	//				delete[] _str;
	//			}

	//			// 浅拷贝并增加引用计数
	//			_str = s._str;
	//			_pCount = s._pCount;
	//			++(*_pCount);
	//		}

	//		return *this;
	//	}

	//	~String()
	//	{
	//		if (--(*_pCount) == 0)
	//		{
	//			cout<<"delete[] _str"<<endl;
	//			delete _pCount;
	//			delete[] _str;
	//		}
	//	}

	//private:
	//	char* _str;
	//	//static int _count;

	//	int* _pCount;
	//};

	class String
	{
	public:
		String(const char* str)
			:_str(new char[strlen(str) + 5])
		{
			_str += 4;
			strcpy(_str, str);

			_GetRefCount(_str) = 1;
		}

		String(const String& s)
			:_str(s._str)
		{
			++_GetRefCount(_str);
		}

		String& operator=(const String& s)
		{
			if (_str != s._str)
			{
				_Release();

				_str = s._str;
				++_GetRefCount(_str);
			}

			return *this;
		}

		~String()
		{
			_Release();
		}

		// Insert
		// Find

		char& operator[](size_t pos)//String* this
		{
			// 当引用计数大于1，需要完成写时拷贝
			if (_GetRefCount(_str) > 1)
			{
				char* tmp = new char[strlen(_str) + 5];
				tmp += 4;
				strcpy(tmp, _str);
				_GetRefCount(tmp) = 1;

				--_GetRefCount(_str);
				_str = tmp;
			}

			return _str[pos];
		}

		//const String* this
		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		int Find(const String& s)
		{
			cout << "Find(const String& s)" << endl;
			return -1;
		}

	private:
		int& _GetRefCount(char* _ptr)
		{
			return *((int*)(_ptr - 4));
		}

		void _Release()
		{
			if (--_GetRefCount(_str) == 0)
			{
				delete[](_str - 4);
			}
		}

	private:
		char* _str;
	};

	//int String::_count = 0;

	// Copy On Write

	void Test1()
	{
		String s1("1111111111111111111111");
		String s2(s1);

		//// 读时也拷贝
		//cout<<s1[0]<<endl;

		//// 写时拷贝
		//s1[0] = 'x';

		s1.Find("xxxx");
		s1.Find(s2);
	}
}

void Test5()
{
	int begin = GetTickCount();

	COW::String s1("1111111111111111111111111111111111111111");
	for (int i = 0; i < 1000000; ++i)
	{
		COW::String s2(s1);
		// cout<<s2<<endl;
		//...
	}

	int end = GetTickCount();

	cout << end - begin << endl;
}

#include <string>

int main()
{

	COW::Test1();
	//Test5();

	//string s1("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	//string s2(s1);

	//printf("%x, %x", s1.c_str(), s2.c_str());

	return 0;
}