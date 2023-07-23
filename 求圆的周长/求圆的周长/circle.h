#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include <iostream>
const double PI = 3.1415;
class circle
{
public:
	//属性
	int m_r;//半径

	//行为
	//获取到圆的周长
	double calculateZC()
	{
		//2 * pi  * r
		//获取圆的周长
		return  2 * PI * m_r;
	}

private:

};


#endif // !__CIRCLE_H__
