#pragma once

//ÿһ���ڵ�Ľṹ
struct node
{
	int key;  //�ؼ��֣���Ͱ��ͳ��Ͱ���������������ݽڵ��о��ǽڵ������
	struct node *next;
};

//������
void PrintBucketSort(node** bucket, int bucket_size);
int f(int x);

void BucketSort(int* a, int size,int bucket_size)
{
	assert(a);
	
	//��Ͱ����ռ�
	node** bucket = new node*[bucket_size*sizeof(node)]; 

	//��ʼ��
	for (int i = 0; i < bucket_size; ++i)
	{
		bucket[i] = new node[sizeof(node)]; //ÿһ��Ͱ
		bucket[i]->key = 0;
		bucket[i]->next = nullptr;
	}

	for (int j = 0; j < size; ++j)
	{
		node* sub_node = new node[sizeof(node)]; //Ͱ�µ�ÿһ���ڵ�
		sub_node->key = a[j];
		sub_node->next = nullptr;

		//�������������ĸ�Ͱ��
		int num = f(a[j]);

		//��һ��ָ��ָ�����Ͱ�ŵ�ͷ
		node* sub_head = bucket[num];

		//��ʼ����
		if (sub_head->next == nullptr)
		{
			bucket[num]->next = sub_node;
			bucket[num]->key++;
		}
		//��Ͱ�Ų�Ϊ�գ���ô��������
		else
		{
			while (sub_head->next != nullptr && sub_node->key >= sub_head->next->key)
			{
				sub_head = sub_head->next;
			}

			sub_node->next = sub_head->next;
			sub_head->next = sub_node;
			bucket[num]->key++;
		}
	}
	//��ӡ
	PrintBucketSort(bucket, bucket_size);
}

//ӳ�亯��
int f(int x)
{
	return (x / 10);
}

//��ӡ
void PrintBucketSort(node** bucket, int bucket_size)
{
	//����Ͱ��(Ͱ��)
	for (int i = 0; i < bucket_size; ++i)
	{
		node* cur = bucket[i]->next;
		while (cur)
		{
			cout << cur->key << " ";
			cur = cur->next;
		}
	}
	cout << endl;
}

void Test7()
{
	int a[10] = { 49, 38, 35, 97, 76, 73, 27, 49, 34, 78 };
	cout << "Ͱ����" << endl;
	BucketSort(a, 10, 10);  //Ͱ��������97��������Ҫ10��Ͱ
}