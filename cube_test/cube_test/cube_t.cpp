#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Cube;
bool is_Equal(const Cube& c1, const Cube& c2);
class Cube
{
public:
	Cube();
	~Cube();
	double getV() const { return a * a * a; }
	double getArea() const { return 6 * a * a; }
	void setA(int aa) { a = aa; }
	bool is_equal(const Cube& c) {
		return this->a = c.a;
	}
	friend bool is_Equal(const Cube& c1, const Cube& c2);
private:
	double a;
};

Cube::Cube()
{
}

Cube::~Cube()
{
}
bool is_Equal(const Cube& c1, const Cube& c2) {
	return c1.a == c2.a;
}

int main() {
	Cube c;
	c.setA(5);
	cout << c.getArea() << endl;
	cout << c.getV() << endl;
	Cube c2;
	c2.setA(5);
	cout<< c.is_equal(c2) << endl;
	cout << is_Equal(c, c2) << endl;
}