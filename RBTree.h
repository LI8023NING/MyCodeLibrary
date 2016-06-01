#pragma once

//红黑颜色
enum Colour
{
	RED,
	BLACK,
};

//红黑树节点结构
template<class K, class V>
struct RBTreeNode
{
	// 链接结构
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	// Key/Value
	K _key;
	V _value;

	// 颜色
	Colour _col;

	RBTreeNode(const K& key, const V& value, Colour col = RED)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_col(col)
		,_key(key)
		,_value(value)

	{}
};


//树结构
// > ==
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}
	
	//插入比较复杂，详细见博客
	bool Insert(const K& key, const V& value)
	{
		//1.空树的时候
		if(_root == NULL)
		{
			_root = new Node(key, value, BLACK);
			return true;
		}

		// 2.找位置，插入节点
		Node* parent = NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value ,RED);
		if (parent->_key < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		// 3.进行调整
		while(cur != _root && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;

				// 》1情况1
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else // 》2.其余情况
				{
					if (cur == parent->_right)
					{
						_RotateL(parent);
						swap(cur, parent);
					}

					grandfather->_col = RED;
					parent->_col = BLACK;

					_RotateR(grandfather);
				}
			}
			else 
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						_RotateR(parent);
						swap(cur, parent);
					}
					
					grandfather->_col = RED;
					parent->_col = BLACK;

					_RotateL(grandfather);
				}
			}
		}
	
		_root->_col = BLACK;

		return true;
	}

	//左旋
	void _RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		subR->_parent = parent->_parent;
		parent->_parent = subR;

		if (subR->_parent == NULL)
		{
			_root = subR;
		}
		else
		{
			if (subR->_parent->_key > subR->_key)
			{
				subR->_parent->_left = subR;
			}
			else
			{
				subR->_parent->_right = subR;
			}
		}
	}
	
 	//右旋
	void _RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
		subL->_parent = parent->_parent;
		parent->_parent = subL;

		if (subL->_parent == NULL)
		{
			_root = subL;
		}
		else
		{
			if (subL->_parent->_key > subL->_key)
			{
				subL->_parent->_left = subL;
			}
			else
			{
				subL->_parent->_right = subL;
			}
		}
	}

	void InOrder()
	{
		return _InOrder(_root);
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}

		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
	}

protected:
	Node* _root;
};

void Test1()
{
	RBTree<int, int> t1;

	int a[10] = {5, 2, 9, 6, 7, 3, 4, 0, 1, 8};
	for (size_t i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		t1.Insert(a[i], i);
	}

	t1.InOrder();
}