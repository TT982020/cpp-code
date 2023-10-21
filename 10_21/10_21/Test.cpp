#include <iostream>

using namespace std;
//设计一个类不能被拷贝
class CopyBan {

	CopyBan(const CopyBan& cb) = delete;

	CopyBan& operator=(const CopyBan& cb) = delete;
};

//请设计一个类，只能在堆上创建对象
class HeapOnly {
public:
	void destroy() {
		delete this;
	}
private:
	~HeapOnly(){}
};

//请设计一个类，只能在堆上创建对象
class HeapOnly1 {
public:
	static HeapOnly1* createObject() {
		return new HeapOnly1;
	}
private:
	HeapOnly1(){}
	HeapOnly1(const HeapOnly1& hp) = delete;
	HeapOnly1& operator=(const HeapOnly1& hp) = delete;
};




//请设计一个类，只能在栈上创建对象
class StackOnly {
public:
	static StackOnly createObj() {
		return StackOnly();
	}
	// 防止这个创建对象 ： StackOnly* so1 = new StackOnly(so);
	//不封拷贝构造，因为 StackOnly so1(so); 可以进行
	void* operator new(size_t size) = delete;
	void operator delete(void*) = delete;

private:
	StackOnly(int a = 0):_a(a) {  }
	int _a;
};

// 请设计一个类，不能被继承
class NonInherit final {

};

class NonInherit1{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit1(){}
};

int main() {
	//HeapOnly hp1;
	//static HeapOnly hp2;
	//HeapOnly* hp = new HeapOnly;

	/*HeapOnly1 hp1;
	static HeapOnly1 hp2;
	HeapOnly1* hp = new HeapOnly1;*/

	HeapOnly1* hp = HeapOnly1::createObject();
	//HeapOnly1 copy(*hp);
	StackOnly so = StackOnly::createObj();
	//StackOnly so1(so);
	//StackOnly* so1 = new StackOnly(so);

}
