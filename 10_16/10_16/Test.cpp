#include <iostream>
using namespace std;

//int main() {
//	int x = 0, y = 2;
//	double rate = 2.5;
//	auto add1 = [](int x, int y)->int {return x + y; };
//	auto add2 = [](int x, int y) {return x + y; };
//	auto add3 = [rate](int x, int y)->int {return (x + y) * rate; };
//
//	auto swap = [](int& x, int& y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//		};
//
//	swap(x, y);
//
//	//mutable�ò���ı��������޸ģ���������Ȼ��x��y�Ŀ���
//	auto swap1 = [x, y]() mutable {
//		int tmp = x;
//		x = y;
//		y = tmp;
//		};
//	swap1();
//}
////////////////////////////  ģ��ɱ����
//template<class T>
//void _ShowList(T val) {
//	cout << val << " ";
//	cout << endl;
//}


void _ShowList() {
	cout << endl;
}


template<class T,class ...Args>
void _ShowList(T val, Args... args) {
	cout << val << " ";
	_ShowList(args...);
}

//Args... ��ʾ0-N��������
template<class ...Args>
void CppPrint(Args... args) {
	_ShowList(args...);
}
template <class T>
void PrintArg(T t)
{
	cout << t << " ";
}
//չ������
template <class ...Args>
void ShowList(Args... args)
{
	int arr[] = { (PrintArg(args), 0)... };
	cout << endl;
}

int main() {
	CppPrint();
	CppPrint(1);
	CppPrint(1,2);
	CppPrint(1,2,"xx");

	ShowList(1);
	ShowList(1, 'A');
	ShowList(1, 'A', std::string("sort"));

	return 0;
}
////////////////////////////  ��װ��
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{ // ������
//	cout << useF(f, 11.11) << endl;
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber���ʽ
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}