#pragma once

#include<iostream>
#include<vector>
//using namespace std;  //尽量不要让 using出现在头文件中 


template<class T>
class Heap
{
public:
	//构造
	Heap();

	//建大堆
	Heap(const T* a,size_t size);

	//堆排序
	void HeapSort();
	
	//建堆副
	void _Heap(const T* a,size_t size);

	//虚向下调整 实向上走
	void AdjustDown(int index,int num);

	void AdjustUp(int index);

	//打印
	void Print();

private:
	vector<T> MinHeap;
};

template<class T>
Heap<T>::Heap()
	{}

template<class T>
Heap<T>::Heap(const T* a,size_t size)
{
	_Heap(a,size);
}

template<class T>
void Heap<T>::_Heap(const T *a, size_t size)
{
	for(int i = 0; i < size; i++)
	{
		MinHeap.push_back(a[i]);
	}
	
	//第一个非叶子结点开始
	for(int i = (MinHeap.size()-2)/2; i >= 0; i--)
	{
		AdjustUp(i);
	}
}

template<class T>
void Heap<T>::AdjustDown(int index,int num)
{
	int child = 2*index+1;
	int cout = num+1;
	while(child < MinHeap.size()-cout)
	{
		if(child+1 <MinHeap.size()-cout && MinHeap[child] < MinHeap[child+1])
		{
			child++;
		}

		if(MinHeap[child] > MinHeap[(child-1)/2])
		{
			swap(MinHeap[child],MinHeap[(child-1)/2]);
			index = child; //交换后的是不是打乱了顺序  继续
			child = 2*index+1;//等效循环外的第一个条件
		}
		else
		{
			break;	
		}
	}
}

template<class T>
void Heap<T>::AdjustUp(int index)
{
	int child = index*2 + 1;
	while(child < MinHeap.size())
	{
		if((child+1)< MinHeap.size() && MinHeap[child+1] > MinHeap[child])
		{
			child++;
		}

		if(MinHeap[child] > MinHeap[(child-1)/2])
		{
			swap(MinHeap[child],MinHeap[(child-1)/2]);
			index = child;
			child = 2*index+1;
		}
		else
		{
			break;
		}
	}
}

template<class T>
void Heap<T>::HeapSort()
{
	for(int i = 0; i < MinHeap.size(); i++)
	{
		int num = MinHeap.size()-i-1;
		swap(MinHeap[0],MinHeap[num]);
		AdjustDown(0,i);
	}
}

template<class T>
void Heap<T>::Print()
{
	for(int i = 0; i < MinHeap.size();i++)
	{
		cout<<MinHeap[i]<<" ";
	}
	cout<<endl;
}