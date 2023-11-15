#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;
#include"HashTable.h"

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
//	um["sort"] = "ÅÅĞò";
//	um["left"] = "×ó±ß";
//	um["string"] = "×Ö·û´®";
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
//	ht1.Insert(make_pair("sort", "ÅÅĞò"));
//	ht1.Insert(make_pair("left", "×ó±ß"));
//	ht1.Insert(make_pair("right", "ÓÒ±ß"));
//
//	return 0;
//}

int main() {
	hash_bucket::HashTable<int, int> ht;
	int a[] = { 1,111,4,7,15,25,44,9 };
	for (auto e : a) {
		ht.Insert(make_pair(e, e));
	}
	ht.Print();
	ht.Insert(make_pair(14, 14));
	ht.Print();
	ht.Insert(make_pair(24, 24));
	ht.Print();

	ht.Insert(make_pair(34, 34));
	ht.Print();

	ht.Erase(34);
	ht.Print();

	hash_bucket::HashTable<string, string> ht1;
	ht1.Insert(make_pair("sort", "ÅÅĞò"));
	ht1.Insert(make_pair("left", "×ó±ß"));
	ht1.Insert(make_pair("right", "ÓÒ±ß"));
	ht1.Insert(make_pair("insert", "²åÈë"));
	ht1.Insert(make_pair("string", "×Ö·û´®"));
	ht1.Insert(make_pair("haha", "¹ş¹ş"));

	ht1.Print();
}