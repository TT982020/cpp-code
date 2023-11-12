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
		typedef typename RBTree<K, pair<const K, V>, mapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, mapKeyOfT>::const_iterator const_iterator;
		pair <iterator, bool> insert(const pair<K, V>& kv) {
			return _t.Insert(kv);
		}

		iterator begin() {
			return _t.begin();
		}

		iterator end() {
			return _t.end();
		}
		const_iterator begin() const {
			return _t.begin();
		}

		const_iterator end() const {
			return _t.end();
		}

		V& operator[](const K& key) {
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<const K, V>, mapKeyOfT> _t;
	};
};