#include <iostream>

using namespace std;

template <class T>
T* func(int n) {
	return new T[n];
}
// 专门处理int的加法函数
int Add(int left, int right)
{
	return left + right;
}
// 通用加法函数
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
	Add<int>(1, 2); // 调用编译器特化的Add版本
}
// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	// 使用析构函数演示：在类中声明，在类外定义。
	~Vector();

	void PushBack(const T& data)；
		void PopBack()；
		// ...

		size_t Size() { return _size; }

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template <class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

int main() {
	int a = 1, b = 2;
	swap(a, b);
	int* p = func<int>(5);
}