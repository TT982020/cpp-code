#include <iostream>
using namespace std;
//�ۼƴ����˶��ٶ���

class A
{
public:
	A() { 
		++n; 
		++m;
	}
	A(const A & t) { 
		++n; 
		++m;
	}
	~A() { 
		--m; 
	}
	//��̬��Ա�������ص��ǣ�û��thisָ��
	static int GetM() {
		return m;
	}
	static void Print() {
		//x++;   //���ܷ��ʷǾ�̬��Ա, û��this
		cout << m << " " << n << endl;
	}
private:
	static int n;

	//����ʹ�õĶ���
	static int m;

	int x = 0;
};

int A::m = 0;
int A::n = 0;

A func(A aa) {
	return aa;
}

int main() {
	A aa1;
	
	A aa2;
	//cout << "n = " << n << ",m=" << m << endl;
	A();

	A::Print();
	
	//���ܱ����������޸�
	//m++;
	//n--;
	//cout << "n = " << n << ",m=" << m << endl;
	func(aa1);
	A::Print();
	//cout << "n = " << n << ",m=" << m << endl;
}