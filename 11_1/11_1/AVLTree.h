#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLNode
{
	pair<K, V> _kv;
	AVLNode<K, V>* _left;
	AVLNode<K, V>* _right;
	AVLNode<K, V>* _parent;
	int _bf;
	AVLNode<K, V>(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree {
	typedef AVLNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
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
		if (kv.first > parent->_kv.first) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		cur->_parent = parent;
		while (parent)
		{
			
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else if (parent->_right == cur){
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				//旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					rotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) {
					rotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) {
					rotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) {
					rotateLR(parent);
				}
				break;
			}
			else {
				assert(false);
			}
		}
		return true;
	}

	
	//左旋,孩子在右边
	void rotateL(Node* parent) {
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		parent->_right = curleft;
		if (curleft) {
			curleft->_parent = parent;
		}

		cur->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;
		if (ppnode == nullptr)
		{
			_root = cur;
			cur->_parent = ppnode;
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

		cur->_bf = parent->_bf = 0;
	}

	void rotateR(Node* parent) {
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
		cur->_bf = parent->_bf = 0;
	}

	void rotateRL(Node* parent) {
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		int bf = curleft->_bf;

		rotateR(parent->_right);
		rotateL(parent);
		if (bf == 0)
		{
			cur->_bf = parent->_bf = curleft->_bf = 0;
		}
		else if (bf == 1) {
			curleft->_bf = 0;
			parent->_bf = -1;
			cur->_bf = 0;
		}
		else if (bf == -1) {
			curleft->_bf = 0;
			cur->_bf = 1;
			parent->_bf = 0;
		}
		else {
			assert(false);
		}
	}

	void rotateLR(Node* parent) {
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;
		rotateL(parent->_left);
		rotateR(parent);
		if (bf == 0)
		{
			cur->_bf = parent->_bf = curright->_bf = 0;
		}
		else if (bf == 1) {
			parent->_bf = 0;
			cur->_bf = -1;
			curright->_bf = 0;
		}
		else if (bf == -1) {
			cur->_bf = 0;
			curright->_bf = 0;
			parent->_bf = 1;
		}
		else {
			assert(false);
		}
	}

	//void InOrder() {
	//	_InOrder(_root);
	//}

	//void _InOrder(Node* root) {
	//	if (root == nullptr) {
	//		return;
	//	}
	//	_InOrder(root->_left);
	//	cout << root->_kv.first << ":" << root->_kv.second;
	//	if (root->_left)
	//	{
	//		cout << "left:" << root->_left->_kv.first << " ";
	//	}
	//	if (root->_right)
	//	{
	//		cout << "right:" << root->_right->_kv.first << " ";
	//	}
	//	cout << endl;
	//	
	//	
	//	_InOrder(root->_right);
	//}
	int Height(Node* root) {
		if (root == nullptr)
		{
			return 0;
		}
		int leftH = Height(root->_left);
		int rightH = Height(root->_right);
		return leftH > rightH ? leftH + 1 : rightH + 1;
	}

	bool isBalance() {
		return _isBalance(_root);
	}

	bool _isBalance(Node* root) {
		if (root==nullptr)
		{
			return true;
		}
		int hl = Height(root->_left);
		int hr = Height(root->_right);

		if (hr - hl != root->_bf)
		{
			cout << "平衡因子异常" << root->_kv.first << "->" << root->_bf << endl;
			return false;
		}

		return abs(hl - hr) <= 1 && _isBalance(root->_left) && _isBalance(root->_right);

	}

private:
	Node* _root = nullptr;
};