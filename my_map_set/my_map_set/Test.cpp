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
		cout << *iter << " ";
		++iter;
	}

	return 0;
}