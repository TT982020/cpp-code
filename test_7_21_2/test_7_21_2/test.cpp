#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//int main() {
//
//	//ѡ��ṹ-����if���
//	//����һ�������������������600�֣���Ϊ����һ����ѧ��������Ļ�ϴ�ӡ
//
//	int score = 0;
//	cout << "������һ��������" << endl;
//	cin >> score;
//
//	cout << "������ķ���Ϊ�� " << score << endl;
//
//	//if���
//	//ע�������if�ж������棬��Ҫ�ӷֺ�
//	if (score > 600)
//	{
//		cout << "�ҿ�����һ����ѧ������" << endl;
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
//	cout << "�����뿼�Է�����" << endl;
//
//	cin >> score;
//
//	if (score > 600)
//	{
//		cout << "�ҿ�����һ����ѧ" << endl;
//	}
//	else
//	{
//		cout << "��δ����һ����ѧ" << endl;
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
//	cout << "�����뿼�Է�����" << endl;
//
//	cin >> score;
//
//	if (score > 600)
//	{
//		cout << "�ҿ�����һ����ѧ" << endl;
//	}
//	else if (score > 500)
//	{
//		cout << "�ҿ����˶�����ѧ" << endl;
//	}
//	else if (score > 400)
//	{
//		cout << "�ҿ�����������ѧ" << endl;
//	}
//	else
//	{
//		cout << "��δ���ϱ���" << endl;
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
//		cout << "������һ��" << endl;
//		if (score>700)
//		{
//			cout << "���ϱ���" << endl;
//		}
//		else if (score > 650) {
//			cout << "�����廪" << endl;
//		}
//		else {
//			cout << "�����˴�" << endl;
//		}
//	}
//	else if (score > 500) {
//		cout << "���϶���" << endl;
//	}
//	else if (score > 400) {
//		cout << "��������" << endl;
//	}
//	else
//	{
//		cout << "���ϱ���" << endl;
//	}
//}

//С�����
//int main() {
//	int a = 0, b = 0, c = 0;
//	cin >> a >> b >> c;
//	int max = a > b ? a : b;
//	max = c > max ? c : max;
//	cout << max << endl;
//}

/*
* 
> ע��1��switch����б��ʽ����ֻ�������ͻ����ַ���

> ע��2��case�����û��break����ô�����һֱ����ִ��

> �ܽ᣺��if���ȣ����ڶ������ж�ʱ��switch�Ľṹ������ִ��Ч�ʸߣ�ȱ����switch�������ж�����
*/
//int main() {
//	int score = 0;
//	cout << "�����Ӱ���" << endl;
//	cin >> score;
//	switch (score)
//	{
//	case 10:
//	case 9:
//		cout << "good" << endl;
//		break;
//	case 8:
//		cout << "�ǳ���" << endl;
//		break;
//	case 7:
//	case 6:
//		cout << "һ��" << endl;
//		break;
//	default:
//		cout << "��Ƭ" << endl;
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
//		cout << "����������:";
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