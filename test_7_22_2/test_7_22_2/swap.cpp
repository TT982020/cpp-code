#define _CRT_SECURE_NO_WARNINGS 1
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}