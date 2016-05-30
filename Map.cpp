/*�Թ��Ͽδ����� �������3 ����Ϊ ��ڵ���߲�ͨ ����Ϊ�Ǹ�����
//��ת���ұ� ���ұ����²�ͨ���������������ֻص������ ���ʱ��
//��ڵ����Ҷ����� ֻ�е�ѭ������� ��������������*/


#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//��ȡ�Թ�����
void GetMazeMap(int* a,int row,int col)
{
	FILE* fOut = fopen("Map.txt","r"); //ֻ���ķ�ʽ��
	assert(fOut);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col;)
		{
			char ch = fgetc(fOut); 
			if(ch == '0' || ch == '1')
			{
				a[i*col + j] = ch - '0';//�����е��ַ� ת��Ϊ���� col���ⲿ����
				j++;
			}
		}
	}
	fclose(fOut);
}

//��ӡ�Թ�
void PrintMaze(int* a,int row,int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout<<a[i*col + j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

struct pos//���
{
	int row;
	int col;
};

//����Թ��Ƿ������
bool CheckIsAccess(int* a, int rowSize, int colSize, pos cur)
{
	if(cur.row < rowSize && cur.col < colSize
		&&cur.row >= 0 && cur.col >= 0
		&& a[cur.row * colSize + cur.col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Ѱ���Թ�·��
//stack��һ��ջ pos��һ���ṹ������ ����ģ�� stack<pos> ����һ������
stack<pos> GetMazePath(int* a, int rowSize, int colSize, pos entry)
{
	stack<pos> paths;
	pos cur = entry; //������긶�� cur��
	paths.push(entry); //���������ջ

	while(!paths.empty())  //���ջ��Ϊ��
	{
		pos cur = paths.top();//cur ָ��ջ�����ꣻ
		pos next = cur;

		if(next.row == rowSize - 1)
		{
			return paths;
		}
		
 /************************************************
 //ÿ����ߵ��������Ҿ��жϣ����ͨ· ������ջ�����
 //��ͬ�ͷ���
 //
 //***********************************************/
		//������
		next = cur;
		if(next.col == entry.col && next.row == entry.row)
		{
			a[next.row * colSize + next.col] = 2;
		}
		next.col--; //�˴����ܽ��м��ɸ����� ֮���ж�
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			paths.push(next);
			continue;
		}

		// ��
		next = cur;
		next.col++;
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			cur = next;
			paths.push(next);
			continue;
		}

		// ��
		next.row--;
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			paths.push(next);
			continue;
		}

		// ��
		next = cur;
		next.row++;
		if (CheckIsAccess(a, 10, 10, next))
		{
			a[next.row * colSize + next.col] = 2;
			paths.push(next);
			continue;
		}

		pos top = paths.top();
		a[top.row* colSize + top.col] = 3;
		paths.pop();
	}

	cout<<"û��"<<endl;
	return paths;
}


void Test()
{
	int a[10][10] = {};
	GetMazeMap((int*)a, 10, 10);
	PrintMaze((int*)a, 10, 10);

	pos entry = {2,0};  //����� ������ ������
	GetMazePath((int*)a,10,10,entry);
	PrintMaze((int*)a, 10, 10);
}

int main()
{
	Test();
	return 0;
}