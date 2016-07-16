#pragma once

//�ϲ����������
void MergeSection(int *a, int *tmp, int begin1, int end1, int begin2, int end2)
{
	int index = 0;
	while (begin1 <= end1 && begin2 <= end2)   //�����Ӽ��ϲ�
	{
		if (a[begin1] <= a[begin2])      //��С�ķ���index = 0��λ�� �Դ�����
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	//���ټ������������

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
}

//�鲢����
void _MergeSort(int *a, int *tmp, int left,int right)
{
	assert(a);

	if (left >= right)
	{
		return;
	}
	
	int mid = left + (right - left) / 2;

 	_MergeSort(a, tmp,left,mid);
	_MergeSort(a, tmp, mid+1,right );

	MergeSection(a,tmp,left,mid,mid+1,right);
	 

	for (int i = 0; i < (right - left + 1); ++i)
	{
		a[left+i] = tmp[i];
	}
}

void MergeSort(int *a, int size)
{
	int *tmp = new int[size];  //�൱�ڵ��������� �����ϲ�
	memset(tmp,0,sizeof(int)*size);
	_MergeSort(a, tmp, 0, size - 1);
	delete[] tmp;
}