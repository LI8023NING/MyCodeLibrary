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