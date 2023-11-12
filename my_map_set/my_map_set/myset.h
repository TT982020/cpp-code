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
		//set不能修改key的值
		typedef typename RBTree<K, K, setKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, setKeyOfT>::const_iterator const_iterator;
		/*iterator begin() const {
			return _t.begin();
		}
		iterator end() const {
			return _t.end();
		}*/
		const_iterator begin() const {
			return _t.begin();
		}
		const_iterator end() const {
			return _t.end();
		}
		pair<iterator, bool> insert(const K& key) {
			pair<typename RBTree<K, K, setKeyOfT>::iterator, bool> p = _t.Insert(key);

			return pair<iterator, bool>(p.first, p.second);
		}

	private:
		RBTree<K, K, setKeyOfT> _t;
	};
}