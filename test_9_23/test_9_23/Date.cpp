#include "Date.h"

int Date::GetMonthDay(int year, int month) {
	static const int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return days[month];
}
Date::Date(int year, int month, int day) {
	if (month < 1 || month>12 || day<1 || day>GetMonthDay(year, month))
	{
		cout << "ÈÕÆÚ´íÎó" << endl;
	}
	year_ = year;
	month_ = month;
	day_ = day;
}
void Date::Print() const {
	cout << year_ << "-" << month_ << "-" << day_ << endl;
}

Date::~Date() {
	cout << "~Date();" << endl;
}

Date& Date::operator=(const Date& d) {
	if (this != &d)
	{
		year_ = d.year_;
		month_ = d.month_;
		day_ = d.day_;
	}
	return *this;
}

bool Date::operator<(const Date& d2) {
	if (year_ < d2.year_)
	{
		return true;
	}
	else if (year_ == d2.year_ && month_ < d2.month_) {
		return true;
	}
	else if (year_ == d2.year_ && month_ == d2.month_ && day_ < d2.day_) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator==(const Date& d) {
	return year_ == d.year_ && month_ == d.month_ && day_ == d.day_;
}

bool Date::operator!=(const Date& d) {
	return !(*this == d);
}

bool Date::operator<=(const Date& d) {
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) {
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) {
	return !(*this < d);
}

Date& Date::operator+=(int day) {
	if (day < 0)
	{
		return *this -= (-day);
	}
	day_ += day;
	while (day_ > GetMonthDay(year_, month_))
	{
		day_ -= GetMonthDay(year_, month_);
		month_++;
		if (month_ == 13)
		{
			month_ = 1;
			year_++;
		}
	}
	return *this;
}

Date Date::operator+(int day) {
	Date tmp(*this);
	tmp += day;
	return tmp;
}

//Date& Date::operator+=(int day) {
//	*this = *this + day;
//	return *this;
//}
//
//Date Date::operator+(int day) {
//	Date tmp(*this);
//	tmp.day_ += day;
//	while (tmp.day_ > GetMonthDay(tmp.year_, tmp.month_))
//	{
//		tmp.day_ -= GetMonthDay(tmp.year_, tmp.month_);
//		tmp.month_++;
//		if (tmp.month_ == 13)
//		{
//			tmp.month_ = 1;
//			tmp.year_++;
//		}
//	}
//	return tmp;
//}


Date& Date::operator-=(int day) {
	if (day < 0)
	{
		return *this += (-day);
	}
	day_ -= day;
	while (day_ <= 0)
	{
		month_--;
		if (month_ == 0)
		{
			year_--;
			month_ = 12;
		}
		day_ += GetMonthDay(year_, month_);
	}
	return *this;
}

Date Date::operator-(int day) {
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++() {
	*this += 1;
	return *this;
}

Date Date::operator++(int) {
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--() {
	*this -= 1;
	return *this;
}

Date Date::operator--(int) {
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date& d) {
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}