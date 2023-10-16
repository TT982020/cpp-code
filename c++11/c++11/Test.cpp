#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;
struct Point
{
	Point(int x, int y)
		:_x(x)
		,_y(y){ }
	int _x;
	int _y;
};


//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//
//	int x = 3;
//	int y = { 3 };
//	int z{ 3 };
//	 
//	Point p1 = { 1,1 };
//	Point p2{ 0,0 };
//	Point p3(1, 2);
//
//	int* pi = new int[3] {1, 2, 3};
//
//	Point* p = new Point[3]{ {0,0},{1,1},{2,2} };
//
//	return 0;
//}

//int main() {
//	//下面两行是不同的，
//	//Point p = { 1,1 };是调用了构造函数
//	//而vector<int> v = { 1,2,3,4,5 }; 右边是一个initialization_list<int> 
//	vector<int> v = { 1,2,3,4,5 };  
//	Point p = { 1,1 };  //直接调用两个参数的构造，隐式类型转换
//
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//
//	map<string, string> dict = { {"sort","排序"},{"left","左边"} };
//	v = { 2,3,4,5 };
//}

class A {
private:
	decltype(malloc) pf;
};

template <class Func>
class B {
private:
	Func f;
};

//int main() {
//	auto pf = malloc;
//	//typeid(pf).name()推出的是对象的类型是一个字符串，只能看不能用
//	cout << typeid(pf).name() << endl;
//	int x = 0, y = 10;
//
//	//decltype(pf)推出的是对象的类型，在定义变量，或作为模板实参
//	decltype(pf) pf1;
//
//	B<decltype(pf)> b;
//	B<decltype(x* y)> b;
//}


//int main() {
//	const int a = 0;
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//
//	double x = 1.1, y = 2.2;
//	//以下是常见的右值
//	10;
//	x + y;
//	fmin(x, y);  // 返回的是一个临时对象，都是右值
//
//	const char* p = "xxxxxxxxxxx";  //左值
//	cout << &p[2] << endl;
//}

//int main() {
//	//左值引用
//	int a = 10;
//	double x = 1.1, y = 2.2;
//
//	int& r = a;
//	//左值引用可以引用右值，加const
//	const int& r2 = 10;
//	const double& r3 = x + y;
//
//	//右值引用
//	int&& r1 = 10;
//	
//	double&& z = x + y;
//
//	//右值引用能否给左值取别名？
//	//不能直接引用，但可以引用move之后的左值
//	int&& r4 = move(a);
//}

void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }
// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发

template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
	//完美转发，t是左值引用，保持左值属性
	//完美转发，t是右值引用，保持右值属性
	//Fun(forward<T>(t));
}


int main()
{
	PerfectForward(10); // 右值
	int a;
	PerfectForward(a); // 左值
	PerfectForward(std::move(a)); // 右值
	const int b = 8;
	PerfectForward(b);  // const 左值
	PerfectForward(std::move(b)); // const 右值

	//int a;
	int& r = a;
	int&& rr = move(a);
	int&& rrr = 10;
	rrr++;
	cout << &a << endl;
	cout << &r << endl;
	cout << &rr << endl;
	cout << rrr << endl;
	return 0;
}

//int main() {
//	int a;
//	int& r = a;
//	int&& rr = move(a);
//	cout << &a << endl;
//	cout << &r << endl;
//	cout << &rr << endl;
//}