#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void a::StackInit(ST* ps, int N) {
	ps->data = (int*)malloc(sizeof(int) * N);
	ps->top = 0;
	ps->capacity = N;
}

void a::StackPush(ST* ps, int data) {

}