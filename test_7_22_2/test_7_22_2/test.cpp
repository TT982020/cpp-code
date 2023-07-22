#define _CRT_SECURE_NO_WARNINGS 1
#include "swap.h"
struct student
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
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
	string tname = "��ʦ";
	string sname = "ѧ��";
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
			cout << "\t������" << tArray[i].sarray[j].name << " ������" << tArray[i].sarray[j].score << endl;
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
	//��ά����������
	int arr[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};

	cout << "��ά�����С�� " << sizeof(arr) << endl;
	cout << "��ά����һ�д�С�� " << sizeof(arr[0]) << endl;
	cout << "��ά����Ԫ�ش�С�� " << sizeof(arr[0][0]) << endl;

	cout << "��ά���������� " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "��ά���������� " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//��ַ
	cout << "��ά�����׵�ַ��" << arr << endl;
	cout << "��ά�����һ�е�ַ��" << arr[0] << endl;
	cout << "��ά����ڶ��е�ַ��" << arr[1] << endl;

	cout << "��ά�����һ��Ԫ�ص�ַ��" << &arr[0][0] << endl;
	cout << "��ά����ڶ���Ԫ�ص�ַ��" << &arr[0][1] << endl;

	int a = 10, b = 20;
	cout << "a=" << a << "," << "b=" << b << endl;
	swap(&a, &b);
	cout << "a=" << a << "," << "b=" << b << endl;
	struct student stu1;
	stu1.age = 20;
	stu1.name = "��ͮ";
	stu1.score = 100;
	cout << "name:" << stu1.name << ",age:" << stu1.age << ",score:" << stu1.score << endl;

	teacher tarray[3];
	int len = sizeof(tarray) / sizeof(tarray[0]);
	initTeacher(tarray, len);
	printTeachers(tarray,len);

	hero heros[5] = { {"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"} };
	sortByBubble(heros, 5);
	printHero(heros, 5);
	return 0;
}