#pragma once
#include <stdlib.h>
namespace a {
	typedef struct Stack
	{
		int* data;
		int top;
		int capacity;
	}ST;
	//�����������Ͷ���ͬʱ��ȱʡ����
	//�����������岻��
	void StackInit(ST* ps, int N = 4);

	//���h��cpp���룬��ô���������ﶨ�庯����������壬����ɺ���������
	//��ΪStack.cpp ��һ��StackPush����test.c��include��Stack.h����ô�����ӵ�ʱ��
	//��������StackPush���������������࣬ÿ��cpp��������һ��.o�ļ����Ժ����γɷ��ű�
	//���ӣ��Է��ű���кϲ����ض�λ
	/*void StackPush(ST* ps, int data) {

	}*/

	//����ʹ��static���Խ������,static��ı��������ԣ�ֻ�ڵ�ǰ�ļ���Ч
	/*static void StackPush(ST* ps, int data){
	}*/

	void StackPush(ST* ps, int data);
}