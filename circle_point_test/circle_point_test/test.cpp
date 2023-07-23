#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;
class Point
{
public:
	Point(int xx, int yy) :x(xx), y(yy) {};
	~Point() {};
	int getx() const { return x; }
	int gety() const { return y; }
private:
	int x;
	int y;
};


class Circle
{
public:
	Circle(Point pp, int rr) :p(pp), r(rr) {};
	~Circle() {};
	void func(const Point p){
		double dis = sqrt(pow(this->p.getx() - p.getx(), 2) + pow(this->p.gety() - p.gety(), 2));
		if (dis>r)
		{
			cout << "Ô²Íâ" << endl;
		}
		else if (dis < r) {
			cout << "Ô²ÄÚ" << endl;
		}
		else {
			cout << "Ô²ÉÏ" << endl;
		}
	}

private:
	Point p;
	int r;
};

int main() {
	Point p1(0, 0);
	int r = 2;
	Circle c(p1, r);
	Point p2(0, 0);
	c.func(p2);
}