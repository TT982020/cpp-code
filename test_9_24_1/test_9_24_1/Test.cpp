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

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}

	void Print() const {
		cout << "Print()->" << _a << endl;
	}
private:
	int _a;
};

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

A f2() {
	/*A aa;
	return aa;*/
	//return A(1);
	return 2;
}

int main() {
	A ret = f2();
	cout << "-------------------------------------" << endl;

	A ret2;
	ret2 = f2();
	return 0;
}
