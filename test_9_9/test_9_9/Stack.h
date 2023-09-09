#pragma once
#include <stdlib.h>
namespace a {
	typedef struct Stack
	{
		int* data;
		int top;
		int capacity;
	}ST;
	//不允许声明和定义同时给缺省参数
	//声明给，定义不给
	void StackInit(ST* ps, int N = 4);

	//如果h和cpp分离，那么不能在这里定义函数，如果定义，会造成函数重命名
	//因为Stack.cpp 有一份StackPush，而test.c又include了Stack.h，那么在链接的时候
	//会有两个StackPush，造成重命名。汇编，每个cpp都会生成一个.o文件，对函数形成符号表
	//链接，对符号表进行合并和重定位
	/*void StackPush(ST* ps, int data) {

	}*/

	//或者使用static可以解决问题,static会改变链接属性，只在当前文件生效
	/*static void StackPush(ST* ps, int data){
	}*/

	void StackPush(ST* ps, int data);
}