#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void reverse(char* str, int begin, int end) {
    int left = begin, right = end;
    while (left < right) {
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        left++;
        right--;
    }
}
struct S
{
    char a : 3;
    char b : 4;
    char c : 5;
    char d : 4;
};

int main() {
    struct S s = { 0 };
    s.a = 10;
    s.b = 12;
    s.c = 3;
    s.d = 4;
    printf("%d\n", sizeof(struct S));
}