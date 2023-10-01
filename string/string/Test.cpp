#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>

using namespace std;
#include "string.h"
int main() {
	//name1::test_string8();
	string s1;
	string s2("hello world");

	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;

	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
}