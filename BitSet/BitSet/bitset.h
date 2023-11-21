#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace bit_set {
	template<size_t N>
	class bitset {
	public:
		bitset() {
			_a.resize(N / 32 + 1);
		}
		void set(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;
			_a[i] |= 1 << j;
		}

		void reset(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;
			_a[i] &= (~(1 << j));
		}

		bool test(size_t x) {
			size_t i = x / 32;
			size_t j = x % 32;
			return _a[i] & (1 << j);
		}
	private:
		vector<int> _a;
	};

	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x) {
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				_bs2.set(x);
			}
			else if (!_bs1.test(x) && _bs2.test(x)) {
				_bs1.set(x);
				_bs2.reset(x);
			}
		}

		bool is_once(size_t x) {
			if (!_bs1.test(x) && _bs2.test(x))
			{
				return true;
			}
			return false;
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}