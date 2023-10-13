#include <iostream>
#include <vector>
#include <list>
#include <array>

using namespace std;
template<class Container>
void Print(const Container& con) {
	typename Container::const_iterator it = con.begin();
	while (it != con.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//非类型模板参数
template<class T, size_t N>
class Stack
{
private:
	T _a[N];
	int _size;
};

template<class T>
bool Less(T left, T right) {
	return left < right;
}


bool Less(int* left, int* right) {
	return *left < *right;
}

template<class T>
bool Less(T* left, T* right) {
	return *left < *right;
}

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y) {
		return x < y;
	}
};

template<class T>
class Less<T*>
{
public:
	bool operator()(const T* x, const T* y) {
		return *x < *y;
	}
};

template<class T1, class T2>
class Date
{
public:
	Date() {
		cout << "class T1, class T2" << endl;
	}
	template<>
	class Less<Date*>
	{
	public:
		bool operator()(const Date* x, const Date* y) {
			return *x < *y;
		}
	};

private:
	T1 _a;
	T1 _b;
};

template<>
class Date<int, double>
{
public:
	Date() {
		cout << "Date<int, double>" << endl;
	}

private:
};


template<class T1>
class Date<T1, double>
{
public:
	Date() {
		cout << "Date<int, double>" << endl;
	}
private:
};

template<class T1, class T2>
class Date<T1*, T2*>
{
public:
	Date() {
		cout << "Date<T1*, T2*>" << endl;
	}
private:
};




//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	Print(v);
//
//	Stack<int, 10> st1;
//	Stack<double, 10> st1;
//	array<int, 10> arr;
//}

int main() {
	Date<int, int> d1;
	Date<int, double> d2;
}