#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;
struct Point
{
	Point(int x, int y)
		:_x(x)
		,_y(y){ }
	int _x;
	int _y;
};


//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//
//	int x = 3;
//	int y = { 3 };
//	int z{ 3 };
//	 
//	Point p1 = { 1,1 };
//	Point p2{ 0,0 };
//	Point p3(1, 2);
//
//	int* pi = new int[3] {1, 2, 3};
//
//	Point* p = new Point[3]{ {0,0},{1,1},{2,2} };
//
//	return 0;
//}

//int main() {
//	//���������ǲ�ͬ�ģ�
//	//Point p = { 1,1 };�ǵ����˹��캯��
//	//��vector<int> v = { 1,2,3,4,5 }; �ұ���һ��initialization_list<int> 
//	vector<int> v = { 1,2,3,4,5 };  
//	Point p = { 1,1 };  //ֱ�ӵ������������Ĺ��죬��ʽ����ת��
//
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//
//	map<string, string> dict = { {"sort","����"},{"left","���"} };
//	v = { 2,3,4,5 };
//}

class A {
private:
	decltype(malloc) pf;
};

template <class Func>
class B {
private:
	Func f;
};

//int main() {
//	auto pf = malloc;
//	//typeid(pf).name()�Ƴ����Ƕ����������һ���ַ�����ֻ�ܿ�������
//	cout << typeid(pf).name() << endl;
//	int x = 0, y = 10;
//
//	//decltype(pf)�Ƴ����Ƕ�������ͣ��ڶ������������Ϊģ��ʵ��
//	decltype(pf) pf1;
//
//	B<decltype(pf)> b;
//	B<decltype(x* y)> b;
//}


//int main() {
//	const int a = 0;
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	double x = 1.1, y = 2.2;
//	//�����ǳ�������ֵ
//	10;
//	x + y;
//	fmin(x, y);  // ���ص���һ����ʱ���󣬶�����ֵ
//
//	const char* p = "xxxxxxxxxxx";  //��ֵ
//	cout << &p[2] << endl;
//}

//int main() {
//	//��ֵ����
//	int a = 10;
//	double x = 1.1, y = 2.2;
//
//	int& r = a;
//	//��ֵ���ÿ���������ֵ����const
//	const int& r2 = 10;
//	const double& r3 = x + y;
//
//	//��ֵ����
//	int&& r1 = 10;
//	
//	double&& z = x + y;
//
//	//��ֵ�����ܷ����ֵȡ������
//	//����ֱ�����ã�����������move֮�����ֵ
//	int&& r4 = move(a);
//}

//void Fun(int& x) { cout << "��ֵ����" << endl; }
//void Fun(const int& x) { cout << "const ��ֵ����" << endl; }
//void Fun(int&& x) { cout << "��ֵ����" << endl; }
//void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
//// ģ���е�&&��������ֵ���ã������������ã�����ܽ�����ֵ���ܽ�����ֵ��
//// ģ�����������ֻ���ṩ���ܹ�����ͬʱ������ֵ���ú���ֵ���õ�������
//// �����������͵�Ψһ���þ��������˽��յ����ͣ�����ʹ���ж��˻�������ֵ��
//// ����ϣ���ܹ��ڴ��ݹ����б���������ֵ������ֵ������, ����Ҫ����������ѧϰ������ת��
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(t);
//	//����ת����t����ֵ���ã�������ֵ����
//	//����ת����t����ֵ���ã�������ֵ����
//	//Fun(forward<T>(t));
//}
//
//
//int main()
//{
//	PerfectForward(10); // ��ֵ
//	int a;
//	PerfectForward(a); // ��ֵ
//	PerfectForward(std::move(a)); // ��ֵ
//	const int b = 8;
//	PerfectForward(b);  // const ��ֵ
//	PerfectForward(std::move(b)); // const ��ֵ
//
//	//int a;
//	int& r = a;
//	int&& rr = move(a);
//	int&& rrr = 10;
//	rrr++;
//	cout << &a << endl;
//	cout << &r << endl;
//	cout << &rr << endl;
//	cout << rrr << endl;
//	return 0;
//}

//int main() {
//	int a;
//	int& r = a;
//	int&& rr = move(a);
//	cout << &a << endl;
//	cout << &r << endl;
//	cout << &rr << endl;
//}

using namespace std;
namespace AAA {
#include<assert.h>
	class string
	{
		//friend ostream& operator<<(ostream& out, const string& s);
	public:
		/*string(int capacity = 16)
			:_str(new char[capacity])
			,_size(0)
			,_capacity(capacity)
		{
			_str[0] = '\0';
		}*/
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator begin() const {
			return _str;
		}
		const_iterator end() const {
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(const char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}


		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		/*string(const string& str) {
			_size = str._size;
			_capacity = str._capacity;
			_str = new char[str._capacity + 1];
			strcpy(_str, str.c_str());
		}*/

		void swap(string& s) {
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//��������Ľ�
		string(const string& str)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& str)  ���" << endl;
			string tmp(str._str);
			swap(tmp);
		}


		string(string&& s)
			:_str(nullptr)
		{
			cout << "string(string&& s) �ƶ�����" << endl;
			swap(s);
		}

		/*string& operator=(const string& str) {
			if (this != &str)
			{
				char* tmp = new char[str._capacity + 1];
				strcpy(tmp, str.c_str());
				delete[] _str;
				_str = tmp;
				_size = str._size;
				_capacity = str._capacity;
			}
			return *this;
		}*/

		//��ֵ���ظĽ�
		/*string& operator=(const string& str) {
			if (this != &str)
			{
				string tmp(str);
				swap(tmp);
			}
			return *this;
		}*/

		//��ֵ�����ٸĽ�
		string& operator=(string tmp) {
			swap(tmp);
			return *this;
		}

		string& operator=(string&& s) {
			cout << "string& operator=(string&& s) �ƶ�����" << endl;
			swap(s);
			return *this;
		}

		char& operator[](int pos) {
			assert(pos < _size);
			return _str[pos];
		}

		const char operator[](int pos) const {
			assert(pos < _size);
			return _str[pos];
		}

		size_t capacity() const {
			return _capacity;
		}

		size_t size() const {
			return _size;
		}

		const char* c_str() const {
			return _str;
		}

		void reserve(size_t n) {
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str); // strcpy���\0Ҳ������ȥ
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0') {
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
					_size++;
				}
				_str[n] = '\0';
			}
		}

		void push_back(char ch) {
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}

		void append(const char* str) {
			int len = strlen(str);

			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str) {
			append(str);
			return *this;
		}

		void insert(size_t pos, char ch) {
			assert(pos >= 0 || pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}

		void insert(int pos, const char* str) {
			assert(pos >= 0 || pos <= _size);
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			memcpy(_str + pos, str, strlen(str));
			_size += len;
		}

		void erase(int pos, int len = npos) {
			assert(pos >= 0 || pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else {
				size_t end = pos;
				while (end <= _size - len)
				{
					_str[end] = _str[end + len];
					end++;
				}
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0) {
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* sub, size_t pos = 0) {
			const char* found = strstr(_str + pos, sub);
			if (found)
			{
				return found - _str;
			}
			else {
				return npos;
			}
		}

		string substr(size_t pos, size_t len = npos) {
			string s;
			size_t end = pos + len;
			if (len == npos || pos + len >= _size)
			{
				end = _size;
				len = _size - pos;
			}
			s.reserve(len);
			for (size_t i = pos; i < end; i++)
			{
				s += _str[i];
			}
			return s;
		}

		bool operator<(const string& s) {
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s) {
			return strcmp(_str, s._str) == 0;
		}
		bool operator<=(const string& s) {
			return *this < s || *this == s;
		}

		bool operator>(const string& s) {
			return !(*this <= s);
		}

		bool operator>=(const string& s) {
			return !(*this < s);
		}

		bool operator!=(const string& s) {
			return !(*this == s);
		}

		void clear() {
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		int _size;
		int _capacity;
		//const static size_t npos = -1; //����, һ����˵��̬���������������ʼ��������const static int����
	public:
		const static size_t npos; //����

	};
	template<class T>
	struct ListNode
	{
		ListNode* _next = nullptr;
		ListNode* _prev = nullptr;
		T _data;
		/*ListNode(const T& val)
			:_data(val)
			,_next(nullptr)
			,_prev(nullptr){}*/
		template<class Ty>
		ListNode(Ty&& val)
			:_data(std::forward<Ty>(val))
			, _next(nullptr)
			, _prev(nullptr) {}
	};

	template<class T>
	class List
	{
		typedef ListNode<T> Node;
	public:
		List()
		{
			_head = new Node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		void PushBack(const T& x)
		{
			//Insert(_head, x);
			Insert(_head, x);
		}

		void PushBack(T&& x)
		{
			//Insert(_head, x);
			Insert(_head, std::forward<T>(x));
		}

		void PushFront(T&& x)
		{
			//Insert(_head->_next, x);
			Insert(_head->_next, forward<T>(x));
		}
		void Insert(Node* pos, T&& x)
		{
			Node* prev = pos->_prev;
			Node* newnode = new Node(std::forward<T>(x)); // �ؼ�λ��
			// prev newnode pos
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = pos;
			pos->_prev = newnode;
		}

		void Insert(Node* pos, const T& x)
		{
			Node* prev = pos->_prev;
			Node* newnode = new Node(x); // �ؼ�λ��
			// prev newnode pos
			prev->_next = newnode; newnode->_prev = prev;
			newnode->_next = pos;
			pos->_prev = newnode;
		}
	private:
		Node* _head;
	};


}
int main()
{
	AAA::List<AAA::string> lt;
	AAA::string str1("11111");
	lt.PushBack(str1);
	cout << endl;

	AAA::string str2("2222");
	lt.PushBack(move(str2));
	cout << endl;

	lt.PushBack("333333333");
	cout << endl;

	return 0;
}


