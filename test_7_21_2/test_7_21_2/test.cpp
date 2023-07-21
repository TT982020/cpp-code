#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main() {
//
//	//选择结构-单行if语句
//	//输入一个分数，如果分数大于600分，视为考上一本大学，并在屏幕上打印
//
//	int score = 0;
//	cout << "请输入一个分数：" << endl;
//	cin >> score;
//
//	cout << "您输入的分数为： " << score << endl;
//
//	//if语句
//	//注意事项，在if判断语句后面，不要加分号
//	if (score > 600)
//	{
//		cout << "我考上了一本大学！！！" << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}
//int main() {
//
//	int score = 0;
//
//	cout << "请输入考试分数：" << endl;
//
//	cin >> score;
//
//	if (score > 600)
//	{
//		cout << "我考上了一本大学" << endl;
//	}
//	else
//	{
//		cout << "我未考上一本大学" << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	int score = 0;
//
//	cout << "请输入考试分数：" << endl;
//
//	cin >> score;
//
//	if (score > 600)
//	{
//		cout << "我考上了一本大学" << endl;
//	}
//	else if (score > 500)
//	{
//		cout << "我考上了二本大学" << endl;
//	}
//	else if (score > 400)
//	{
//		cout << "我考上了三本大学" << endl;
//	}
//	else
//	{
//		cout << "我未考上本科" << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//	int score = 0;
//	cin >> score;
//	if (score>600)
//	{
//		cout << "考上了一本" << endl;
//		if (score>700)
//		{
//			cout << "考上北大" << endl;
//		}
//		else if (score > 650) {
//			cout << "考上清华" << endl;
//		}
//		else {
//			cout << "考上人大" << endl;
//		}
//	}
//	else if (score > 500) {
//		cout << "考上二本" << endl;
//	}
//	else if (score > 400) {
//		cout << "考上三本" << endl;
//	}
//	else
//	{
//		cout << "考上本科" << endl;
//	}
//}

//小猪称重
//int main() {
//	int a = 0, b = 0, c = 0;
//	cin >> a >> b >> c;
//	int max = a > b ? a : b;
//	max = c > max ? c : max;
//	cout << max << endl;
//}

/*
* 
> 注意1：switch语句中表达式类型只能是整型或者字符型

> 注意2：case里如果没有break，那么程序会一直向下执行

> 总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间
*/
//int main() {
//	int score = 0;
//	cout << "请给电影打分" << endl;
//	cin >> score;
//	switch (score)
//	{
//	case 10:
//	case 9:
//		cout << "good" << endl;
//		break;
//	case 8:
//		cout << "非常好" << endl;
//		break;
//	case 7:
//	case 6:
//		cout << "一般" << endl;
//		break;
//	default:
//		cout << "烂片" << endl;
//		break;
//	}
//}

//int main() {
//	int num = 0;
//	while (num < 10)
//	{
//		cout << "num = " << num << endl;
//		num++;
//	}
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//	int num = rand() % 100 + 1;
//	int p = -1;
//	while (p!=num)
//	{
//		cout << "请输入数字:";
//		cin >> p;
//		if (p==num)
//		{
//			cout << "right" << endl;
//			break;
//		}
//		else if (p > num) {
//			cout << "big" << endl;
//		}
//		else
//		{
//			cout << "small" << endl;
//		}
//	}
//}

//int main() {
//	int num = 0;
//
//	do
//	{
//		cout << num << endl;
//		num++;
//
//	} while (num < 10);
//
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//	int num = 100;
//	do
//	{
//		int r1 = num % 10;
//		int r2 = num / 10 % 10;
//		int r3 = num / 100;
//		int sum = r1 * r1 * r1 + r2 * r2 * r2 + r3 * r3 * r3;
//		if (sum==num)
//		{
//			cout << num << endl;
//		}
//		num++;
//	} while (num<1000);
//}

//int main() {
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 7 || i / 10 % 10 == 7 || i % 7 == 0) {
//			cout << i << endl;
//		}
//	}
//}

int main() {
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++) {
			cout << j << "*" << i << "=" << i * j << " ";
		}
		cout << endl;
	}
}