#define _CRT_SECURE_NO_WARNINGS 1
#include "circle.h"
using namespace std;
int main() {
	//ͨ��Բ�࣬����Բ�Ķ���
	// c1����һ�������Բ
	circle c1;
	c1.m_r = 10; //��Բ����İ뾶 ���и�ֵ����

	//2 * pi * 10 = = 62.8
	cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;

	system("pause");

	return 0;
}