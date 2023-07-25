#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __TEST_H__

#include <iostream>
using namespace std;

class Base;
class Derived;
class Component;
class Component
{
public:
	Component();
	~Component();

private:

};

Component::Component()
{
	cout << "Component ctor" << endl;
}

Component::~Component()
{
	cout << "Component dtor" << endl;
}

class Base
{
public:
	Base() { cout << "base ctor" << endl; };
	~Base() { cout << "base dtor" << endl; };
private:
	Component com;
};
class Derived: public Base
{
public:
	Derived();
	~Derived();
	
private:
	

};

Derived::Derived()
{
	cout << "Derived ctor" << endl;
}

Derived::~Derived()
{
	cout << "Derived dtor" << endl;
}



#endif // !__TEST_H__
