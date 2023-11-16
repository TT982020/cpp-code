#include<iostream>

using namespace std;
#include"HashTable.h"
#include "UnorderedMap.h"
#include "UnorderedSet.h"

//int main() {
//	unordered_set<int> us;
//	us.insert(3);
//	us.insert(1);
//	us.insert(4);
//	us.insert(2);
//	us.insert(30);
//
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//
//	unordered_map<string, string> um;
//	um["sort"] = "����";
//	um["left"] = "���";
//	um["string"] = "�ַ���";
//	for (const auto& e : um) {
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	cout << endl;
//}

//int main() {
//	int a[] = { 1,111,4,7,15,25,44,9 };
//	open_address::HashTable<int, int> ht;
//	for (size_t i = 0; i < sizeof(a)/sizeof(int); i++)
//	{
//		ht.Insert(make_pair(a[i], a[i]));
//	}
//	open_address::HashData<const int,int>* ret =  ht.Find(4);
//	//ret->_kv.first = 41;
//
//	//HashTable<string, string, StringHashFunc> ht1;
//	open_address::HashTable<string, string> ht1;
//	ht1.Insert(make_pair("sort", "����"));
//	ht1.Insert(make_pair("left", "���"));
//	ht1.Insert(make_pair("right", "�ұ�"));
//
//	return 0;
//}

//int main() {
//	hash_bucket::HashTable<int, int> ht;
//	int a[] = { 1,111,4,7,15,25,44,9 };
//	for (auto e : a) {
//		ht.Insert(make_pair(e, e));
//	}
//	ht.Print();
//	ht.Insert(make_pair(14, 14));
//	ht.Print();
//	ht.Insert(make_pair(24, 24));
//	ht.Print();
//
//	ht.Insert(make_pair(34, 34));
//	ht.Print();
//
//	ht.Erase(34);
//	ht.Print();
//
//	hash_bucket::HashTable<string, string> ht1;
//	ht1.Insert(make_pair("sort", "����"));
//	ht1.Insert(make_pair("left", "���"));
//	ht1.Insert(make_pair("right", "�ұ�"));
//	ht1.Insert(make_pair("insert", "����"));
//	ht1.Insert(make_pair("string", "�ַ���"));
//	ht1.Insert(make_pair("haha", "����"));
//
//	ht1.Print();
//}

int main() {
	my_set::unordered_set<int> s;
	s.insert(3);
	s.insert(12);
	s.insert(11);
	s.insert(9);
	s.insert(53);
	s.insert(5);
	my_set::unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;


	my_map::unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("right", "�ұ�"));
	dict.insert(make_pair("insert", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("haha", "����"));
	dict.print();

	my_map::unordered_map<string, string>::iterator iter = dict.begin();
	while (iter != dict.end())
	{
		cout << iter->first << ":" << iter->second << endl;
		++iter;
	}
	cout << endl;

	for (const auto& e : dict) {
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;
}