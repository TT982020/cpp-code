#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class Shape
{
public:
	Shape() {};
	~Shape() {};
	virtual void draw();
	virtual void func2();
	int geti() const { return i1; }
private:
	int i1 = 1;
};
void Shape::draw() {
	cout << "shape draw" << endl;
}

void Shape::func2() {

}

class Rec
{
public:
	Rec() {};
	~Rec() {};
	virtual void draw();
	int geti() const { return i2; }

private:
	int i2 = 2;
};
void Rec::draw() {
	cout << "rectangle draw" << endl;
}

class Square
{
public:
	Square() {};
	~Square() {};
	virtual void draw();
	int geti() const { return i3; }

private:
	int i3 = 3;
};

void Square::draw() {
	cout << "Square draw" << endl;
}

int main() {
	list<Shape*> lst;
	Rec r;
	Square q;
	lst.push_back((Shape*) & r);
	lst.push_back((Shape*) & q);

	for (auto a : lst) {
		a->draw();
		//cout << a->geti() << endl;
	}
}
