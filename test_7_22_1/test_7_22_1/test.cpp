#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void reverse(int arr[], int len) {
	int* left = arr, * right = arr + len - 1;
	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}

void bubble_sort(int arr[], int len) {
	int flag = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j]>arr[j+1])
			{
				flag = 1;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag==0)
		{
			break;
		}
	}
}

int main() {
	int arr[] = { 1,3,2,5,4 };
	reverse(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	bubble_sort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
}
//int main() {
//	//数组名用途
//	//1、可以获取整个数组占用内存空间大小
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
//	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
//	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
//
//	//2、可以通过数组名获取到数组首地址
//	cout << "数组首地址为： " << (int)arr << endl;
//	cout << "数组中第一个元素地址为： " << (int)&arr[0] << endl;
//	cout << "数组中第二个元素地址为： " << (int)&arr[1] << endl;
//
//	//arr = 100; 错误，数组名是常量，因此不可以赋值
//
//
//	system("pause");
//
//	return 0;
//}