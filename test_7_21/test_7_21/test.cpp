#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
int main() {
	float f = 3.1415926f;
	double d = 3.1415926;
	cout << "f = " << f << endl;;
	cout << "d = " << d << endl;;

	//科学计数法
	float f2 = 3e2;
	cout << "f2=" << f2 << endl;

	float f3 = 3e-2;
	cout << "f3=" << f3 << endl;

	cout << "\\" << endl;
	cout << "\tHello" << endl;
	cout << "\n" << endl;


	cout << "aaaaa\thello" << endl;
	cout << "aa\thello" << endl;
	cout << "aaa\thello" << endl;

	string s = "hello,world.";
	cout << "s=" << s << endl;


	bool flag = true;
	cout << flag << endl;
	flag = false;
	cout << flag << endl;

	cout << sizeof(bool) << endl; //1个字节


}