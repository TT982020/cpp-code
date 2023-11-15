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
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;
		HashNode(const pair<K,V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable {
		typedef HashNode<K, V> Node;
	public:
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

		Node* Find(const K& key) {
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();

			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_kv.first == key) {
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv) {
			HashFunc hf;
			if (Find(kv.first))
			{
				return false;
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
						int hashi = hf(cur->_kv.first) % newsize;
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
			int hashi = hf(kv.first) % _table.size();
			Node* newnode = new Node(kv);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}

		bool Erase(const K& key) {
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (cur->_kv.first == key) {
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else {
						prev->_next = cur->_next;
					}
					delete cur;
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
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
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