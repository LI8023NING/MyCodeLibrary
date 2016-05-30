#pragma once

#include<iostream>
using namespace std;

//��������Ƿ�����
enum PointerTag
{
	THREAD,  //0
	LINK     //1
};

//�����������Ľڵ�ṹ
template<class T>
struct BinaryTreeNodeThd
{
	// ����
	//����
	//�Һ���
	//����������־
	T _data;
	BinaryTreeNodeThd<T> *_left;
	BinaryTreeNodeThd<T> *_right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	//��ʼ��
	BinaryTreeNodeThd(const T& data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)  //LINK˵����������� 
		, _rightTag(LINK) //THERD˵������Ϊ���ϵ�����
	{}
};

//����������
template<class T>
class BinaryTreeThd
{
public:
	//�������������������飩
	BinaryTreeThd(T *array, size_t size);
	
	//����
	~BinaryTreeThd()
	{}

	//��������������
	void InOrdThreading();

	//�������
	void InOderThd();

	//ǰ������������
	void PrevOrderThreading();

	//ǰ�����
	void PrevOrderThd();

	//��������������
	void PostOrderThreading();

	//�������
	void PostOrderThd();

protected:

	//��������
	void _InOrderThreading(BinaryTreeNodeThd<T>* cur, BinaryTreeNodeThd<T>*& prev)
	{
		if (cur == NULL) //��Ϊ��
		{
			return;
		}

		_InOrderThreading(cur->_left,prev); //Ψһ���þ���cur������

		//��߿յĻ�����������  
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		//��Ϊ�� ���� 
		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;

		_InOrderThreading(cur->_right, prev);
	}

	//ǰ������
	void _PrevOrderThreading(BinaryTreeNodeThd<T>* cur, BinaryTreeNodeThd<T>*& prev)
	{
		if (cur == NULL)
			return;

		if (cur->_left == NULL)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}

		prev = cur;

		if (cur->_leftTag == LINK)
			_PrevOrderThreading(cur->_left, prev);

		if (cur->_rightTag == LINK)
			_PrevOrderThreading(cur->_right, prev);
	}

	//��������
	void _PostOrderThreading(BinaryTreeNodeThd<T>* cur,BinaryTreeNodeThd<T>* prev)
	{
		if (cur == NULL)
		{
			return;
		}

		_PostOrderThreading(cur->_left, prev);
		_PostOrderThreading(cur->_right, prev);

		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}

		if (prev && prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}

		prev = cur;
	}

protected:
	BinaryTreeNodeThd<T>* _CreateTree(const T *array,size_t size,size_t& index)
	{
		BinaryTreeNodeThd<T> *root = nullptr;
		if (index < size && array[index] != '#')
		{
			root = new BinaryTreeNodeThd<T>(array[index]);
			root->_left = _CreateTree(array,size,++index);
			root->_right = _CreateTree(array,size,++index);
		}
		else
		{
			return NULL;
		}
		
		return root;
	}
protected:
	BinaryTreeNodeThd<T> *_root;
};

//������
template<class T>
BinaryTreeThd<T>::BinaryTreeThd(T *array, size_t size)
{
	size_t index = 0;
	_root = _CreateTree(array, size, index);
}

//�������
template<class T>
void BinaryTreeThd<T>::InOderThd()
{
	BinaryTreeNodeThd<T> *cur = _root;
	while (cur)
	{
		//�����������Ҫ������ߵĽڵ�
		while (cur && cur->_leftTag == LINK) //��������Ӳ�������
		{
			cur = cur->_left;
		}

		cout << cur->_data << "  "; //����ڵ�

		//�����������ĺ�̽ڵ�
		while (cur->_rightTag == THREAD)
		{
			cur = cur->_right;
			cout << cur->_data << "  ";
		}

		//ת���ұ���
		cur = cur->_right;
	}
}

//ǰ�����
void PrevOrderThd()
{
	BinaryTreeNodeThd<T>* cur = _root;
	while (cur)
	{
		while (cur && cur->_leftTag == LINK)
		{
			cout << cur->_data << " ";
			cur = cur->_left;
		}
		cout << cur->_data << " ";

		cur = cur->_right;

		/*	while(cur && cur->_rightTag == THREAD)
		{
		cur = cur->_right;
		cout<<cur->_data<<" ";
		}

		if(cur->_leftTag == LINK)
		cur = cur->_left;
		else
		cur = cur->_right;*/
	}

	cout << endl;
}

//��������
template<class T>
void BinaryTreeThd<T>::InOrdThreading()
{
	BinaryTreeNodeThd<T> *prev = NULL;
	_InOrderThreading(_root,prev);
}
