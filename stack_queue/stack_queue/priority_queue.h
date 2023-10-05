#pragma once

namespace C {
	template<class T, class Container = vector<T>, class Compare = DateCompare<T>>
	class priority_queue
	{
	public:
		priority_queue() {}
		template<class InputIterator>
		priority_queue(InputIterator begin, InputIterator end)
			:_con(begin, end)
		{
			for (int i = (_con - 2) / 2; i >= 0; i--) {
				adjust_down(i);
			}
		}

		void adjust_up(int child) {
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child])) {
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
				
			}
		}

		void adjust_down(int parent) {
			Compare com;
			int child = parent * 2 + 1;

			while (child < _con.size())
			{
				
				if (child + 1 < _con.size()
					&& com(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (com(_con[parent], _con[child])) {
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& data) {
			_con.push_back(data);
			adjust_up(_con.size() - 1);
		}

		void pop() {
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		T& top() {
			return _con[0];
		}

		bool empty() {
			return _con.empty();
		}



	private:
		Container _con;
	};
	template<class T>
	class Less {
	public:
		bool operator()(const T& x, const T& y) {
			return x < y;
		}
	};

}