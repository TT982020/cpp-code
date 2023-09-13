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

//CPP �޸� or ��һ��ֵ
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
//	//��ֵ
//	b = x;
//}

//int& Count() {
//	int n = 0;
//	return n;
//}

//int main() {
//	int ret = Count();
//	//���ܷ���0��Ҳ���ܷ������ֵ
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
//	//const int& aa = func(); //����const���ӳ���ʱ�������������ڣ�ֱ��a��������������ʱ�����Żᱻ����
//	//int a = 10;
//	//int& ra = a;
//	//int b = 20;
//	//int& rb = b;
//
//	////��rb��ֵ����ra��ֵ
//	//ra = rb;
//
//	////��b��ֵ��ra��ra��ָ�򲻱�
//	//ra = b;
//
//	//int c = 4;
//	//const int& rc = c;
//	//����
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
//	//Ȩ�޵ķŴ�
//	//int& b = a;
//
//	//int b = a;���ԣ������Ǹ�ֵ������b�޸Ĳ�Ӱ��a
//
//	//Ȩ�޵�ƽ�ƣ�����
//	const int& c = a;
//
//	//Ȩ�޵���С
//	int x = 0;
//	const int& y = x; //x�޸�yҲ�����޸�
//	//y = a; ����
//
//	int i = 0;
//	const double& d = i; //����ת���������ʱ��������ʱ�������г���
//	return 0;
//}

#define N 10
#define ADD(a,b) ((a)+(b))

inline int Add(int a, int b) {
	return a + b;
}
//int main() {
//	//ֱ��չ�����������������ɺ�����ַ����������ű�
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
// ���м��г�Ա���������г�Ա����
class A1 {
public:
	void f1() {}
private:
	int _a;
};
// ���н��г�Ա����
class A2 {
public:
	void f2() {}
};
// ����ʲô��û��---����
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