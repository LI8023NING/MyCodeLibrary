#pragma once

//���ں궨���һЩע������

//1
#define SUB(x,y) x-y
#define ACCESS_BEFORE(element,offset,value) *SUB(&element,offset) =value

//Ԥ������������Ǿ��滻�� *&array[5]-4=6; �ȼ�����������Ч���
void Test()
{
	int i;
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	ACCESS_BEFORE(array[5], 4, 6);
	for (i = 0; i < 10; ++i)
	{
		printf("%d",array[i]);
	}
}

//2
#define UL unsigned long
#define SECOND_PER_YEAR UL(60*60*24*365) //UL��ʾ�޷��ų����� ����Ϊʲô�Ƿ��ں�ߣ�����ǰ�߲��Ǹ���˵���������

void Test()
{
	cout << SECOND_PER_YEAR << endl;
}

//3
//������С
#define MIN(a,b) ((a) <= (b)? (a):(b))



