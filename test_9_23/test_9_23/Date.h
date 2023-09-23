#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month) const;
	Date(int year = 1, int month = 1, int day = 1);
	void Print() const;
	void Print();
	//拷贝构造函数，用一个已经存在的对象，初始化另一个要创建对象
	//Date(const Date& d);


	//赋值运算符重载，两个已经存在的对象
	//为了支持 d1 = d2 = d3，函数返回一个对象引用，因为出了作用域this还在
	// d1 = d1 可以过需要进一步改进
	Date& operator=(const Date& d);
	~Date();

	//总结一下，只读函数可以加const，内部不设计修改成员。加const的好处是const和非const对象都可以调
	bool operator<(const Date& d2) const;

	bool operator==(const Date& d) const;

	bool operator!=(const Date& d) const;

	bool operator<=(const Date& d) const;

	bool operator>(const Date& d) const;

	bool operator>=(const Date& d) const;

	Date& operator+=(int day);

	Date operator+(int day) const;

	Date& operator-=(int day);

	Date operator-(int day) const;

	Date& operator++();

	Date operator++(int);

	Date& operator--();

	Date operator--(int);

	int operator-(const Date& d) const;

	//日常自动生成的就可以
	//不想被取到有效地址
	Date* operator&();

	const Date* operator&() const;
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
