#include <iostream>
#include <assert.h>
using namespace std;


namespace A
{
	////////////////////////////////////
	// ǳ���� 
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
		// ǳ���������������ָ��ָ����ͬһ���ڴ�;
		String s1("li ning yi qie jie you ke neng");
		String s2 = s1;
		//����ʱ����
	}

	int main()
	{
		Test();
		return 0;
	}
}