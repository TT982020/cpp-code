#include <iostream>

using namespace std;
//���һ���಻�ܱ�����
class CopyBan {

	CopyBan(const CopyBan& cb) = delete;

	CopyBan& operator=(const CopyBan& cb) = delete;
};

//�����һ���ֻ࣬���ڶ��ϴ�������
class HeapOnly {
public:
	void destroy() {
		delete this;
	}
private:
	~HeapOnly(){}
};

//�����һ���ֻ࣬���ڶ��ϴ�������
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




//�����һ���ֻ࣬����ջ�ϴ�������
class StackOnly {
public:
	static StackOnly createObj() {
		return StackOnly();
	}
	// ��ֹ����������� �� StackOnly* so1 = new StackOnly(so);
	//���⿽�����죬��Ϊ StackOnly so1(so); ���Խ���
	void* operator new(size_t size) = delete;
	void operator delete(void*) = delete;

private:
	StackOnly(int a = 0):_a(a) {  }
	int _a;
};

// �����һ���࣬���ܱ��̳�
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
