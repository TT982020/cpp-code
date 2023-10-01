#pragma once
#include <assert.h>

namespace name1 {
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
			,_capacity(_size)
		{
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

		//拷贝构造改进
		string(const string& str)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(str._str);
			swap(tmp);
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

		//赋值重载改进
		/*string& operator=(const string& str) {
			if (this != &str)
			{
				string tmp(str);
				swap(tmp);
			}
			return *this;
		}*/

		//赋值重载再改进
		string& operator=(string tmp) {
			swap(tmp);
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
				strcpy(tmp, _str); // strcpy会把\0也拷贝过去
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
				_str[end] = _str[end-1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}

		void insert(int pos, const char* str) {
			assert(pos >= 0 || pos <= _size);
			int len = strlen(str);
			if (_size+len > _capacity)
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
		//const static size_t npos = -1; //特例, 一般来说静态变量不能在这里初始化，但是const static int可以
	public:
		const static size_t npos; //特例

	};
	const size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s) {
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/
		for (auto ch : s) {
			out << ch;
		}
		return out;
	}
	
	//存在一个弊端，可能会导致多次扩容，也可能导致空间浪费,解决办法是先把数据读到一个buffer中，读满了再写到s中
	istream& operator>>(istream& in, string& s) {
		char ch;
		s.clear();
		char buff[129];
		size_t i = 0;
		in.get(ch);
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i==128)
			{
				buff[i] = '\0';
				s += buff; 
				i = 0;
			}
;			//s += ch;
			in.get(ch);
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}

	void test_string1() {
		string s1("hello,world");
		cout << s1.c_str() << endl;
		string s2;
		cout << s2.c_str() << endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto ch : s1) {
			cout << ch << " ";
		}
		cout << endl;

	}
	void test_string2() {
		string s1;
		s1.append("nihao ");
		s1.append("okk ");
		s1.push_back('a');
		s1.push_back('b');
		s1.push_back('c');

		s1 += '#';
		s1 += "hello bit";

		cout << s1.c_str() << endl;
	}

	void test_string3() {
		string s1;
		//s1.insert(0, 'a');

		s1.insert(0, "hello");
		s1.insert(0, '$');
		cout << s1.c_str() << endl;
		string s2("hello world");
		s2.insert(5, "%%");
		cout << s2.c_str() << endl;

		s2.erase(5, 2);
		cout << s2.c_str() << endl;
	}

	void test_string4() {
		string s1("hello world");
		string s2("hello world");
		cout << (s1 == s2) << endl;
		s1[0] = 'z';
		/*cout << (s1 > s2) << endl;
		cout << s1 << endl;*/

		cin >> s1;
		cout << s1;
	}
	void test_string6() {
		string s1("hello world");
		//s1.resize(20,'x');
		s1.resize(20);
		cout << s1;
	}

	void test_string7() {
		string s1("test.cpp.tar.zip");
		//size_t i = s1.find('.');
		/*size_t i = s1.rfind('.');
		string s2 = s1.substr(i);
		cout << s2 << endl;*/

		string s3("https://legacy.cplusplus.com/reference/string/string/substr/");
		string protocol, name, resource;
		size_t i1 = s3.find(':');
		if (i1 != string::npos)
		{
			//不解决浅拷贝的问题，这里会出问题，因为substr会调用拷贝构造，此时是浅拷贝，析构后空间释放就会出问题
			protocol = s3.substr(0, i1);
			cout << protocol << endl;
		}
		else
		{
			cout << "没有找到i1" << endl;
		}

		size_t i2 = s3.find('/', i1 + 3);
		if (i2 != string::npos)
		{
			name = s3.substr(i1 + 3, i2 - (i1 + 3));
			cout << name << endl;
		}
		else
		{
			cout << "没有找到i2" << endl;
		}

		resource = s3.substr(i2 + 1);
		cout << resource << endl;

	}

	void test_string8() {
		string s1("hello,world");
		string s2 = s1;
		cout << s1 << endl;
		cout << s2 << endl;

		string s3("xxxxxxxxxxxxxxxxxxx");
		s2 = s3;
		cout << s2 << endl;

	}

}