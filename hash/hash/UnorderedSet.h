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

		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator const_iterator;

		pair<iterator, bool> insert(const K& key) {
			pair<typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator, bool> p = _ht.Insert(key);
			return make_pair(iterator(p.first), p.second);
		}

		void print() {
			_ht.Print();
		}

		iterator begin() const {
			return _ht.begin();
		}

		iterator end() const {
			return _ht.end();
		}
	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
		
	};
}
