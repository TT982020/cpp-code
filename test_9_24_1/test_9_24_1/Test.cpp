#include <iostream>
using namespace std;
//�ۼƴ����˶��ٶ���

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
//	//��̬��Ա�������ص��ǣ�û��thisָ��
//	static int GetM() {
//		return m;
//	}
//	static void Print() {
//		//x++;   //���ܷ��ʷǾ�̬��Ա, û��this
//		cout << m << " " << n << endl;
//	}
//private:
//	static int n;
//
//	//����ʹ�õĶ���
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



//int main() {
//	A aa1;
//	
//	A aa2;
//	//cout << "n = " << n << ",m=" << m << endl;
//	A();
//
//	A::Print();
//	
//	//���ܱ����������޸�
//	//m++;
//	//n--;
//	//cout << "n = " << n << ",m=" << m << endl;
//	func(aa1);
//	A::Print();
//	//cout << "n = " << n << ",m=" << m << endl;
//}

//class A
//{
//	//�����public����ͨ��A::������B��Ķ��������private�����ⲿ���ܴ���B�����
////public:
//	//B����A����ͷ����޶��������ƣ���ʵ����������������
//	//�ڲ������ⲿ�����Ԫ
//	class B
//	{
//	public:
//		void FuncB() {
//			A a;
//			a._a = 1;
//		}
//	private:
//		int _b;
//	};
//
//public:
//	//���B��private����ô��A���ڲ����Դ���B�Ķ��󣬶��ⲿ���ܴ���
//	void func() {
//		B bb;
//	}
//
//private:
//	int _a;
//};
//
//int main() {
//
//	cout << sizeof(A) << endl;  //4
//	//A::B bb1;
//
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print() const {
//		cout << "Print()->" << _a << endl;
//	}
//private:
//	int _a;
//};

//void f(const A& aa = A()) {
//	aa.Print();
//}
//void ff(A aa) {
//	aa.Print();
//}
//int main() {
//	/*A aa1;
//	f(aa1);*/
//
//	f(A());
//	f(2);
//	f();
//
//	//const���û��ӳ��������������
//	//ref��������������������
//	const A& ref = A();
//	A aa2;
//	cout << "-------------------------------------" << endl;
//	
//	A aa1;
//	ff(aa1);
//	cout << "-------------------------------------" << endl;
//
//	//һ�����ʽ�������Ĳ������棬�����Ĺ�����ܻᱻ�ϲ�
//	ff(A());
//	cout << "-------------------------------------" << endl;
//
//	ff(1);
//	cout << "-------------------------------------" << endl;
//
//	A aa3 = 1;
//	cout << "-------------------------------------" << endl;
//
//	A aa4 = A(2);
//	cout << "-------------------------------------" << endl;
//
//}

//A f2() {
//	/*A aa;
//	return aa;*/
//	//return A(1);
//	return 2;
//}

//int main() {
//	A ret = f2();
//	cout << "-------------------------------------" << endl;
//
//	A ret2;
//	ret2 = f2();
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

struct ListNode
{
	ListNode* _next;
	int _val;
	ListNode(int val = 0)
		:_val(val)
		, _next(nullptr)
	{}
};

int main() {
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = new int;
	int* p3 = (int*)malloc(sizeof(int) * 10);
	int* p4 = new int[10];
	free(p1);
	free(p3);

	delete p2; //c++
	delete[] p4;

	//����֧�ֿ��ռ�+��ʼ��
	int* p6 = new int(1);
	int* p7 = new int[10] {1, 2, 3}; // ����Ĭ����0
	int* p8 = new int[10] {}; // Ĭ����0

	//mallocû�а취�ܺõ�֧�ֶ�̬������Զ������͵ĳ�ʼ��
	A* a1 = (A*)malloc(sizeof(A));

	//�Զ������ͣ����ռ�+���ù��캯����ʼ��
	A* a2 = new A;
	A* a3 = new A(3);

	A aa1(1);
	A aa2(2);
	A* a4 = new A[10];

	A* a5 = new A[10]{ aa1,aa2 };
	A* a6 = new A[10]{ A(1),A(2)};
	A* a7 = new A[10]{ 1,2 };



	//�Զ������ͣ�������������+�ͷſռ�
	delete a2;
	delete a3;
	delete[] a4;
	delete[] a5;
	delete[] a6;
	delete[] a7;

	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	n1->_next = n2;
	n2->_next = n3;
	n3->_next = n4;
	n4->_next = n5;

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;

	return 0;
}