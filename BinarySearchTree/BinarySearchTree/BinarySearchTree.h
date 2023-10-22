#pragma once

template<class K>
struct BSTreeNode {
	K _key;
	struct BSTreeNode<K>* _left;
	struct BSTreeNode<K>* _right;
	BSTreeNode(K key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K>
class BSTree {
	typedef BSTreeNode<K> Node;

public:
	BSTree()
		:_root(nullptr) {}


	bool insert(const K& key) {
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key > cur->_key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		Node* newnode = new Node(key);
		if (key > parent->_key) {
			parent->_right = newnode;
		}
		else {
			parent->_left = newnode;
		}
		return true;
	}

	bool Erase(const K& key) {
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key > cur->_key) {
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				//左为空
				if (cur->_left == nullptr) {
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else {
						if (parent->_right == cur) {
							parent->_right = cur->_right;
						}
						else {
							parent->_left = cur->_right;
						}
					}
				}
				//右为空
				else if (cur->_right == nullptr) {
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur) {
							parent->_right = cur->_left;
						}
						else {
							parent->_left = cur->_left;
						}
					}

				}
				//左右都有孩子
				//找替代节点
				else {
					Node* leftMax = cur->_left;
					Node* maxParent = cur;
					while (leftMax->_right)
					{
						maxParent = leftMax;
						leftMax = leftMax->_right;
					}
					swap(leftMax->_key, cur->_key);
					if (maxParent->_left == leftMax)
					{
						maxParent->_left = leftMax->_left;
					}
					else {
						maxParent->_right = leftMax->_left;
					}
					cur = leftMax;
				}
				delete cur;
				return true;
			}
		}
	}

	bool Find(const K& key) {
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key) {
				cur = cur->_right;
			}
			else if (key < cur->_key) {
				cur = cur->_left;
			}
			else {
				return true;
			}
		}
		return false;
	}

	void Inorder() {
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root) {
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_key << " ";
		_Inorder(root->_right);
	}

private:
	Node* _root;
};



void TestBSTree1() {
	BSTree<int> bst;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a) {
		bst.insert(e);
	}
	bst.Inorder();

	bst.Erase(4);
	bst.Inorder();
	bst.Erase(6);
	bst.Inorder();
	bst.Erase(7);
	bst.Inorder();
	bst.Erase(3);
	for (auto e : a) {
		bst.Erase(e);
	}
	bst.Inorder();
}