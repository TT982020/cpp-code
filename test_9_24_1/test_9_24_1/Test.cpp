#include <iostream>
using namespace std;
//累计创建了多少对象

//class A
//{
//public:
//	A() { 
//		++n; 
//		++m;
//	}
//	A(const A & t) { 
//		++n; 
//		++m;
//	}
//	~A() { 
//		--m; 
//	}
//	//静态成员函数的特点是：没有this指针
//	static int GetM() {
//		return m;
//	}
//	static void Print() {
//		//x++;   //不能访问非静态成员, 没有this
//		cout << m << " " << n << endl;
//	}
//private:
//	static int n;
//
//	//正在使用的对象
//	static int m;
//
//	int x = 0;
//};
//
//int A::m = 0;
//int A::n = 0;
//
//A func(A aa) {
//	return aa;
//}


class A
{
	//如果是public可以通过A::来创建B类的对象，如果是private，则外部不能创建B类对象
//public:
	//B类受A类域和访问限定符的限制，其实他们是两个独立类
	//内部类是外部类的友元
	class B
	{
	public:
	private:
		int _b;
	};

public:
	//如果B是private，那么在A类内部可以创建B的对象，而外部不能创建
	void func() {
		B bb;
	}
	
private:
	int _a;
};

int main() {

	cout << sizeof(A) << endl;  //4
	//A::B bb1;
	
}
//int main() {
//	A aa1;
//	
//	A aa2;
//	//cout << "n = " << n << ",m=" << m << endl;
//	A();
//
//	A::Print();
//	
//	//可能被外面随意修改
//	//m++;
//	//n--;
//	//cout << "n = " << n << ",m=" << m << endl;
//	func(aa1);
//	A::Print();
//	//cout << "n = " << n << ",m=" << m << endl;
//}