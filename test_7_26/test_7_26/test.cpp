#define _CRT_SECURE_NO_WARNINGS 1
//using namespace std;
//#include <iostream>
//namespace x1 {
//	int a = 10;
//}
//
//namespace x2 {
//	int a = 10;
//}
//
//int main() {
//	cout << x1::a << endl;
//	cout << x2::a << endl;
//}
#include <iostream>

template<class Key>
struct hash
{

};
template<>
struct hash<char>
{
	size_t operator() (char c) { return c; }
};

template <>
struct hash<int> {
	size_t operator() (int i) { return i; }
};

template <>
struct hash<long> {
	size_t operator() (long l) { return l; }
};



int main() {
	std::cout << hash<int>()(10) << std::endl;

}