#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main() {
//	cout << __cplusplus << endl;
//}
class A
{
public:
	A() {};
	~A() {};
	virtual void vfunc1();
	virtual void vfunc2();
	void func1();
	void func2();

private:
	int m_data1, m_data2;
};
void A::vfunc1() {
	cout << "A::vfunc1" << endl;
}
void A::vfunc2() {
	cout << "A::vfunc2" << endl;
}
void A::func1() {
	cout << "A::func1" << endl;
}
void A::func2() {
	cout << "A::func2" << endl;
}
class B: public A
{
public:
	B() {};
	~B() {};
	virtual void vfunc1();
	void func2();

private:
	int m_data3;
};
void B::vfunc1() {
	cout << "B::vfunc1" << endl;
}
void B::func2() {
	cout << "B::func2" << endl;
}
class C:public B
{
public:
	C() {};
	~C() {};
	virtual void vfunc1();
	void func2();
private:
	int m_data1, m_data4;
};

void C::vfunc1() {
	cout << "C::vfunc1" << endl;
}
void C::func2() {
	cout << "C::func2" << endl;
}
int main() {
	A a;
	a.func1(); 
	a.func2();
	a.vfunc1();
	a.vfunc2();

	B b;
	b.func1(); //a func1
	b.func2(); //b func2
	b.vfunc1(); //b vfunc1
	b.vfunc2(); //a vfunc2

	C c;
	c.func1();  //a func1
	c.func2();  //c func2
	c.vfunc1(); //c vfunc1
	c.vfunc2(); //a vfunc2
}
