
#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _col;
	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template <class T, class Ptr, class Ref>
struct __TreeIterator {
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ptr, Ref> Self;
	typedef __TreeIterator<T, T*, T&> Iterator;
	__TreeIterator(Node* node)
		:_node(node)
	{}

	__TreeIterator(const Iterator& iter) 
		:_node(iter._node)
	{}

	Node* _node;

	Ref operator*() {
		return _node->_data;
	}

	Ptr operator->() {
		return &_node->_data;
	}

	bool operator!=(const Self& s) {
		return s._node != _node;
	}

	Self& operator++() {
		Node* cur = _node;
		if (cur->_right)
		{
			cur = cur->_right;
			//找右子树中的最左节点
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else {
			// 找parent，直到cur节点为parent的左节点
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator--() {
		Self ret = *this;

		if (_node->_left)
		{
			Node* cur = _node->_left;
			while (cur && cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return ret;
	}
};

template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:

	typedef __TreeIterator<T, T*, T&> iterator;
	typedef __TreeIterator<T, const T*, const T&> const_iterator;

	iterator begin() {
		//找最左节点
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end() {
		return iterator(nullptr);
	}

	const_iterator begin() const {
		//找最左节点
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return const_iterator(cur);
	}

	const_iterator end() const {
		return const_iterator(nullptr);
	}

	Node* Find(const K& key) {
		KeyOfT kot;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) > key) {
				cur = cur->_left;
			}
			else if (kot(cur->_data) < key) {
				cur = cur->_right;
			}
			else {
				return cur;
			}
		}
		return nullptr;
	}

	pair<iterator, bool> Insert(const T& data) {
		KeyOfT kot;
		Node* cur = _root;
		Node* parent = nullptr;
		if (cur == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		while (cur)
		{
			if (kot(data) > kot(cur->_data)) {
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(data) < kot(cur->_data)) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED;
		if (kot(cur->_data) > kot(parent->_data))
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

		return make_pair(iterator(newnode), true);
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
