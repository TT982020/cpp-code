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


class A
{
	//�����public����ͨ��A::������B��Ķ��������private�����ⲿ���ܴ���B�����
//public:
	//B����A����ͷ����޶��������ƣ���ʵ����������������
	//�ڲ������ⲿ�����Ԫ
	class B
	{
	public:
	private:
		int _b;
	};

public:
	//���B��private����ô��A���ڲ����Դ���B�Ķ��󣬶��ⲿ���ܴ���
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
//	//���ܱ����������޸�
//	//m++;
//	//n--;
//	//cout << "n = " << n << ",m=" << m << endl;
//	func(aa1);
//	A::Print();
//	//cout << "n = " << n << ",m=" << m << endl;
//}