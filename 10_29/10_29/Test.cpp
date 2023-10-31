#include<iostream>
#include <map>
#include <set>
using namespace std;

void test_set1() {
	//ȥ��+����
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

	std::set<int> myset;
	std::set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	// [30��60]���ᱻɾ��
	itlow = myset.lower_bound(30);                //       ^
	itup = myset.upper_bound(60);                 //                   ^

	// [itlow, itup)
	myset.erase(itlow, itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	auto ret = myset.equal_range(80);
	cout << *ret.first << endl;
	cout << *ret.second << endl;
}

void test_set2() {
	multiset<int> set;
	set.insert(1);
	set.insert(2);
	set.insert(2);
	set.insert(4);
	set.insert(5);
	set.insert(3);
	set.insert(3);
	
	for (auto e : set) {
		cout << e << " ";
	}
	cout << endl;
	//��������ĵ�һ��7
	auto pos = set.find(3);
	while (pos != set.end())
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;

	auto ret = set.equal_range(5);
	set.erase(ret.first, ret.second);
	for (auto e : set) {
		cout << e << " ";
	}
	cout << endl;
}

void test_map1() {
	map<string, string> dict;
	pair<string, string> kv1("hello", "���");
	dict.insert(make_pair("insert", "����"));
	dict.insert(pair<string, string>("bye", "�ټ�"));
	dict.insert(make_pair("sort", "����"));

	//�������ʽ����ת��
	dict.insert({ "string","�ַ���" });
}


void test_map2() {
	map<string, string> dict;
	dict.insert({ "string","�ַ���" });
	dict.insert({ "insert","����" });
	dict.insert({ "sort","����" });

	//�����룬�����ǣ���������У�ֻ�Ƚ�key��value����ͬ������ν
	//key �Ѿ����˾Ͳ�������
	dict.insert({ "sort","����xxx" });

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		//it->first = "xx";
		it->second = "xxx";
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

}

void test_map3() {
	map<string, int> countMap;
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "�㽶" };
	for (const auto& str : arr)
	{
		countMap[str]++;
		/*auto ret = countMap.find(str);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			countMap.insert({ str, 1 });
		}*/
	}
	for (auto e : countMap) {
		cout << e.first << ":" << e.second << endl;
	}
}


int main() {
	//test_set1();
	test_map2();
}