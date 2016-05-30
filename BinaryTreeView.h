#pragma once

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//1����������еĽڵ����

int GetNodeNum(BinaryTreeNode * pRoot)
{
	if(pRoot == NULL)
	{
		return 0;
	}
	return GetNodeNum(pRoot->m_pLeft) + GetNodeNum(pRoot->m_pRight) + 1;
}

//2��������������
int GetDepth(BinaryTreeNode * pRoot)
{
	if(pRoot == NULL)
	{
		return 0;
	}

	int depthLeft = GetDepth(pRoot->m_pLeft);
	int depthRight = GetDepth(pRoot->m_pRight);

	return depthLeft > depthRight ? (depthLeft + 1):(depthRight + 1);
}

//3��ǰ�����������������������

void PreOrderTraverse(BinaryTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    printf("%d\n",pRoot->data); // ��ʾ�������
    PreOrderTraverse(pRoot->m_pLeft); // ǰ�����������
    PreOrderTraverse(pRoot->m_pRight); // ǰ�����������
}

void InOrderTraverse(BinaryTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    InOrderTraverse(pRoot->m_pLeft); // �������������
    printf("%d\n",pRoot->data); // ��ʾ�������
    InOrderTraverse(pRoot->m_pRight); // �������������
}

void InOrderTraverse(BinaryTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    InOrderTraverse(pRoot->m_pLeft); // �������������
    InOrderTraverse(pRoot->m_pRight); // �������������
    printf("%d\n",pRoot->data); // ��ʾ�������
}





