#include <iostream>
#include <queue>
#include <deque>

using namespace std;
#include "Stack.h"
#include "Queue.h"
#include "priority_queue.h"

//int main() {
//	B::queue<int, list<int>> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(14);
//
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}
//	cout << endl;
//}
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

class DateCompare {
public:
	bool operator()(Date* d1, Date* d2) {
		return *d1 > *d2;
	}
};

void test_date() {
	// 大堆，需要用户在自定义类型中提供<的重载
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;

	priority_queue<Date*, vector<Date*>, DateCompare> q2;
	q2.push(new Date(2018, 10, 29));
	q2.push(new Date(2018, 10, 28));
	q2.push(new Date(2018, 10, 30));
	cout << *(q2.top()) << endl;
}

void test_priority_queue() {
	//插入删除的效率logn
	//priority_queue<int> q;//大堆
	C::priority_queue<int, vector<int>, C::Less<int>> q;//小堆
	q.push(3);
	q.push(1);
	q.push(5);
	q.push(4);
	while (!q.empty())
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;

	C::Less<int> less1;
	C::Less<double> less2;
	cout << less1(1, 2) << endl;
	cout << less2(1.1, 2.2) << endl;
}
int main() {
	//test_priority_queue();
	test_date();

}