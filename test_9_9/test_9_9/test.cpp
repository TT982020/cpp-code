#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdlib.h>

namespace a {
	int rand = 0;
	int Add(int a, int b) {
		return a + b;
	}
	struct Node
	{
		int data;
		struct Node* next;
	};
	//�����ռ��������
	namespace xxx {
		int rand = 1;
	}
}

//ȫ��չ����Ĭ������²���ȥ�����ռ��ң���������һ���ſ�������ƣ���ô�ͻ�ȥ�����ռ��ң���ʱ�����ռ��к�ȫ�ֶ���ȥ�ң�������
//����һ�����⣬��Ƚ�Σ�գ�����������ͻ������ȫ����һ��rand������a�ռ�����һ��rand������
//��ôprintf("%d\n", rand);�е�rand�᲻��ȷ
//using namespace a;

//����չ������Ȩ�����ſ���a�ռ��е�Add����ôa�е�Add�Ϳ��Ա��ҵ���
//����չ��Ҳ��������ô��չ��������ȫ����һ��Add��������ʱ�ַſ���using a::Add;��ô�������ᱨ��
using a::Add;
using std::cout;
using std::endl;
#include "Queue.h"
#include "Stack.h"
int main() {
	/*printf("%p\n", rand);
	printf("%d\n", a::rand);
	printf("%d\n", a::xxx::rand);
	printf("%d\n", Add(1, 2));
	printf("%d\n", Add(1, 2));
	struct a::Node node;*/

	cout << "hello,world" << endl;
	cout << "hello,world" << endl;
	cout << "hello,world" << endl;
	int i = 0;
	std::cin >> i;
	a::Queuenit();
	a::StackInit();
	return 0;
}

//int Add(int a, int b) {
//	return (a + b) * 10;
//}

//int main() {
//	printf("%d\n", a::rand);
//	printf("%d\n", a::Add(1, 2));
//	printf("%d\n", Add(1, 2));
//	struct a::Node node;
//}
