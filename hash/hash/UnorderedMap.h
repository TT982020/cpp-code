#pragma once
#include "HashTable.h"

namespace my_map {
	template<class K, class V>
	class unordered_map {
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& data) {
				return data.first;
			}
		};
		typedef typename hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		bool insert(const pair<K, V>& kv) {
			return _ht.Insert(kv);
		}
		void print() {
			_ht.Print();
		}
		iterator begin() {
			return _ht.begin();
		}

		iterator end() {
			return _ht.end();
		}
	private:
		hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT> _ht;
	};
}
