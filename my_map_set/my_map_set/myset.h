#pragma once
#include "RBTree.h"
namespace name_set {
	template<class K>
	class set {
		struct setKeyOfT
		{
			const K& operator()(const K& key) {
				return key;
			}
		};

	public:
		typedef typename RBTree<K, K, setKeyOfT>::iterator iterator;
		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
		bool insert(const K& key) {
			return _t.Insert(key);
		}

	private:
		RBTree<K, K, setKeyOfT> _t;
	};
}