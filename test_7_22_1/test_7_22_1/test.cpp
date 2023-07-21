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
//	//��������;
//	//1�����Ի�ȡ��������ռ���ڴ�ռ��С
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	cout << "����������ռ�ڴ�ռ�Ϊ�� " << sizeof(arr) << endl;
//	cout << "ÿ��Ԫ����ռ�ڴ�ռ�Ϊ�� " << sizeof(arr[0]) << endl;
//	cout << "�����Ԫ�ظ���Ϊ�� " << sizeof(arr) / sizeof(arr[0]) << endl;
//
//	//2������ͨ����������ȡ�������׵�ַ
//	cout << "�����׵�ַΪ�� " << (int)arr << endl;
//	cout << "�����е�һ��Ԫ�ص�ַΪ�� " << (int)&arr[0] << endl;
//	cout << "�����еڶ���Ԫ�ص�ַΪ�� " << (int)&arr[1] << endl;
//
//	//arr = 100; �����������ǳ�������˲����Ը�ֵ
//
//
//	system("pause");
//
//	return 0;
//}