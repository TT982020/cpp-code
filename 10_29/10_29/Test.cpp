#include<iostream>
#include <map>
#include <set>
using namespace std;

void test_set1() {
	set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(2);
	s.insert(3);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	auto pos = s.find(3);
	//��Ҫ�������find��ʱ�临�Ӷ��ΪO(N),ʹ��set��find��������ĸ߶�
	//find(s.begin(), s.end(), 3);
	if (pos != s.end())
		s.erase(pos);

	for (auto e : s) {
		cout << e << " ";
	}
	cout << endl;

	s.erase(2);
	for (auto e : s) {
		cout << e << " ";
	}
}

int main() {
	test_set1();
}