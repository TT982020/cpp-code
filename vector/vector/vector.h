#pragma once
#include<assert.h>
namespace name {
	template<class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin(){
			return _start;
		}

		iterator end() {
			return _finish;
		}

		const_iterator begin() const {
			return _start;
		}

		const_iterator end() const {
			return _finish;
		}

		vector() 
			:_start(nullptr)
			, _finish(nullptr)
			,_endofstorage(nullptr)
		{}

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			/*int sz = v.size();
			int cp = v.capacity();
			_start = new T[cp];
			for (size_t i = 0; i < sz; i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + sz;
			_endofstorage = _start + cp;*/
			reserve(v.capacity());
			for (auto e : v) {
				push_back(e);
			}
		}
		void swap(vector<T>& tmp) {
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
		}

		vector<T>& operator=(vector<T> tmp) {
			swap(tmp);
			return *this;
		}

		~vector() {
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		void reserve(size_t n) {
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{ 
					//拷贝新空间，释放旧空间
					//memcpy(tmp, _start, sizeof(T) * sz); //会有浅拷贝的问题
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];  //赋值是深拷贝
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = tmp + n;
			}
		}

		void resize(size_t n, const T& data = T()) {
			if (n <= size())
			{
				_finish = _start + n;
			}
			else {
				reserve(n);
				
				while (_finish != _start + n)
				{
					*_finish = data;
					++_finish;
				}
			}
		}

		void push_back(const T& data) {
			//if (_finish == _endofstorage)
			//{
			//	reserve(capacity() == 0 ? 4 : capacity() * 2);
			//	//T* tmp = new T[cp];

			//	////拷贝新空间，释放旧空间
			//	//if (_start)
			//	//{
			//	//	memcpy(tmp, _start, sizeof(T) * sz);
			//	//	delete[] _start;
			//	//}
			//	//_start = tmp;
			//	//_finish = _start + sz;
			//	//_endofstorage = _start + cp;
			//}
			//*_finish = data;
			//++_finish;	
			insert(end(), data);
		}

		void insert(iterator pos, const T& data) {
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				//这里可能会发生迭代器失效的现象，原因发生了扩容，原数组中的pos失效了，所以需要记录偏移量，获得新数组中的pos
				int len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = data;
			++_finish;
		}

		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			iterator end = pos;
			while (end != _finish - 1)
			{
				*end = *(end + 1);
				end++;
			}
			--_finish;
			return pos;
		}

		int size() const {
			return _finish - _start;
		}
		int capacity() const {
			return _endofstorage - _start;
		}

		T& operator[](int pos) {
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](int pos) const{
			assert(pos < size());
			return *(_start + pos);
		}

		

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : v) {
			cout << e << " ";
		}

		cout << endl;
	}

	void test_vector2() {
		vector<int*> v1;
		v1.resize(10);

		vector<string> v2;
		v2.resize(10);
	}

	void test_vector3() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin()+2, 30);
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 30);
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin());
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin()+2);
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector5() {
		//std::vector<int> v;
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0) {
				it = v.erase(it);
			}
			else {
				it++;
			}
			
		}
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6() {
		vector<string> v;
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");
		v.push_back("1111111");

		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector7() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int> v1(v);
		vector<int> v2;
		v2 = v;
		for (auto e : v1) {
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v2) {
			cout << e << " ";
		}
		cout << endl;
	}
}
