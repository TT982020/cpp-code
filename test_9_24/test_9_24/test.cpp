#include <iostream>
using namespace std;

class A
{
public:
	//可以加一个explicit 取消单参数类的隐式转换
	//explicit A(int i)
	A(int i)
		:_a(i)
	{}
	A(const A& a)
		:_a(a._a)
	{}

private:
	int _a;
};

class B
{
public:
	//可以加一个explicit 取消单参数类的隐式转换
	//explicit A(int i)
	B(int b1, int b2)
		: _b1(b1),
		 _b2(b2)
	{
		cout << "B(int b1, int b2)" << endl;
	}


private:
	int _b1;
	int _b2;
};
typedef A DataType;
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
	/*TestStack();
	int n = 0;
	Date d(2023, 9, 24, n);
	d.func();*/
	A aa1(1);
	A aa2 = 2;
	Stack st;
	st.Push(1);
	const A& a = 2;

	B b1(1, 2);
	B b2 = { 2,2 };
	const B& ref2 = { 2,3 };

	//有名对象.特点：生命周期在当前局部域
	A aa6(6);
	//匿名对象.特点：生命周期只在这一行
	A(7);

	//int n = 0;
	/*Date d1(2023, 9, 24);
	cout << d1 << endl;
	cout << Date(2023, 9, 24) << endl;*/

}
