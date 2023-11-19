#pragma once
#include <vector>
template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};

template<>
struct DefaultHashFunc<string>
{
	size_t operator()(const string& str) {
		size_t hashi = 0;
		for (auto e : str) {
			hashi *= 131;
			hashi += e;
		}
		return hashi;
	}
};

namespace open_address {
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData {

		pair<K, V> _kv;
		STATE _state = EMPTY;
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable {
	public:
		HashTable()
		{
			_table.resize(10);
		}
		bool Insert(const pair<K, V>& kv) {
			if (Find(kv.first))
			{
				return false;
			}
			HashFunc hf;
			if (_n * 10 / _table.size() >= 7)
			{
				size_t newsize = _table.size() * 2;
				//遍历旧表，重新映射新表
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(newsize);
				for (size_t i = 0; i < _table.size(); i++)
				{
					//遍历旧表的数据重新插入即可
					if (_table[i]._state == EXIST)
					{
						newHT.Insert(_table[i]._kv);
					}
				}
				_table.swap(newHT._table);
			}
			size_t hashi = hf(kv.first) % _table.size();

			// 线性探测
			while (_table[hashi]._state == EXIST)
			{
				hashi++;
				// 如果走到vector的末尾，可以对hashi重新取模，到数组的首部
				hashi %= _table.size();
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;
			return true;
		}

		//返回的pair中的key应该不允许修改，所以返回const K
		HashData<const K, V>* Find(const K& key) {
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();

			// 线性探测
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state != EXIST && _table[hashi]._kv.first == key)
				{
					return (HashData<const K, V>*) & _table[hashi];
				}
				hashi++;
				// 如果走到vector的末尾，可以对hashi重新取模，到数组的首部
				hashi %= _table.size();
			}
			return nullptr;
		}
		bool Erase(const K& key) {
			HashData<const K, V>* ptr = Find(key);
			if (ptr)
			{
				ptr->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}

	private:
		vector<HashData<K, V>> _table;
		size_t _n = 0; // 存储有效数据的个数，以方便扩容
	};
}

namespace hash_bucket {
	

	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;
		typedef HTIterator<K, T, T*, T&, KeyOfT, HashFunc> iterator;

		Node* _node;
		const HashTable<K, T, KeyOfT, HashFunc>* _pht;

		/*HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}*/

		//普通迭代器，它是拷贝构造
		//const迭代器，它是构造
		HTIterator(Node* node, const HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		HTIterator(const iterator& iter)
			:_node(iter._node)
			,_pht(iter._pht)
		{}

		Self operator++() {
			KeyOfT kot;
			HashFunc hf;
			if (_node->_next)
			{
				_node = _node->_next;
				return *this;
			}
			else {
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();
				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else {
						++hashi;
					}
				}
				_node = nullptr;
				return *this;
			}
		}

		Ref operator*() {
			return _node->_data;
		}

		Ptr operator->() {
			return &_node->_data;
		}

		bool operator!=(const Self& s) {
			return _node != s._node;
		}

	};

	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable {
		template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, T*, T&, KeyOfT, HashFunc> iterator;
		typedef HTIterator<K, T, const T*, const T&, KeyOfT, HashFunc> const_iterator;
		HashTable() {
			_table.resize(10, nullptr);
			_n = 0;
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}

		iterator begin() {
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end() {
			return iterator(nullptr, this);
		}

		const_iterator begin() const {
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}
			return const_iterator(nullptr, this);
		}

		const_iterator end() const {
			return const_iterator(nullptr, this);
		}

		iterator Find(const K& key) {
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();

			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key) {
					return iterator(cur, this);
				}
				cur = cur->_next;
			}
			return iterator(nullptr, this);
		}

		pair<iterator, bool> Insert(const T& data) {
			HashFunc hf;
			KeyOfT kot;
			iterator it = Find(kot(data));
			if (it != end())
			{
				return make_pair(it, false);
			}
			if (_n == _table.size())
			{
				size_t newsize = _table.size() * 2;
				vector<Node*> newtable;
				newtable.resize(newsize, nullptr);
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						int hashi = hf(kot(cur->_data)) % newsize;
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
					//旧表设置为nullptr
					_table[i] = nullptr;
				}
				//旧表和新表进行交换
				_table.swap(newtable);
			}
			int hashi = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			it._node = newnode;
			it._pht = this;
			++_n;
			return make_pair(it, true);
		}

		bool Erase(const K& key) {
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (kot(cur->_data) == key) {
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else {
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		void Print() {
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				printf("[%d]->", i);
				while (cur)
				{
					cout << cur->_data.first << ":" << cur->_data.second << "->";
					cur = cur->_next;
				}
				cout << "NULL" << endl;
			}
			cout << endl;
		}
	private:
		vector<Node*> _table;
		int _n; //记录存储了多少个有效数据
	};

}