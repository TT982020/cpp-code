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

		~vector() {
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void push_back(const T& data) {
			if (_finish == _endofstorage)
			{
				size_t sz = size();
				int cp = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[cp];

				//拷贝新空间，释放旧空间
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + cp;
			}
			*_finish = data;
			++_finish;	
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
}