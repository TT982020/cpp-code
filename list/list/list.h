#pragma once
namespace name {
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& data = T())
			:_data(data)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	template<class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator self;
		Node* _node;

		//构造函数，赋值一个指针
		__list_iterator(Node* node)
			:_node(node)
		{}

		self& operator++() {
			_node = _node->_next;
			return *this;
		}

		T& operator*() {
			return _node->_data;
		}

		bool operator!=(const self& s) {
			return _node != s._node;
		}

	};

	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef __list_iterator<T> iterator;

		void empty_init() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		list(const T&)
		{
			empty_init();
		}

		~list() {
		}

		iterator begin() {
			return _head->_next;
		}

		iterator end() {
			return _head;
		}

		void push_back(const T& data) {
			Node* tmp = new Node(data);
			Node* tail = _head->_prev;

			tail->_next = tmp;
			tmp->_prev = tail;
			tmp->_next = _head;
			_head->_prev = tmp;
		}

	private:
		Node* _head;
	};

	

	void test_list1() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}