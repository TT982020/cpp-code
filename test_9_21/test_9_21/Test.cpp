#include <iostream>

using namespace std;
//class A
//{
//public:
//	A(int a = 0) {
//		cout << "A(int a)" << endl;
//		_a = a;
//	}
//	~A() {
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
////class Date
////{
////public:
////	/*Date(int year = 1, int month = 1, int day = 1) {
////		_year = year;
////		_month = month;
////		_day = day;
////	}*/
////
////	~Date();
////
////private:
////	int _year;
////	int _month;
////	int _day;
////
////	A _aa;
////};
////
////
////Date::~Date()
////{
////}
////
//////���A���ṩ���캯������Ҫʹ�ó�ʼ���б���
////int main() {
////	//Date d;
////	return 0;
////}
//
//
//
////////////////////////////////////////////////////////////
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// ��������...
//	/*~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}*/
//private:
//	// �������ͳ�Ա
//	DataType* _array;
//	int _capacity;
//	int _size;
//
//	//�Զ������ͳ�Ա
//	A _aa;
//};
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//}
//
//int main() {
//	TestStack();
//}



////////////////////////////////////��������  ��ֵ���أ���������أ�

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) {
//		cout << "Date(const Date& d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	~Date() {
//		cout << "~Date()" << endl;
//	}
//
//
//	void PrintDate() {
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	Stack(const Stack& s) {
//		cout << "Stack(const Stack& s)" << endl;
//		_array = (DataType*)malloc(sizeof(DataType) * s._capacity);
//		if (NULL == _array)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//			return;
//		}
//		memcpy(_array, s._array, sizeof(DataType) * s._size);
//		_capacity = s._capacity;
//		_size = s._size;
//
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// ��������...
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	// �������ͳ�Ա
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//class MyQueue
//{
//private:
//	Stack pops;
//	Stack pushs;
//};
//
//
//void fun1(Date d) {
//	d.PrintDate();
//}
//
////������s�ĸı䲻Ӱ��s1
//void fun2(Stack s) {
//	s.Push(1);
//	s.Push(2);
//}
//int main() {
//	/*Date d1(2023, 9, 21);
//	Stack s;
//	Stack s1(s);
//	fun1(d1);
//	fun2(s);*/
//	MyQueue mq;
//
//	MyQueue mq2 = mq;
//	return 0;
//}

///////////////////////////////////////////////////////////////////////
///////���������
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1) {
		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) {
		cout << "Date(const Date& d)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator<(const Date& d2) {
		if (_year < d2._year)
		{
			return true;
		}
		else if (_year == d2._year && _month < d2._month) {
			return true;
		}
		else if (_year == d2._year && _month == d2._month && _day < d2._day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator<=(const Date& d) {
		return *this < d || *this == d;
	}

	bool operator>(const Date& d) {
		return !(*this <= d);
	}

	bool operator>=(const Date& d) {
		return !(*this < d);
	}

	int GetMonthDay(int year, int month) {
		int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return days[month];
	}

	Date& operator+=(int day) {
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		//���������� ���������
		return *this;
	}

	//+ ���������ı䵱ǰ����
	Date operator+(int day) {
		Date tmp(*this);
		tmp += day;
		return tmp;
		//tmp._day += day;
		//while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		//{
		//	tmp._day -= GetMonthDay(tmp._year, tmp._month);
		//	tmp._month++;
		//	if (tmp._month == 13)
		//	{
		//		tmp._year++;
		//		tmp._month = 1;
		//	}
		//}
		////���������� ��������ڣ����Բ��ܷ������ã��ķ��ؿ�������ʱ����
		//return tmp;
	}

	~Date() {
		cout << "~Date()" << endl;
	}


	void PrintDate() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

};

//bool operator<(const Date& d1, const Date& d2) {
//	if (d1._year < d2._year)
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month < d2._month) {
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

int main() {
	Date d1(2023, 9, 22);
	Date d2(2022, 7, 21);
	int i = 10, j = 7;
	bool ret1 = i < j;
	bool ret2 = d1 < d2;
	cout << ret1 << "," << ret2 << endl;

	/*Date d3 = d2 += 100;
	d3.PrintDate();
	d2.PrintDate();*/

	Date d3 = d2 + 100;
	d3.PrintDate();
	d2.PrintDate();

}