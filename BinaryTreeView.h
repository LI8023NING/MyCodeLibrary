#pragma once

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//1、求二叉树中的节点个数

int GetNodeNum(BinaryTreeNode * pRoot)
{
	if(pRoot == NULL)
	{
		return 0;
	}
	return GetNodeNum(pRoot->m_pLeft) + GetNodeNum(pRoot->m_pRight) + 1;
}

//2、求二叉树的深度
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

//3、前序遍历，中序遍历，后序遍历

void PreOrderTraverse(BinaryTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    printf("%d\n",pRoot->data); // 显示结点数据
    PreOrderTraverse(pRoot->m_pLeft); // 前序遍历左子树
    PreOrderTraverse(pRoot->m_pRight); // 前序遍历右子树
}

void InOrderTraverse(BinaryTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    InOrderTraverse(pRoot->m_pLeft); // 中序遍历左子树
    printf("%d\n",pRoot->data); // 显示结点数据
    InOrderTraverse(pRoot->m_pRight); // 中序遍历右子树
}

void InOrderTraverse(BinaryTreeNode * pRoot)
{
    if(pRoot == NULL)
        return;
    InOrderTraverse(pRoot->m_pLeft); // 后序遍历左子树
    InOrderTraverse(pRoot->m_pRight); // 后序遍历右子树
    printf("%d\n",pRoot->data); // 显示结点数据
}





