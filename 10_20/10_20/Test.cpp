#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <memory>
#include <functional>
using namespace std;
#include "SmartPtr.h"
class A {
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
	int _a;
};
//int main() {
//	name::auto_ptr<A> ap1(new A(1));
//	name::auto_ptr<A> ap2(new A(1));
//
//	name::auto_ptr<A> ap3(ap1);
//	//管理权转移，拷贝时，会把被拷贝对象的资源管理权转移给拷贝对象
//	// 导致被拷贝对象悬空，访问就会出问题
//	//ap1->_a++;
//	ap3->_a++;
//}

//int main() {
//
//	name::unique_ptr<A> up1(new A(1));
//	name::unique_ptr<A> up2(new A(1));
//	name::unique_ptr<A> up3(up2);
//
//
//}
//struct Node
//{
//	A _val;
//	//weak_ptr不是RAII智能指针，专门用来解决shared_ptr循环引用
//	//weak_ptr不参与引用计数，可以访问资源，不参与资源释放的管理
//	weak_ptr<Node> _next;
//	weak_ptr<Node> _prev;
//};
//
//int main() {
//	//name::shared_ptr<A> sp1(new A(1));
//	//
//	//name::shared_ptr<A> sp3(sp1);
//
//	//name::shared_ptr<A> sp2(new A(2));
//	//name::shared_ptr<A> sp4(sp2);
//	//name::shared_ptr<A> sp5(sp4);
//
//	//sp1 = sp5;
//	//sp2->_a++;
//	//sp3->_a++;
//
//	//shared_ptr<Node> sp1(new Node);
//	//shared_ptr<Node> sp2(new Node);
//
//	////存在循环引用的问题
//	//sp1->_next = sp2;
//	//sp2->_prev = sp1;
//
//
//	shared_ptr<Node> sp1(new Node);
//	shared_ptr<Node> sp2(new Node);
//
//	//存在循环引用的问题
//	sp1->_next = sp2;
//	sp2->_prev = sp1;
//}

//struct Node
//{
//	A _val;
//	/*name::shared_ptr<Node> _next;
//	name::shared_ptr<Node> _prev;*/
//	name::weak_ptr<Node> _next;
//	name::weak_ptr<Node> _prev;
//};
//
//int main() {
//	name::shared_ptr<Node> sp1(new Node);
//	name::shared_ptr<Node> sp2(new Node);
//
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//
//	//存在循环引用的问题
//	sp1->_next = sp2;
//	sp2->_prev = sp1;
//
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//}

template<class T>
struct DeleteArray
{
	void operator()(T* ptr) {
		delete[] ptr;
	}
};

//int main() {
//	//定制删除器
//	name::shared_ptr<A> sp1(new A[10], DeleteArray<A>());
//	name::shared_ptr<A> sp2((A*)malloc(sizeof(A)), [](A* ptr) {free(ptr); });
//
//	name::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* fp) {fclose(fp); });
//
//	name::shared_ptr<A> sp4(new A(1));
//}

int main() {
	char* ptr = new char[1024 * 1024 * 1024];

	return 0;
}