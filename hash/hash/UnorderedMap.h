#pragma once
#include "HashTable.h"

namespace my_map {
	template<class K, class V>
	class unordered_map {
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& data) {
				return data.first;
			}
		};
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		pair<iterator, bool> insert(const pair<const K, V>& kv) {
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

		V& operator[](const K& key) {
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

		
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT> _ht;
	};
}
