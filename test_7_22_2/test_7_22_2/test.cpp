#define _CRT_SECURE_NO_WARNINGS 1
#include "swap.h"
struct student
{
	//成员列表
	string name;  //姓名
	int age;      //年龄
	int score;    //分数
}stu;
struct teacher
{
	string name;
	struct student sarray[5];
};
struct hero
{
	string name;
	int age;
	string sex;
};

void initTeacher(teacher tarray[],int len) {
	string tname = "教师";
	string sname = "学生";
	string seedname = "ABCDE";
	for (int i = 0; i < len; i++) {
		tarray[i].name = tname + seedname[i];
		for (int j = 0; j < 5; j++) {
			tarray[i].sarray[j].name = sname + seedname[j];
			tarray[i].sarray[j].age = 10;
			tarray[i].sarray[j].score = rand() % 61 + 40;
		}
	}
}


void printTeachers(teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sarray[j].name << " 分数：" << tArray[i].sarray[j].score << endl;
		}
	}
}

void sortByBubble(struct hero heros[], int len) {
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++) {
			if (heros[j].age > heros[j + 1].age)
			{
				hero tmp = heros[j];
				heros[j] = heros[j + 1];
				heros[j + 1] = tmp;
			}
		}
	}
}
void printHero(struct hero heros[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "name=" << heros[i].name << ",age=" << heros[i].age << ",sex=" << heros[i].sex << endl;
	}
}
int main() {
	srand((unsigned int)(time(NULL)));
	//二维数组数组名
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "二维数组大小： " << sizeof(arr) << endl;
	cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
	cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//地址
	cout << "二维数组首地址：" << arr << endl;
	cout << "二维数组第一行地址：" << arr[0] << endl;
	cout << "二维数组第二行地址：" << arr[1] << endl;

	cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;

	int a = 10, b = 20;
	cout << "a=" << a << "," << "b=" << b << endl;
	swap(&a, &b);
	cout << "a=" << a << "," << "b=" << b << endl;
	struct student stu1;
	stu1.age = 20;
	stu1.name = "晓彤";
	stu1.score = 100;
	cout << "name:" << stu1.name << ",age:" << stu1.age << ",score:" << stu1.score << endl;

	teacher tarray[3];
	int len = sizeof(tarray) / sizeof(tarray[0]);
	initTeacher(tarray, len);
	printTeachers(tarray,len);

	hero heros[5] = { {"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"} };
	sortByBubble(heros, 5);
	printHero(heros, 5);
	return 0;
}