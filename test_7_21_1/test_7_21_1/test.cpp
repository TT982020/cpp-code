#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
//int main() {
//	//int a = 0;
//	//cout << "���������ͱ�����" << endl;
//	//cin >> a;
//	//cout << a << endl;
//
//	////����������
//	//double d = 0;
//	//cout << "�����븡���ͱ�����" << endl;
//	//cin >> d;
//	//cout << d << endl;
//
//	////�ַ�������
//	//char ch = 0;
//	//cout << "�������ַ��ͱ�����" << endl;
//	//cin >> ch;
//	//cout << ch << endl;
//
//	////�ַ���������
//	//string str;
//	//cout << "�������ַ����ͱ�����" << endl;
//	//cin >> str;
//	//cout << str << endl;
//
//	////������������
//	//bool flag = true;
//	//cout << "�����벼���ͱ�����" << endl;
//	//cin >> flag;
//	//cout << flag << endl;
//
//	int i1 = 10;
//	int i2 = 3;
//	cout << i1 / i2 << endl;
//
//	double d1 = 0.5;
//	double d2 = 0.22;
//	cout << d1 / d2 << endl;
//}

//int main() {
//	int a1 = 10;
//	int b1 = 3;
//
//	cout << 10 % 3 << endl;
//
//	int a2 = 10;
//	int b2 = 20;
//
//	cout << a2 % b2 << endl;
//
//	int a3 = 10;
//	int b3 = 0;
//
//	//cout << a3 % b3 << endl; //ȡģ����ʱ������Ҳ����Ϊ0
//
//	//����С��������ȡģ
//	double d1 = 3.14;
//	double d2 = 1.1;
//
//	//cout << d1 % d2 << endl;
//
//	system("pause");
//}


//int main() {
//
//	//���õ���
//	int a = 10;
//	a++; //�ȼ���a = a + 1
//	cout << a << endl; // 11
//
//	//ǰ�õ���
//	int b = 10;
//	++b;
//	cout << b << endl; // 11
//
//	//����
//	//ǰ�õ����ȶԱ�������++���ټ�����ʽ
//	int a2 = 10;
//	int b2 = ++a2 * 10;
//	cout << b2 << endl;
//
//	//���õ����ȼ�����ʽ����Ա�������++
//	int a3 = 10;
//	int b3 = a3++ * 10;
//	cout << b3 << endl;
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	//��ֵ�����
//
//	// =
//	int a = 10;
//	a = 100;
//	cout << "a = " << a << endl;
//
//	// +=
//	a = 10;
//	a += 2; // a = a + 2;
//	cout << "a = " << a << endl;
//
//	// -=
//	a = 10;
//	a -= 2; // a = a - 2
//	cout << "a = " << a << endl;
//
//	// *=
//	a = 10;
//	a *= 2; // a = a * 2
//	cout << "a = " << a << endl;
//
//	// /=
//	a = 10;
//	a /= 2;  // a = a / 2;
//	cout << "a = " << a << endl;
//
//	// %=
//	a = 10;
//	a %= 2;  // a = a % 2;
//	cout << "a = " << a << endl;
//
//	system("pause");
//
//	return 0;
//}


//int main() {
//
//	int a = 10;
//	int b = 20;
//
//	cout << (a == b) << endl; // 0 
//
//	cout << (a != b) << endl; // 1
//
//	cout << (a > b) << endl; // 0
//
//	cout << (a < b) << endl; // 1
//
//	cout << (a >= b) << endl; // 0
//
//	cout << (a <= b) << endl; // 1
//
//	system("pause");
//
//	return 0;
//}

//�߼������  --- ��
//int main() {
//
//	int a = 10;
//
//	cout << !a << endl; // 0
//
//	cout << !!a << endl; // 1
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	int a = 10;
//	int b = 10;
//
//	cout << (a && b) << endl;// 1
//
//	a = 10;
//	b = 0;
//
//	cout << (a && b) << endl;// 0 
//
//	a = 0;
//	b = 0;
//
//	cout << (a && b) << endl;// 0
//
//	system("pause");
//
//	return 0;
//}

int main() {

	int a = 10;
	int b = 10;

	cout << (a || b) << endl;// 1

	a = 10;
	b = 0;

	cout << (a || b) << endl;// 1 

	a = 0;
	b = 0;

	cout << (a || b) << endl;// 0

	system("pause");

	return 0;
}