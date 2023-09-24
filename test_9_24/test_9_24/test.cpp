#include <iostream>
using namespace std;
typedef int DataType;
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// 其他方法...
	~Stack()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	// 内置类型成员
	DataType* _array;
	int _capacity;
	int _size;

};
class MyQueue
{
public:
	MyQueue(int capacity = 10): _st1(capacity),_st2(capacity) {

	}
	
private:
	Stack _st1;
	Stack _st2;
};

class Date
{
public:
	Date(int year, int month, int day, int& i)
		:_year(year),
		_month(month)
		,_x(1),_refi(i) {
		_day = day;
	}
	//~Date();

	void func() {
		_refi++;
		cout << _refi << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	const int _x;
	int& _refi;
};

void TestStack()
{
	Stack s(10);
	s.Push(1);
	s.Push(2);
}

int main() {
	TestStack();
	int n = 0;
	Date d(2023, 9, 24, n);
	d.func();


}
