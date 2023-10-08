#include <iostream>
#include <queue>
#include <deque>
#include <array>

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

template<class T>
class DateCompare {
public:
	bool operator()(T d1, T d2) {
		return d1 > d2;
	}
};


template<>
class DateCompare<Date*> {
public:
	bool operator()(Date* d1, Date* d2) {
		return *d1 < *d2;
	}
};

void test_date() {
	// 大堆，需要用户在自定义类型中提供<的重载
	C::priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << q1.top() << endl;

	//c::priority_queue<Date*, vector<Date*>, DateCompare<Date*>> q2;
	C::priority_queue<Date*> q2;
	q2.push(new Date(2018, 10, 29));
	q2.push(new Date(2018, 10, 28));
	q2.push(new Date(2018, 10, 30));
	cout << *(q2.top()) << endl;
}

void test_priority_queue() {
	//插入删除的效率logn
	//priority_queue<int> q;//大堆
	C::priority_queue<int, vector<int>, C::Less<int>> q;//大堆
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

template<class T, size_t N>
class Stack
{
private:
	T _a[N];
};

//模板特化：针对某些类型进行特殊化处理
template<class T1,class T2>
class Date1
{
public:
	Date1() {
		cout << "Date(T1,T2)" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//全特化
template<>
class Date1<int,double>
{
public:
	Date1() {
		cout << "Date(int,double)" << endl;
	}
private:
};

//偏特化
template<class T1>
class Date1<T1, double>
{
public:
	Date1() {
		cout << "Date(T1, double)" << endl;
	}
private:
};

template<class T1, class T2>
class Date1<T1*, T2*>
{
public:
	Date1() {
		cout << "Date(T1, double)" << endl;
	}
private:
};

template<class T>
class DateCompare<T*> {
public:
	bool operator()(T* d1, T* d2) {
		return *d1 > *d2;
	}
};

int main() {
	test_priority_queue();
	//test_date();
	//Stack<int, 10> st;

	//array<int, 10> a;  //多了越界检查
	//vector<int> v(10, 0);

	//Date1<int, int> d1;
	//Date1<int, double> d2;
	//Date1<double, double> d2;
	//Date1<double*, double*> d2;
	//Date1<int*, double*> d2;

}