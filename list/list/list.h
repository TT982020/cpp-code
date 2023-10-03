#pragma once
#include <assert.h>
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
		typedef __list_iterator<T> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		T* operator->() {
			return &_node->_data;
		}

		self& operator++() {
			_node = _node->_next;
			return *this;
		}

		self& operator--() {
			_node = _node->_prev;
			return *this;
		}

		self operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self operator--(int) {
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		T& operator*() {
			return _node->_data;
		}

		bool operator!=(const self& s) {
			return _node != s._node;
		}

		bool operator==(const self& s) {
			return _node == s._node;
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
			_size = 0;
		}

		list()
		{
			empty_init();
		}

		list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt) {
				push_back(e);
			}
		}

		void swap(list<T>& lt) {
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T>& lt) {
			/*if (*this != lt)
			{
				clear();
				for (auto e : lt) {
					push_back(e);
				}
			}*/
			swap(lt);
			return *this;
		}

		iterator begin() {
			return _head->_next;
		}

		iterator end() {
			return _head;
		}

		iterator begin() const {
			return _head->_next;
		}

		iterator end() const {
			return _head;
		}

		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear() {
			iterator it = begin(); 
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_front(const T& data) {
			insert(begin(), data);
		}

		void push_back(const T& data) {
			/*Node* tmp = new Node(data);
			Node* tail = _head->_prev;

			tail->_next = tmp;
			tmp->_prev = tail;
			tmp->_next = _head;
			_head->_prev = tmp;*/
			insert(end(), data);
		}

		void pop_front() {
			erase(begin());
		}

		void pop_back() {
			erase(--end());
		}

		iterator insert(iterator pos, const T& data) {
			//在pos之前插入一个节点
			Node* cur = pos._node;
			Node* newnode = new Node(data);
			Node* prev = cur->_prev;

			newnode->_next = cur;
			cur->_prev = newnode;
			prev->_next = newnode;
			newnode->_prev = prev;
			++_size;
			return iterator(newnode);
		}

		iterator erase(iterator pos) {
			//删除pos位置节点
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--_size;
			return iterator(next);
		}

		size_t size() {
			return _size;
		}

	private:
		Node* _head;
		size_t _size;
	};

	struct AA
	{
		//friend ostream& operator<<(ostream& out, AA a);
		AA(int a = 0, int b = 0)
			:_a(a)
			,_b(b)
		{}
		int _a;
		int _b;
	};
	//ostream& operator<<(ostream& out, AA a) {
	//	out << "(" << a._a << "," << a._b << ")";
	//	return out;
	//}
	

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
		cout << "size=" << lt.size() << endl;
		//cout << endl;
		lt.insert(lt.begin(), 100);
		for (auto e : lt) {
			cout << e << " ";
		}
		cout << "size=" << lt.size() << endl;
		//cout << endl;
		list<int> lt2(lt);
		for (auto e : lt2) {
			cout << e << " ";
		}
		cout << "size=" << lt2.size() << endl;
		//cout << endl;
		list<int> lt3;
		lt3.push_back(1);
		lt3.push_back(2);
		for (auto e : lt3) {
			cout << e << " ";
		}
		cout << "size=" << lt3.size() << endl;
		//cout << endl;
		lt3 = lt2;
		for (auto e : lt3) {
			cout << e << " ";
		}
		cout << "size=" << lt3.size() << endl;
		//cout << endl;
	}

	void test_list2() {
		list<AA> lt;
		lt.push_back(AA(1, 1));
		lt.push_back(AA(1, 2));
		lt.push_back(AA(1, 3));
		lt.push_back(AA(1, 4));
		list<AA>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a << "," << (*it)._b << " " << endl;
			//cout << it.operator->()->_a << "," << it.operator->()->_b << " " << endl;
			cout << it->_a << "," << it->_b << " " << endl;
			++it;
		}
		cout << endl;
	}
}