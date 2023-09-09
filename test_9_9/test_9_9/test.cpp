#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

namespace a {
	int rand = 0;
	int Add(int a, int b) {
		return a + b;
	}
	struct Node
	{
		int data;
		struct Node* next;
	};
	//命名空间可以套娃
	namespace xxx {
		int rand = 1;
	}
}

//全部展开，默认情况下不会去命名空间找，但是下面一句会放开这个限制，那么就会去命名空间找（此时命名空间中和全局都会去找），这样
//会有一个问题，会比较危险，导致命名冲突，例如全局有一个rand函数，a空间中有一个rand变量，
//那么printf("%d\n", rand);中的rand会不明确
//using namespace a;

//部分展开（授权），放开了a空间中的Add，那么a中的Add就可以被找到。
//部分展开也重名，那么不展开，例如全局有一个Add函数，此时又放开了using a::Add;那么编译器会报错
using a::Add;
using std::cout;
using std::endl;
#include "Queue.h"
#include "Stack.h"
int main() {
	/*printf("%p\n", rand);
	printf("%d\n", a::rand);
	printf("%d\n", a::xxx::rand);
	printf("%d\n", Add(1, 2));
	printf("%d\n", Add(1, 2));
	struct a::Node node;*/

	cout << "hello,world" << endl;
	cout << "hello,world" << endl;
	cout << "hello,world" << endl;
	int i = 0;
	std::cin >> i;
	a::Queuenit();
	a::StackInit();
	return 0;
}

//int Add(int a, int b) {
//	return (a + b) * 10;
//}

//int main() {
//	printf("%d\n", a::rand);
//	printf("%d\n", a::Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	struct a::Node node;
//}
