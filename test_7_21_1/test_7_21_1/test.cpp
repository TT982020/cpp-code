#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//int main() {
//	//int a = 0;
//	//cout << "请输入整型变量：" << endl;
//	//cin >> a;
//	//cout << a << endl;
//
//	////浮点型输入
//	//double d = 0;
//	//cout << "请输入浮点型变量：" << endl;
//	//cin >> d;
//	//cout << d << endl;
//
//	////字符型输入
//	//char ch = 0;
//	//cout << "请输入字符型变量：" << endl;
//	//cin >> ch;
//	//cout << ch << endl;
//
//	////字符串型输入
//	//string str;
//	//cout << "请输入字符串型变量：" << endl;
//	//cin >> str;
//	//cout << str << endl;
//
//	////布尔类型输入
//	//bool flag = true;
//	//cout << "请输入布尔型变量：" << endl;
//	//cin >> flag;
//	//cout << flag << endl;
//
//	int i1 = 10;
//	int i2 = 3;
//	cout << i1 / i2 << endl;
//
//	double d1 = 0.5;
//	double d2 = 0.22;
//	cout << d1 / d2 << endl;
//}

//int main() {
//	int a1 = 10;
//	int b1 = 3;
//
//	cout << 10 % 3 << endl;
//
//	int a2 = 10;
//	int b2 = 20;
//
//	cout << a2 % b2 << endl;
//
//	int a3 = 10;
//	int b3 = 0;
//
//	//cout << a3 % b3 << endl; //取模运算时，除数也不能为0
//
//	//两个小数不可以取模
//	double d1 = 3.14;
//	double d2 = 1.1;
//
//	//cout << d1 % d2 << endl;
//
//	system("pause");
//}


//int main() {
//
//	//后置递增
//	int a = 10;
//	a++; //等价于a = a + 1
//	cout << a << endl; // 11
//
//	//前置递增
//	int b = 10;
//	++b;
//	cout << b << endl; // 11
//
//	//区别
//	//前置递增先对变量进行++，再计算表达式
//	int a2 = 10;
//	int b2 = ++a2 * 10;
//	cout << b2 << endl;
//
//	//后置递增先计算表达式，后对变量进行++
//	int a3 = 10;
//	int b3 = a3++ * 10;
//	cout << b3 << endl;
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	//赋值运算符
//
//	// =
//	int a = 10;
//	a = 100;
//	cout << "a = " << a << endl;
//
//	// +=
//	a = 10;
//	a += 2; // a = a + 2;
//	cout << "a = " << a << endl;
//
//	// -=
//	a = 10;
//	a -= 2; // a = a - 2
//	cout << "a = " << a << endl;
//
//	// *=
//	a = 10;
//	a *= 2; // a = a * 2
//	cout << "a = " << a << endl;
//
//	// /=
//	a = 10;
//	a /= 2;  // a = a / 2;
//	cout << "a = " << a << endl;
//
//	// %=
//	a = 10;
//	a %= 2;  // a = a % 2;
//	cout << "a = " << a << endl;
//
//	system("pause");
//
//	return 0;
//}


//int main() {
//
//	int a = 10;
//	int b = 20;
//
//	cout << (a == b) << endl; // 0 
//
//	cout << (a != b) << endl; // 1
//
//	cout << (a > b) << endl; // 0
//
//	cout << (a < b) << endl; // 1
//
//	cout << (a >= b) << endl; // 0
//
//	cout << (a <= b) << endl; // 1
//
//	system("pause");
//
//	return 0;
//}

//逻辑运算符  --- 非
//int main() {
//
//	int a = 10;
//
//	cout << !a << endl; // 0
//
//	cout << !!a << endl; // 1
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	int a = 10;
//	int b = 10;
//
//	cout << (a && b) << endl;// 1
//
//	a = 10;
//	b = 0;
//
//	cout << (a && b) << endl;// 0 
//
//	a = 0;
//	b = 0;
//
//	cout << (a && b) << endl;// 0
//
//	system("pause");
//
//	return 0;
//}

int main() {

	int a = 10;
	int b = 10;

	cout << (a || b) << endl;// 1

	a = 10;
	b = 0;

	cout << (a || b) << endl;// 1 

	a = 0;
	b = 0;

	cout << (a || b) << endl;// 0

	system("pause");

	return 0;
}