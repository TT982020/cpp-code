#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <map>

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

// �����һ���࣬���ܱ��̳�,���캯��˽�л������������в��ɼ���
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

//����ģʽ(����ģʽ)
//һ��ʼ��main����֮ǰ���ʹ�������
//1. ������������ʼ�����ݺܶ࣬��Ӱ�������ٶ�
//2. ��������������࣬������������ϵ
// ������A��B���������࣬Ҫ��A�ȴ�����B�ٴ�����B�ĳ�ʼ������������A
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

	//Ϊʲô����������Է���˽�У��������Ϊ�����Ͷ�����룬�ͱ�������������fun������������
	//�������fun���������fun����������Է���˽��
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

		//һ�㵥�������ͷ�
		//���ⳡ�� 1. ��;��Ҫ��ʽ�ͷ� 2.�����������Ҫ����һЩ���⶯�����־û���
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
			//Ҫ���map������д���ļ���
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

	//Ϊʲô����������Է���˽�У��������Ϊ�����Ͷ�����룬�ͱ�������������fun������������
	//�������fun���������fun����������Է���˽��
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