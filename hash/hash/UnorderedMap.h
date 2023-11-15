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
		bool insert(const pair<K, V>& kv) {
			return ht.Insert(kv);
		}
		void print() {
			ht.Print();
		}
	private:
		hash_bucket::HashTable<K, pair<K, V>, MapKeyOfT> ht;
	};
}
