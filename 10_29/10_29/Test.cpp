#include<iostream>
#include <map>
#include <set>
using namespace std;

void test_set1() {
	//去重+排序
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
	//不要用下面的find，时间复杂度最坏为O(N),使用set的find最差是树的高度
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

	// [30到60]都会被删除
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
	//返回中序的第一个7
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
	pair<string, string> kv1("hello", "你好");
	dict.insert(make_pair("insert", "插入"));
	dict.insert(pair<string, string>("bye", "再见"));
	dict.insert(make_pair("sort", "排序"));

	//多参数隐式类型转换
	dict.insert({ "string","字符串" });
}


void test_map2() {
	map<string, string> dict;
	dict.insert({ "string","字符串" });
	dict.insert({ "insert","插入" });
	dict.insert({ "sort","排序" });

	//不插入，不覆盖；插入过程中，只比较key，value是相同的无所谓
	//key 已经有了就不插入了
	dict.insert({ "sort","排序xxx" });

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
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "香蕉" };
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