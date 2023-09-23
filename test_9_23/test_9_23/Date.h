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
	//�������캯������һ���Ѿ����ڵĶ��󣬳�ʼ����һ��Ҫ��������
	//Date(const Date& d);


	//��ֵ��������أ������Ѿ����ڵĶ���
	//Ϊ��֧�� d1 = d2 = d3����������һ���������ã���Ϊ����������this����
	// d1 = d1 ���Թ���Ҫ��һ���Ľ�
	Date& operator=(const Date& d);
	~Date();

	//�ܽ�һ�£�ֻ���������Լ�const���ڲ�������޸ĳ�Ա����const�ĺô���const�ͷ�const���󶼿��Ե�
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

	//�ճ��Զ����ɵľͿ���
	//���뱻ȡ����Ч��ַ
	Date* operator&();

	const Date* operator&() const;
private:
	int year_;
	int month_;
	int day_;
};

//class MyQueue
//{
//	//Ĭ�Ϲ����������������죬��ֵ���ض�����Ҫд
//private:
//	Stack st1;
//	Stack st2;
//};
