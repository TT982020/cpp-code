#define _CRT_SECURE_NO_WARNINGS 1
#include "circle.h"
using namespace std;
int main() {
	//通过圆类，创建圆的对象
	// c1就是一个具体的圆
	circle c1;
	c1.m_r = 10; //给圆对象的半径 进行赋值操作

	//2 * pi * 10 = = 62.8
	cout << "圆的周长为： " << c1.calculateZC() << endl;

	system("pause");

	return 0;
}