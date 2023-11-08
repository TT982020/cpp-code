#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Color _col;
	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
	{}
};


template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv) {
		Node* cur = _root;
		Node* parent = nullptr;
		if (cur == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		while (cur)
		{
			if (kv.first > cur->_kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (cur->_kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// u存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else // u不存在或u为黑
				{
					// cur在parent的左边，进行右单旋
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					
					// cur在parent的右边，进行左右单旋
					else {
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					//进行旋转之后 parent一定是黑色，所以就可以不用再往上判断了
					break;
				}
			}
			else {
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else {
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else {
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	void RotateL(Node* parent) {
		++rotateCount;
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}
		Node* ppnode = parent->_parent;
		cur->_left = parent;

		parent->_parent = cur;
		if (ppnode == nullptr)
		{
			cur->_parent = ppnode;
			_root = cur;
		}
		else {
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
				cur->_parent = ppnode;
			}
			else {
				ppnode->_right = cur;
				cur->_parent = ppnode;
			}
		}
	}

	void RotateR(Node* parent) {
		++rotateCount;
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		parent->_left = curright;
		if (curright)
		{
			curright->_parent = parent;
		}
		cur->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			cur->_parent = nullptr;
			_root = cur;
		}
		else {
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else {
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
	}

	bool CheckColor(Node* root, int blacknum, int benckmark) {
		if (root == nullptr)
		{
			if (blacknum != benckmark)
			{
				return false;
			}
			return true;
		}
		if (root->_col == BLACK)
		{
			++blacknum;
		}
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
			return false;
		}
		
		return CheckColor(root->_left, blacknum, benckmark) 
			&& CheckColor(root->_right, blacknum, benckmark);

	}
	
	bool IsBalance() {
		return _IsBalance(_root);
	}

	bool _IsBalance(Node* root) {
		if (root == nullptr)
		{
			return true;
		}
		if (root->_col != BLACK)
		{
			return false;
		}
		Node* cur = root;
		int benchmark = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++benchmark;
			}
			cur = cur->_left;
		}

		return CheckColor(root, 0, benchmark);
	}

	int Height() {
		return _Height(_root);
	}

	int _Height(Node* root) {
		if (root == nullptr)
		{
			return 0;
		}
		int leftH = _Height(root->_left);
		int rightH = _Height(root->_right);
		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

private:
	Node* _root = nullptr;
public:
	int rotateCount = 0;
};
