#pragma once

//�ڷ�Χ������
void CountSortBetMaxAndMin(int *a, int min, int max,int size)
{
	int gap = max - min + 1;
	int *temparray = new int[gap];
	memset(temparray,0,sizeof(int)*(gap+1));

	for (int count = 0; count < size; ++count)
	{
		temparray[a[count]]++;
	}


	//temparray��һ��
	int index = 0;
	for (int i = min; i < size; ++i)
	{
		while (temparray[i] != 0)
		{
			a[index++] = i;
			temparray[i]--;
		}
	}
}


//��������
void CountSort(int *a,int size)
{
	//��һ����Χ �����������Ԫ�ص�������Сֵ
	int max = a[0];  //���
	int min = a[0];  //��С

	for (int i = 1; i < size; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		else if (a[i] < min)
		{
			min = a[i];
		}
	}

	//�������Χ�м�������
	CountSortBetMaxAndMin(a, min, max,size);
}