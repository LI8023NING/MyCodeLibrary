#include "stdio.h" 
#include "stdarg.h" 
void simple_va_fun(int start, ...)
{
	va_list  arg_ptr;
	int nArgValue = start;    //�ɱ������ֵ
	int nArgCout = 0;         //�ɱ��������Ŀ 

	va_start(arg_ptr, start); //�Թ̶������ĵ�ַ��start��Ϊ���ȷ����ε��ڴ���ʼ��ַ�� 
	do
	{
		++nArgCout;
		printf("the %d th arg: %d\n", nArgCout, nArgValue);  //�����������ֵ 
		nArgValue = va_arg(arg_ptr, int);                    //�õ���һ���ɱ������ֵ
	} while (nArgValue != -1);

	va_end(arg_ptr);
}

int main(int argc, char* argv[])
{
	simple_va_fun(100, 200, 12, 25, 56,-1);

	return 0;
}
