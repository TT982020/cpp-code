#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include <iostream>
const double PI = 3.1415;
class circle
{
public:
	//����
	int m_r;//�뾶

	//��Ϊ
	//��ȡ��Բ���ܳ�
	double calculateZC()
	{
		//2 * pi  * r
		//��ȡԲ���ܳ�
		return  2 * PI * m_r;
	}

private:

};


#endif // !__CIRCLE_H__
