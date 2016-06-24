//template <class T>
//struct Type
//{
//	typedef T ValueType;   // ��Ƕ�ͱ�  ����Ҫ��ȡ�����Ͱ���
//	T* _ptr;
//
//	Type(T * ptr = 0)
//		: _ptr(ptr)
//	{}
//
//	T& operator *() const
//	{
//		return *_ptr;
//	}
//};
//
//template <class I>
//typename I::ValueType fun(const I& x)
//{
//	return *x; //����*������ ����ֵ�����;���T����
//}
//
//void Test()
//{
//	int num = 10;
//	Type<int > x(&num);
//	cout << fun(x) << endl;
//}

//��POD������ȡ��
//
// POD: plain old data ƽ�����ͣ��޹�ʹ�������ͣ�
// ָ��C++ ���� C���ݵ����ͣ����԰��� C �ķ�ʽ����
//

struct __TrueType
{
	bool Get()
	{
		return true;
	}
};

struct __FalseType
{
	bool Get()
	{
		return false;
	}
};

template <class _Tp>
struct TypeTraits
{
	typedef __FalseType   __IsPODType;
};

template <>
struct TypeTraits< bool>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< char>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< unsigned char >
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< short>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< unsigned short >
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< int>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< unsigned int >
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< long>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< unsigned long >
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< long long >
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< unsigned long long>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< float>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< double>
{
	typedef __TrueType     __IsPODType;
};

template <>
struct TypeTraits< long double >
{
	typedef __TrueType     __IsPODType;
};

template <class _Tp>
struct TypeTraits< _Tp*>
{
	typedef __TrueType     __IsPODType;
};

//
// ʹ�ò����Ƶ�����ȡ����
//
template <class T>
void Copy(const T* src, T* dst, size_t size, __FalseType)  //���ͽ���ʵ����������
{
	cout << "__FalseType:" << typeid(T).name() << endl;
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}

template <class T>
void Copy(const T* src, T* dst, size_t size, __TrueType)
{
	cout << "__TrueType:" << typeid(T).name() << endl;
	memcpy(dst, src, size*sizeof (T));
}

//
// ʹ����ȡ�ж����͵�Get�����ж��Ƿ��� POD����������
//
template <class T>
void Copy(const T* src, T* dst, size_t size)
{
	cout << "__TrueType:" << typeid(T).name() << endl;

	if (TypeTraits <T>::__IsPODType().Get())  //����T����
	{
		memcpy(dst, src, size*sizeof (T));
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}


void Test1()
{
	//string s1[10] = { "1", "2", "3", "4444444444444444444444444" };
	//string s2[10] = { "11", "22", "33" };
	//Copy(s1, s2, 10, TypeTraits <string>::__IsPODType());  //ʵ���������󣬵�ʵ�δ���
	//Copy(s1, s2, 10);

	int a1[10] = { 1, 2, 3 };
	int a2[10] = { 0 };
	Copy(a1, a2, 10, TypeTraits <int>::__IsPODType());
	Copy(a1, a2, 10);
}