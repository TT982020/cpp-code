#pragma once
#include "RBTree.h"
namespace name_map {
	template<class K, class V>
	class map {
		struct mapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};

		
	public:
		typedef typename RBTree<K, pair<K, V>, mapKeyOfT>::iterator iterator;
		bool insert(const pair<K, V>& kv) {
			return _t.Insert(kv);
		}
		iterator begin() {
			return _t.begin();
		}

		iterator end() {
			return _t.end();
		}

	private:
		RBTree<K, pair<K, V>, mapKeyOfT> _t;
	};
}