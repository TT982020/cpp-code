#pragma once


namespace key {
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

		~BSTree() {
			Destroy(_root);
		}

		BSTree(const BSTree<K>& root) {
			_root = copy(root._root);
		}

		BSTree<K>& operator=(BSTree<K> root) {
			swap(root._root, _root);
			return *this;
		}

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

		bool FindR(const K& key) {
			return _FindR(_root, key);
		}
		bool InsertR(const K& key) {
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key) {
			return _EraseR(_root, key);
		}

	private:
		Node* copy(Node* root) {
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* newnode = new Node(root->_key);
			newnode->_left = copy(root->_left);
			newnode->_right = copy(root->_right);
			return newnode;
		}

		void Destroy(Node*& root) {
			if (root == nullptr)
			{
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
			root = nullptr;
		}
		bool _EraseR(Node*& root, const K& key) {
			if (root == nullptr)
			{
				return false;
			}
			if (key > root->_key)
			{
				_EraseR(root->_right, key);
			}
			else if (key < root->_key) {
				_EraseR(root->_left, key);
			}
			else {
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				else {
					Node* leftmax = root->_left;
					while (leftmax->_right)
					{
						leftmax = leftmax->_right;
					}
					swap(root->_key, leftmax->_key);
					return _EraseR(root->_left, key);
				}
				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key) {
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (key > root->_key) {
				return _InsertR(root->_right, key);
			}
			else if (key < root->_key) {
				return _InsertR(root->_left, key);
			}
			else {
				return false;
			}
		}

		bool _FindR(Node* root, const K& key) {
			if (root == nullptr)
			{
				return false;
			}
			if (key > root->_key) {
				return _FindR(root->_right, key);
			}
			else if (key < root->_key) {
				return _FindR(root->_left, key);
			}
			else {
				return true;
			}
		}

		Node* _root;
	};
	void TestBSTree1() {
		BSTree<int> bst;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a) {
			bst.InsertR(e);
		}
		bst.Inorder();

		bst.EraseR(4);
		bst.Inorder();
		bst.EraseR(6);
		bst.Inorder();
		bst.EraseR(7);
		bst.Inorder();
		bst.EraseR(3);
		for (auto e : a) {
			bst.EraseR(e);
		}
		bst.Inorder();
	}

	void TestBSTree2() {
		BSTree<int> bst;
		int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : a) {
			bst.InsertR(e);
		}
		bst.Inorder();
		BSTree<int> cp(bst);
	}

}

namespace key_value {
	template<class K, class V>
	struct BSTreeNode {
		K _key;
		V _value;
		struct BSTreeNode<K,V>* _left;
		struct BSTreeNode<K,V>* _right;
		BSTreeNode(K key, V value)
			:_key(key)
			,_value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K, class V>
	class BSTree {
		typedef BSTreeNode<K,V> Node;

	public:
		BSTree()
			:_root(nullptr)
		{}

		

		Node* Find(const K& key) {
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
					return cur;
				}
			}
			return nullptr;
		}
		Node* FindR(const K& key) {
			return _FindR(_root, key);
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
			cout << root->_key << ":" << root->_value << endl;
			_Inorder(root->_right);
		}

		
		bool InsertR(const K& key, const V& value) {
			return _InsertR(_root, key, value);
		}

		bool EraseR(const K& key) {
			return _EraseR(_root, key);
		}

	private:

		bool _EraseR(Node*& root, const K& key) {
			if (root == nullptr)
			{
				return false;
			}
			if (key > root->_key)
			{
				_EraseR(root->_right, key);
			}
			else if (key < root->_key) {
				_EraseR(root->_left, key);
			}
			else {
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr) {
					root = root->_left;
				}
				else {
					Node* leftmax = root->_left;
					while (leftmax->_right)
					{
						leftmax = leftmax->_right;
					}
					swap(root->_key, leftmax->_key);
					return _EraseR(root->_left, key);
				}
				delete del;
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key, const V& value) {
			if (root == nullptr)
			{
				root = new Node(key, value);
				return true;
			}
			if (key > root->_key) {
				return _InsertR(root->_right, key, value);
			}
			else if (key < root->_key) {
				return _InsertR(root->_left, key, value);
			}
			else {
				return false;
			}
		}

		Node* _FindR(Node* root, const K& key) {
			if (root == nullptr)
			{
				return nullptr;
			}
			if (key > root->_key) {
				return _FindR(root->_right, key);
			}
			else if (key < root->_key) {
				return _FindR(root->_left, key);
			}
			else {
				return root;
			}
		}

		Node* _root;
	};

	void TestBSTree1() {
		// 输入单词，查找单词对应的中文翻译
		BSTree<string, string> dict;
		dict.InsertR("string", "字符串");
		dict.InsertR("tree", "树");
		dict.InsertR("left", "左边、剩余");
		dict.InsertR("right", "右边");
		dict.InsertR("sort", "排序");
		// 插入词库中所有单词

		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret == nullptr)
			{
				cout << "单词拼写错误，词库中没有这个单词:" << str << endl;
			}
			else
			{
				cout << str << "中文翻译:" << ret->_value << endl;
			}
		}
	}
	void TestBSTree2() {
		// 统计水果出现的次数
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	   "苹果", "香蕉", "苹果", "香蕉" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			// 先查找水果在不在搜索树中
			// 1、不在，说明水果第一次出现，则插入<水果, 1>
			// 2、在，则查找到的节点中水果对应的次数++
			//BSTreeNode<string, int>* ret = countTree.Find(str);
			auto ret = countTree.Find(str);
			if (ret == NULL)
			{
				countTree.InsertR(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}
		countTree.Inorder();
	}
}



