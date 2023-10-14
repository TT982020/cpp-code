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

//class A
//{
//public:
//	int _a;
//};
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	return 0;
//}


//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void fun1() { 
//		cout << "Person::fun1()" << endl;
//	}
//	virtual void fun2() {
//		cout << "Person::fun2()" << endl;
//	}
//
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	virtual void fun3() { 
//		cout << "Student::fun3()" << endl;
//	}
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//void func() {
//	Person ps1;
//	Student st1;
//}
//
//typedef void(*FUNC_PTR)();
//
//void PrintVFT(FUNC_PTR* table) {
//	for (int i = 0; table[i] != nullptr; i++) {
//		printf("table[%d]=%p->", i, table[i]);
//		FUNC_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main() {
//	Person ps;
//	Student st;
//	long long fptr1 = *((long long*)(&ps));
//	long long fptr2 = *((long long*)(&st));
//
//	PrintVFT((FUNC_PTR*)fptr1);
//	PrintVFT((FUNC_PTR*)fptr2);
//
//
//}
//int main()
//{
//	Person ps;
//	Student st;
//
//	//func();
//
//	int a = 0;
//	printf("栈:%p\n", &a);
//
//	int* b = new int;
//	printf("堆:%p\n", b);
//
//	static int c = 0;
//	printf("静态区:%p\n", &c);
//
//	const char* str = "hello";
//	printf("常量字符串:%p\n", str);
//
//	const int d = 0;
//	printf("常量数据:%p\n", &d);
//	printf("代码段:%p\n", &Func);
//
//
//
//	printf("虚表1:%p\n", *((int*)(& ps)));
//	printf("虚表2:%p\n", *((int*)(& st)));
//
//}

//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private: int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*FUNC_PTR)();
//
//void PrintVFT(FUNC_PTR* table) {
//	for (int i = 0; table[i] != nullptr; i++) {
//		printf("table[%d]=%p->", i, table[i]);
//		FUNC_PTR f = table[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Derive d;
//	FUNC_PTR* vTableb1 = (FUNC_PTR*)(*(long long*)&d);
//	PrintVFT(vTableb1);
//	FUNC_PTR* vTableb2 = (FUNC_PTR*)(*(long long*)((char*)&d + sizeof(Base1)));
//	PrintVFT(vTableb2);
//	return 0;
//}


///////////////////////////////////菱形继承
//class A
//{
//public:
//    virtual void func1() {
//        cout << "A::func1()" << endl;
//    }
//    int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//    virtual void func1() {
//        cout << "B::func1()" << endl;
//    }
//    virtual void func2() {
//        cout << "B::func2()" << endl;
//    }
//    int _b;
//};
////class C : public A
//class C : virtual public A
//{
//public:
//    virtual void func1() {
//        cout << "C::func1()" << endl;
//    }
//    virtual void func2() {
//        cout << "C::func2()" << endl;
//    }
//    int _c;
//};
//class D : public B, public C
//{
//public:
//    virtual void func1() {
//        cout << "D::func1()" << endl;
//    }
//    int _d;
//};
//int main()
//{
//    D d;
//    d.B::_a = 1;
//    d.C::_a = 2;
//    d._b = 3;
//    d._c = 4;
//    d._d = 5;
//    return 0;
//}

////////////////////////////////////////抽象类
//纯虚函数：间接强制派生类重写虚函数
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//
//int main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

class Person
{
public:
	Person() {

	}
	~Person() {}
	virtual void fun() {
		cout << "Person::fun()" << endl;
	}

private:

};

class Student: public Person
{
public:

private:

};


int main() {
	Person ps;
	Student st;
}
