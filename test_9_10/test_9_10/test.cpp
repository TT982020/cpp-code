#include <iostream>
#include <cassert>
#include <vector>
#include "func.h"

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
int BTSize(struct TreeNode* root) {
	return root == NULL ? 0 : BTSize(root->left) + BTSize(root->right) + 1;
}
void _preorder(struct TreeNode* root, int* a, int& pi) {
	if (root == NULL) return;
	a[pi++] = root->val;
	_preorder(root->left, a, pi);
	_preorder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = BTSize(root);
	int* a = (int*)malloc(sizeof(struct TreeNode) * (*returnSize));
	int i = 0;
	_preorder(root, a, i);
	return a;
}

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode, * Plist;

//void PushBack(Plist& plist, int data) {
void PushBack(ListNode*& plist, int data) {

}

void fun1(int a, double b) {
	cout << "fun1(int a, double b)" << endl;
}

void fun1(double a, int b) {
	cout << "fun1(double a, int b)" << endl;
}



typedef struct SeqList {
	int a[10];
	int size;
	int capacity;
}SeqList;

//CPP 修改 or 读一个值
int& SLAT(SeqList& s, int i) {
	assert(i < s.size);
	return s.a[i];
}
//int main() {
//	SeqList l;
//	l.size = 3;
//	SLAT(l, 0) = 10;
//	SLAT(l, 1) = 20;
//	SLAT(l, 2) = 30;
//	cout << SLAT(l, 0) << endl;
//	cout << SLAT(l, 1) << endl;
//	cout << SLAT(l, 2) << endl;
//
//
//}

//int main() {
//	int a = 0;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	int x = 1;
//	//赋值
//	b = x;
//}

//int& Count() {
//	int n = 0;
//	return n;
//}

//int main() {
//	int ret = Count();
//	//可能返回0，也可能返回随机值
//	cout << ret << endl;
//}

//int main() {
//	ListNode* plist = NULL;
//	PushBack(plist, 1);
//	PushBack(plist, 2);
//	PushBack(plist, 3);
//
//	fun1(1, 1.1);
//	fun1(1.1, 1);
//}

struct SL
{
	int& at(int i) {
		return a[i];
	}

	int& operator[](int i) {
		assert(i < 10);
		return a[i];
	}
	int a[10];
};

//int func() {
//	int a = 1;
//	return a;
//}


//int main() {
//	//const int& aa = func(); //加了const会延长临时变量的生命周期，直到a作用域中销毁临时变量才会被销毁
//	//int a = 10;
//	//int& ra = a;
//	//int b = 20;
//	//int& rb = b;
//
//	////把rb的值赋给ra的值
//	//ra = rb;
//
//	////把b赋值给ra，ra的指向不变
//	//ra = b;
//
//	//int c = 4;
//	//const int& rc = c;
//	//报错
//	//int& rd = rc;
//	
//
//	//SL sl;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	//sl.at(i) = i;
//	//	sl[i] = i;
//	//}
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	//cout << sl.at(i) << "  ";
//	//	cout << sl[i] << "  ";
//	//}
//	//cout << endl;
//
//	const int a = 10;
//	//权限的放大
//	//int& b = a;
//
//	//int b = a;可以，这里是赋值拷贝，b修改不影响a
//
//	//权限的平移，可以
//	const int& c = a;
//
//	//权限的缩小
//	int x = 0;
//	const int& y = x; //x修改y也可以修改
//	//y = a; 不行
//
//	int i = 0;
//	const double& d = i; //类型转换会产生临时变量，临时变量具有常性
//	return 0;
//}

#define N 10
#define ADD(a,b) ((a)+(b))

inline int Add(int a, int b) {
	return a + b;
}
//int main() {
//	//直接展开，内联函数不生成函数地址，不进入符号表
//	int c = ADD(2, 3);
//	cout << c << endl;
//	//f(1);
//	ff();
//}

void f(int*) {
	cout << "f(int*)" << endl;
}

void f(int) {
	cout << "f(int)" << endl;
}
// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
};
// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};
int main() {
	vector<std::string> v;
	auto it = v.begin();
	int array[] = {2,4,5,1,2,2};
	for (auto e : array) {
		cout << e << " ";
	}
	cout << endl;
	f(nullptr);
	f(1);
	cout << "sizeof(A1)=" << sizeof(A1) << endl;
	cout << "sizeof(A2)=" << sizeof(A2) << endl;
	cout << "sizeof(A3)=" << sizeof(A3) << endl;
}