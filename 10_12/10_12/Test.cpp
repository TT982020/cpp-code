#include <iostream>
using namespace std;
// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化  
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name=" << _name << endl;
//		cout << "age=" << _age << endl;
//	}
//protected:
//	string _name; // 姓名
//	int _age; // 年龄
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher:public Person
//{
//protected:
//	int _jobid;
//};
//
//
//int main() {
//
//	int i = 0;
//	//double d = 1.0;
//	const double& d = i;
//
//	Person p;
//	Teacher t;
//	p = t;
//	//赋值兼容，切片，不会产生中间临时变量
//	Person p1 = t;
//	Person& p2 = t;
//
//	//t = (Teacher)p;  //强制类型转换也不行
//}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//public:
//	void fun() {
//		cout << "class Person" << endl;
//	}
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111;    //身份证号
//};
//class Student : public Person
//{
//public:
//	void fun(int i) {
//		cout << "class Student : public Person" << endl;
//	}
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main() {
//	Student s1;
//	s1.Print();
//	s1.fun(1);
//	s1.Person::fun();
//}

//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person & p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
//void Test()
//{
//	Student s1("jack", 18); 
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//
//int main() {
//	Test();
//}

class A
{
public:
	int _a;
};
//class B : public A
class B : virtual public A
{
public:
	int _b;
};
//class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}

