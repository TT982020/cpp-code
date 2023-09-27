#include <iostream>

using namespace std;

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_array = new DataType[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// 其他方法...
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		{
//			//free(_array);
//			delete[] _array;
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	// 内置类型成员
//	DataType* _array;
//	int _capacity;
//	int _size;
//};

class A
{
public:
	A(int a = 0)
		:_a(a)
	{}
	~A() {
		cout << "~A()" << endl;
	}

private:
	int _a;
};


//Stack* fun() {
//	int n;
//	cin >> n;
//	Stack* pst = new Stack(n);
//	return pst;
//}

//int main() {
//	/*Stack* ptr = fun();
//	ptr->Push(1);
//	ptr->Push(3);
//	delete ptr;*/
//
//	try
//	{
//		char* p = new char[0x7fffffff];
//		//cout << (void*)p << endl;
//		cout << "hello" << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	
//
//	return 0;
//}

//函数模板
template<class T>
void Swap(T& left, T& right) {
	T tmp = left;
	left = right;
	right = tmp;
}

//类模板
//typedef int DataType;
template<class T>
class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		cout << "Stack(size_t capacity = 3)" << endl;
		_array = (T*)malloc(sizeof(T) * capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	Stack(const Stack& s) {
		cout << "Stack(const Stack& s)" << endl;
		_array = (T*)malloc(sizeof(T) * s._capacity);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		memcpy(_array, s._array, sizeof(T) * s._size);
		_capacity = s._capacity;
		_size = s._size;

	}
	void Push(T data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	// 其他方法...
	~Stack()
	{
		cout << "~Stack()" << endl;
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	// 内置类型成员
	T* _array;
	int _capacity;
	int _size;
};

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main() {
	int a = 0, b = 1;
	double a1 = 1.1, b1 = 2.2;
	Swap(a, b);
	Swap(a1, b1);

	Stack<int> st(4);
	Stack<double> st(4);


	int i1 = 10, i2 = 20;
	double d1 = 10.0, d2 = 20.0;
	//Add(d1, i2);  类型不匹配
	Add(i1, i2);
	Add(i1, (int)d1);

	Add<int>(i1, d1);
	Add<double>(i2, d2);
}
//int main() {
//	Stack* pst1 = (Stack*)operator new(sizeof(Stack));
//	new (pst1)Stack(4);  //显式调用构造函数
//	pst1->~Stack();
//	operator delete(pst1);
//
//	Stack* pst2 = new Stack;
//	delete pst2;
//
//	int* p1 = new int[10];
//	/*free(p1);
//	delete(p1);
//	delete[] p1;*/
//
//	A* p2 = new A[10];
//	//free(p2);
//	//delete p2;  //不匹配
//	delete[] p2;
//
//}