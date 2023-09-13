#pragma once
#include <iostream>
using namespace std;
//只有声明没有定义在别的地方调用会出现链接错误
inline void f(int i);


//inline void f(int i) {
//	cout << i << endl;
//}

void ff();