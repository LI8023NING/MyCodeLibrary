#pragma once

//关于宏定义的一些注意事项

//1
#define SUB(x,y) x-y
#define ACCESS_BEFORE(element,offset,value) *SUB(&element,offset) =value

//预处理器将宏的那句替换成 *&array[5]-4=6; 先减，减返回无效结果
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
#define SECOND_PER_YEAR UL(60*60*24*365) //UL表示无符号长整型 但是为什么是放在后边，放在前边不是更能说的清楚摸？

void Test()
{
	cout << SECOND_PER_YEAR << endl;
}

//3
//返回最小
#define MIN(a,b) ((a) <= (b)? (a):(b))



