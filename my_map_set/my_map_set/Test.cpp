#include "myset.h"
#include "mymap.h"
using namespace std;
int main() {
	name_map::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 3));
	m.insert(make_pair(3, 5));


	name_set::set<int> s;
	s.insert(11);
	s.insert(101);
	s.insert(21);
	s.insert(2);
	s.insert(21);
	s.insert(24);

	name_map::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//it->first = 1;
		it->second = 2;
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	cout << endl;

	for (const auto& e : m) {
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl;

	name_set::set<int>::iterator iter = s.begin();
	while (iter != s.end())
	{
		//(*iter)+=2;
		cout << *iter << " ";
		++iter;
	}
	cout << endl;

	name_map::map<string, string> dict;
	dict.insert(make_pair("sort", "xxx"));//²åÈë
	dict["left"];  // ²åÈë
	dict["left"] = "×ó±ß";  //ĞŞ¸Ä
	dict["sort"] = "ÅÅĞò";  //ĞŞ¸Ä
	dict["right"] = "ÓÒ±ß"; //²åÈë+ĞŞ¸Ä

	for (const auto& each : dict) {
		cout << each.first << ":" << each.second << endl;
	}

	return 0;
}