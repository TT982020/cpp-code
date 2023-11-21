#include "bitset.h"
using namespace std;
//int main() {
//	bit_set::bitset<1000> bs;
//	bs.set(1);
//	bs.set(10);
//	bs.set(100);
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl << endl;
//
//	bs.reset(10);
//	bs.set(999);
//
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl << endl;
//
//	//40亿的整数进行判断,下面三种方式都可以开空间
//	bit_set::bitset<UINT32_MAX> bs1;
//	//bit_set::bitset<-1> bs2;
//	//bit_set::bitset<0xffffffff> bs3;
//
//	bs1.set(0);
//	bs1.set(-1);
//
//
//	return 0;
//}

//找到出现1次的数字
//int main() {
//	int a[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
//	bit_set::twobitset<10> bs;
//	for (auto e : a) {
//		bs.set(e);
//	}
//	for (auto e : a) {
//		if (bs.is_once(e))
//		{
//			cout << e << " ";
//		}
//	}
//	cout << endl;
//}

//找两个文件中数的交集
int main() {
	int a1[] = { 1,1,2,2,2,3,4,6,7,8,6,6,9,0 };
	int a2[] = { 9,7,5,6,0 };
	bit_set::bitset<10> bs1;
	bit_set::bitset<10> bs2;
	for (auto e : a1) {
		bs1.set(e);
	}
	for (auto e : a2) {
		bs2.set(e);
	}
	for (size_t i = 0; i < 10; i++)
	{
		if (bs1.test(i) && bs2.test(i)) {
			cout << i << " ";
		}
	}
	cout << endl;
}