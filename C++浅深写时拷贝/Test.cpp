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

//���
namespace B
{
	/////////////////////////////////////////
	//�����е�string����д
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