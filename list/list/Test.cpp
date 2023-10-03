#include <iostream>
#include <list>
using namespace std;
#include "list.h"
void test_list1() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list2() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;

	lt.reverse();

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	lt.sort();

	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;

	lt.sort(greater<int>());
	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}
void test_list4() {
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(5);
	lt.push_back(5);
	lt.push_back(5);
	lt.push_back(3);

	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;

	lt.sort();
	lt.unique(); //去重，去重前需要sort有序

	for (auto e : lt) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	//test_list4();

	name::test_list3();
}