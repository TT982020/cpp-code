#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <map>

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

// 请设计一个类，不能被继承,构造函数私有化（在派生类中不可见）
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

//int main() {
//	//HeapOnly hp1;
//	//static HeapOnly hp2;
//	//HeapOnly* hp = new HeapOnly;
//
//	/*HeapOnly1 hp1;
//	static HeapOnly1 hp2;
//	HeapOnly1* hp = new HeapOnly1;*/
//
//	HeapOnly1* hp = HeapOnly1::createObject();
//	//HeapOnly1 copy(*hp);
//	StackOnly so = StackOnly::createObj();
//	//StackOnly so1(so);
//	//StackOnly* so1 = new StackOnly(so);
//}

//单例模式(饿汉模式)
//一开始（main函数之前）就创建对象
//1. 如果单例对象初始化内容很多，会影响启动速度
//2. 如果有两个单例类，互相有依赖关系
// 假设有A，B两个单例类，要求A先创建，B再创建，B的初始化创建依赖于A
namespace hungry {
	class Singleton {
	public:
		static Singleton& getInstance() {
			return _instance;
		}
		Singleton(const Singleton& st) = delete;
		Singleton& operator=(const Singleton& st) = delete;
		void Add(const pair<string, string> kv) {
			_dict[kv.first] = kv.second;
		}

		void Print() {
			for (auto& e : _dict) {
				cout << e.first << ":" << e.second << endl;
			}
		}
	private:
		Singleton() { }
		map<string, string> _dict;
		static Singleton _instance;
	};

	//为什么在类外面可以访问私有？可以理解为声明和定义分离，就比如类内声明了fun函数，在类外
	//定义这个fun函数，这个fun函数里面可以访问私有
	Singleton Singleton::_instance;

}

namespace lazy {
	class Singleton {
	public:
		static Singleton& getInstance() {
			if (_pinstance == nullptr)
			{
				_pinstance = new Singleton;
			}
			return *_pinstance;
		}

		//一般单例不用释放
		//特殊场景 1. 中途需要显式释放 2.程序结束，需要进行一些特殊动作（持久化）
		static void DelInstance() {
			if (_pinstance)
			{
				delete _pinstance;
				_pinstance = nullptr;
			}
		}

		Singleton(const Singleton& st) = delete;
		Singleton& operator=(const Singleton& st) = delete;
		void Add(const pair<string, string> kv) {
			_dict[kv.first] = kv.second;
		}

		void Print() {
			for (auto& e : _dict) {
				cout << e.first << ":" << e.second << endl;
			}
		}
		class GC {
		public:
			~GC() {
				lazy::Singleton::DelInstance();
			}
		};

	private:
		Singleton() { }
		~Singleton(){
			cout << "~Singleton()" << endl;
			//要求把map的数据写道文件中
			FILE* file = fopen("out.txt", "w");
			for (auto& e : _dict) {
				fprintf(file, "%s:%s\n", e.first.c_str(), e.second.c_str());
			}
			fclose(file);
			
		}
		
		map<string, string> _dict;
		static Singleton* _pinstance;
		static GC _gc;
	};

	//为什么在类外面可以访问私有？可以理解为声明和定义分离，就比如类内声明了fun函数，在类外
	//定义这个fun函数，这个fun函数里面可以访问私有
	Singleton* Singleton::_pinstance = nullptr;
	Singleton::GC Singleton::_gc;
}
//class GC {
//public:
//	~GC() {
//		lazy::Singleton::DelInstance();
//	}
//};
//
//GC gc;

//int main() {
//	cout << &hungry::Singleton::getInstance() << endl;
//	cout << &hungry::Singleton::getInstance() << endl;
//	cout << &hungry::Singleton::getInstance() << endl;
//	cout << &hungry::Singleton::getInstance() << endl;
//	hungry::Singleton::getInstance().Add(pair<string, string>{"1","one"});
//	hungry::Singleton::getInstance().Add(pair<string, string>{"2","two"});
//	hungry::Singleton::getInstance().Add({"xxxx","yyyyy"});
//	hungry::Singleton::getInstance().Add({"xxxx1","yyyyy1"});
//	hungry::Singleton::getInstance().Add({"xxxx2","yyyyy2"});
//	hungry::Singleton::getInstance().Print();
//	//Singleton st1(st);
//}

int main() {
	lazy::Singleton::getInstance().Add({ "xxxx","yyyyy" });
	lazy::Singleton::getInstance().Add({ "xxxx1","yyyyy1" });
	lazy::Singleton::getInstance().Add({ "xxxx2","yyyyy2" });
	lazy::Singleton::getInstance().Add({ "xxxx3","yyyyy3" });
	lazy::Singleton::getInstance().Print();

	//lazy::Singleton::DelInstance();
	lazy::Singleton::getInstance().Add({ "xxxx4","yyyyy4" });

	lazy::Singleton::getInstance().Print();
	//lazy::Singleton::DelInstance();
}