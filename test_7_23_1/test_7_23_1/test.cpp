#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int g_a = 10;
//int g_b = 10;
//
////全局常量
//const int c_g_a = 10;
//const int c_g_b = 10;
//int main() {
//	//局部变量
//	int a = 10;
//	int b = 10;
//
//	//打印地址
//	cout << "局部变量a地址为： " << &a << endl;
//	cout << "局部变量b地址为： " << &b << endl;
//
//	cout << "全局变量g_a地址为： " << &g_a << endl;
//	cout << "全局变量g_b地址为： " << &g_b << endl;
//
//	//静态变量
//	static int s_a = 10;
//	static int s_b = 10;
//
//	cout << "静态变量s_a地址为： " << &s_a << endl;
//	cout << "静态变量s_b地址为： " << &s_b << endl;
//
//	cout << "字符串常量地址为： " << &"hello world" << endl;
//	cout << "字符串常量地址为： " << &"hello world1" << endl;
//
//	cout << "全局常量c_g_a地址为： " << &c_g_a << endl;
//	cout << "全局常量c_g_b地址为： " << &c_g_b << endl;
//
//	const int c_l_a = 10;
//	const int c_l_b = 10;
//	cout << "局部常量c_l_a地址为： " << &c_l_a << endl;
//	cout << "局部常量c_l_b地址为： " << &c_l_b << endl;
//
//	system("pause");
//
//	return 0;
//}

//int* func()
//{
//	int a = 10;
//	return &a;
//}
//
//int main() {
//
//	int* p = func();
//
//	cout << *p << endl;
//	cout << "hello" << endl;
//	cout << *p << endl;
//
//	system("pause");
//
//	return 0;
//}

//int* func()
//{
//	int* a = new int(10);
//	return a;
//}
//
//int main() {
//
//	int* p = func();
//
//	cout << *p << endl;
//	cout << *p << endl;
//
//	delete p;
//	system("pause");
//
//
//	return 0;
//}

//int main() {
//	int a = 10;
//	int b = 20;
//	//int &c; //错误，引用必须初始化
//	int& c = a; //一旦初始化后，就不可以更改
//	c = b; //这是赋值操作，不是更改引用
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//	system("pause");
//
//	return 0;
//}

//发现是引用，转换为 int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref是引用，转换为*ref = 100
}
int main() {
	int a = 10;

	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref = a;
	ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	return 0;
}