#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int g_a = 10;
//int g_b = 10;
//
////ȫ�ֳ���
//const int c_g_a = 10;
//const int c_g_b = 10;
//int main() {
//	//�ֲ�����
//	int a = 10;
//	int b = 10;
//
//	//��ӡ��ַ
//	cout << "�ֲ�����a��ַΪ�� " << &a << endl;
//	cout << "�ֲ�����b��ַΪ�� " << &b << endl;
//
//	cout << "ȫ�ֱ���g_a��ַΪ�� " << &g_a << endl;
//	cout << "ȫ�ֱ���g_b��ַΪ�� " << &g_b << endl;
//
//	//��̬����
//	static int s_a = 10;
//	static int s_b = 10;
//
//	cout << "��̬����s_a��ַΪ�� " << &s_a << endl;
//	cout << "��̬����s_b��ַΪ�� " << &s_b << endl;
//
//	cout << "�ַ���������ַΪ�� " << &"hello world" << endl;
//	cout << "�ַ���������ַΪ�� " << &"hello world1" << endl;
//
//	cout << "ȫ�ֳ���c_g_a��ַΪ�� " << &c_g_a << endl;
//	cout << "ȫ�ֳ���c_g_b��ַΪ�� " << &c_g_b << endl;
//
//	const int c_l_a = 10;
//	const int c_l_b = 10;
//	cout << "�ֲ�����c_l_a��ַΪ�� " << &c_l_a << endl;
//	cout << "�ֲ�����c_l_b��ַΪ�� " << &c_l_b << endl;
//
//	system("pause");
//
//	return 0;
//}

//int* func()
//{
//	int a = 10;
//	return &a;
//}
//
//int main() {
//
//	int* p = func();
//
//	cout << *p << endl;
//	cout << "hello" << endl;
//	cout << *p << endl;
//
//	system("pause");
//
//	return 0;
//}

//int* func()
//{
//	int* a = new int(10);
//	return a;
//}
//
//int main() {
//
//	int* p = func();
//
//	cout << *p << endl;
//	cout << *p << endl;
//
//	delete p;
//	system("pause");
//
//
//	return 0;
//}

//int main() {
//	int a = 10;
//	int b = 20;
//	//int &c; //�������ñ����ʼ��
//	int& c = a; //һ����ʼ���󣬾Ͳ����Ը���
//	c = b; //���Ǹ�ֵ���������Ǹ�������
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//	system("pause");
//
//	return 0;
//}

//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
}
int main() {
	int a = 10;

	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a;
	ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);
	return 0;
}