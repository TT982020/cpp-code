#include "Date.h"
void TestDate1() {
	Date d1(2023, 8, 33);
	Date d2(2022, 3, 11);
	d1.Print();
	d2.Print();
}

void TestDate2() {
	Date d1(2023, 8, 12);
	Date d2(d1);
	Date d3(d2);
	d3 = d2 = d1;
	d1 = d1;
	d1.Print();
	d2.Print();
}

void TestDate3() {
	Date d1(2023, 9, 23);
	d1 += 100;
	//øΩ±¥ππ‘Ï
	Date d2 = d1 + 20000;
	d1.Print();
	d2.Print();
}

void TestDate4() {
	Date d1(2023, 9, 23);
	d1 -= 20000;
	d1.Print();

	Date d2(2023, 9, 23);
	d2 -= -200;
	d2.Print();

	Date d3(2023, 9, 23);
	d3 += -200;
	d3.Print();
}

void TestDate6() {
	Date d1(2023, 9, 23);
	Date d2 = d1++;
	d2.Print();

	Date d3(2023, 9, 23);
	Date d4 = ++d2;
	d4.Print();

}

void TestDate7() {
	Date d1(2023, 9, 23);

	Date d2(1998, 3, 11);
	int day = d1 - d2;
	printf("%d\n", day);

}

void TestDate8() {
	const Date d1(2023, 9, 23);

	d1.Print();

}

int main() {
	//TestDate1();
	//TestDate2();
	//TestDate3();
	//TestDate4();
	//TestDate6();
	//TestDate7();
	TestDate8();
}