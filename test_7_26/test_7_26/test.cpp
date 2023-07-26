#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
namespace x1 {
	int a = 10;
}

namespace x2 {
	int a = 10;
}

int main() {
	cout << x1::a << endl;
	cout << x2::a << endl;
}