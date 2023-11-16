#pragma once
#include "HashTable.h"
namespace my_set {
	template<class K>
	class unordered_set {
		
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& key) {
				return key;
			}
		};

		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator iterator;
		bool insert(const K& key) {
			return _ht.Insert(key);
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
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
		
	};
}
