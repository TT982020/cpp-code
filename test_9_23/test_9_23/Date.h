#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	Date(int year = 1, int month = 1, int day = 1);
	void Print() const;
	//拷贝构造函数，用一个已经存在的对象，初始化另一个要创建对象
	//Date(const Date& d);


	//赋值运算符重载，两个已经存在的对象
	//为了支持 d1 = d2 = d3，函数返回一个对象引用，因为出了作用域this还在
	// d1 = d1 可以过需要进一步改进
	Date& operator=(const Date& d);
	~Date();

	bool operator<(const Date& d2);

	bool operator==(const Date& d);

	bool operator!=(const Date& d);

	bool operator<=(const Date& d);

	bool operator>(const Date& d);

	bool operator>=(const Date& d);

	Date& operator+=(int day);

	Date operator+(int day);

	Date& operator-=(int day);

	Date operator-(int day);

	Date& operator++();

	Date operator++(int);

	Date& operator--();

	Date operator--(int);

	int operator-(const Date& d);
private:
	int year_;
	int month_;
	int day_;
};

//class MyQueue
//{
//	//默认构造析构，拷贝构造，赋值重载都不需要写
//private:
//	Stack st1;
//	Stack st2;
//};
