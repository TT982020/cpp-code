#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
class student
{
public:
	
	void setId(int i) { id = i; }
	void setName(string n) { name = n; }
	void showStudent() {
		cout << "name = " << name << ", id=" << id << endl;
	}

private:
	string name;
	int id;
};
class Person
{
public:
	string name;

protected:
	string my_car;
private:
	int password;

public:
	void func() {
		name = "lis";
		my_car = "aaa";
		password = 124;
	}

};

class MyClass
{
	int a;
};


int main() {

	student stu;
	stu.setName("µÂÂêÎ÷ÑÇ");
	stu.setId(250);
	stu.showStudent();

	Person p;
	p.name = "hh";
	p.func();

	MyClass c;
	
	

	return 0;
}
