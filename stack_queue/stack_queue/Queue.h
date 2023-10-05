#pragma once
#include <list>
namespace B {
	template <class T, class Container = deque<T>> 
	class queue
	{
	public:
		void push(const T& data) {
			_con.push_back(data);
		}

		void pop() {
			_con.pop_front();
		}

		const T& front() {
			return _con.front();
		}

		const T& back() {
			return _con.back();
		}

		bool empty() {
			return _con.empty();
		}

		size_t size() {
			return _con.size();
		}


	private:
		Container _con;
	};

}