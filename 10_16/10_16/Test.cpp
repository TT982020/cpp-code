#include <iostream>
#include <list>
#include <functional>
using namespace std;

//int main() {
//	int x = 0, y = 2;
//	double rate = 2.5;
//	auto add1 = [](int x, int y)->int {return x + y; };
//	auto add2 = [](int x, int y) {return x + y; };
//	auto add3 = [rate](int x, int y)->int {return (x + y) * rate; };
//
//	auto swap = [](int& x, int& y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//		};
//
//	swap(x, y);
//
//	//mutable让捕获的变量可以修改，但他们依然是x和y的拷贝
//	auto swap1 = [x, y]() mutable {
//		int tmp = x;
//		x = y;
//		y = tmp;
//		};
//	swap1();
//}
////////////////////////////  模板可变参数
//template<class T>
//void _ShowList(T val) {
//	cout << val << " ";
//	cout << endl;
//}


//void _ShowList() {
//	cout << endl;
//}
//
//
//template<class T,class ...Args>
//void _ShowList(T val, Args... args) {
//	cout << val << " ";
//	_ShowList(args...);
//}
//
////Args... 表示0-N个参数包
//template<class ...Args>
//void CppPrint(Args... args) {
//	_ShowList(args...);
//}
//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
////展开函数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//
//int main() {
//	CppPrint();
//	CppPrint(1);
//	CppPrint(1,2);
//	CppPrint(1,2,"xx");
//
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//
//	return 0;
//}

//class Date {
//public:
//	Date(int year = 2020, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day){}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<class ...Args>
//Date* Create(Args... args) {
//	Date* ret = new Date(args...);
//	return ret;
//}
//
//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{} Person(Person && p) = default;
//private:
//	string _name;
//	int _age;
//};
//
//
//int main() {
//	Date* d1 = Create(2023, 10, 17);
//	Date* d2 = Create(2023, 10);
//	Date* d3 = Create();
//	Date d4(2023, 10, 17);
//	Date* d5 = Create(d4);
//
//	std::list<std::pair<int, string>> mylist;
//	mylist.emplace_back(10, "a");
//	mylist.emplace_back(20, "b");
//
//	mylist.push_back(make_pair(10, "a"));
//	mylist.push_back({ 30,"b"});
//
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	return 0;
//	
//	return 0;
//
//}

////////////////////////////  包装器
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{ // 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}


/////////////////////////////////////包装器
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

int Sub(int a, int b) {
	return a - b;
}

double Plus(int a, int b, double rate) {
	return (a + b) * rate;
}

double PPlus(int a, double rate, int b) {
	return (a + b) * rate;
}

class SubType {
public:
	static int sub(int x, int y) {
		return x - y;
	}
	int ssub(int x, int y, int rate) {
		return (x - y) * rate;
	}
};

int main()
{ // 函数名
	cout << useF(f, 11.11) << endl;
	// 函数对象
	cout << useF(Functor(), 11.11) << endl;
	// lamber表达式
	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;

	list <function<double(double)>> lst = { f,Functor(), [](double x) {return x / 4; } };
	double n = 10.0;
	for (auto f : lst) {
		cout << f(n) << endl;
	}

	function<int(int, int)> rsub = bind(Sub, placeholders::_1, placeholders::_2);
	cout << rsub(1, 2) << endl;

	function<double(int, int)> plus1 = bind(Plus, placeholders::_1, placeholders::_2, 4.0);
	function<double(int, int)> plus2 = bind(Plus, placeholders::_1, placeholders::_2, 4.2);
	function<double(int, int)> plus3 = bind(Plus, placeholders::_1, placeholders::_2, 4.3);
	cout << plus1(5, 3) << endl;
	cout << plus2(5, 3) << endl;
	cout << plus3(5, 3) << endl;

	function<double(int, int)> pplus1 = bind(PPlus, placeholders::_1, 4.0, placeholders::_2);
	function<double(int, int)> pplus2 = bind(PPlus, placeholders::_1, 4.2, placeholders::_2);
	function<double(int, int)> pplus3 = bind(PPlus, placeholders::_1, 4.3, placeholders::_2);
	cout << pplus1(5, 3) << endl;
	cout << pplus2(5, 3) << endl;
	cout << pplus3(5, 3) << endl;

	function<int(int, int)> sub1 = bind(&SubType::sub, placeholders::_1, placeholders::_2);
	SubType st;
	function<int(int, int)> sub2 = bind(&SubType::ssub, &st, placeholders::_1, placeholders::_2, 4.0);
	function<int(int, int)> sub3 = bind(&SubType::ssub, SubType(), placeholders::_1, placeholders::_2, 4.0);
	cout << sub1(2, 3) << endl;
	cout << sub2(2, 3) << endl;
	cout << sub3(2, 3) << endl;

	return 0;
}