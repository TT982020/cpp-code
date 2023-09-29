#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <class T>
T* func(int n) {
	return new T[n];
}
// ר�Ŵ���int�ļӷ�����
int Add(int left, int right)
{
	return left + right;
}
// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
	return left + right;
}
void Test()
{
	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
	Add<int>(1, 2); // ���ñ������ػ���Add�汾
}
// ��̬˳���
// ע�⣺Vector���Ǿ�����࣬�Ǳ��������ݱ�ʵ�������������ɾ������ģ��
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	// ʹ������������ʾ�������������������ⶨ�塣
	~Vector();

	void PushBack(const T& data);
	void PopBack();
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
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
template <class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

void test_string1() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << s1 << endl;
	cout << s2 << endl;
	string ret1 = s1 + s1;
	cout << ret1 << endl;

}

void test_string2() {
	string s1("hello, world");
	string s2 = "hello, world";

	//����string
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i]++;
	}
	cout << s1 << endl;
	//����������
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//������д
	it = s1.begin();
	while (it != s1.end())
	{
		*it = 'a';
		++it;
	}
	cout << s1 << endl;

	list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	
	list<int>::iterator lit = lst.begin();
	while (lit != lst.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
}

void test_string3() {
	string s1("hello, world");
	string::reverse_iterator rit = s1.rbegin();
	//auto rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout<<endl;

	//ԭ���������滻�ɵ�����, ch����*it�Ŀ���,���Ҫ�ı�ch������������
	//���ô��﷨������˵�������ռ�
	for (auto& ch : s1) {
		ch++;
		cout << ch << " ";
	}
	cout << endl;
	cout << s1 << endl;
	
}

//������ʹ��string s��Ϊ�˱��⿽������������������Լ�����
void func(const string& s) {
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		//��֧��д
		//*it = 'a';
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::const_reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_string4() {
	string s1("hello worldxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyy");
	string s2(s1, 6, 5);
	cout << s2 << endl;
	string s3(s1, 6, 3);
	cout << s3 << endl;
	string s4(s1, 6);
	cout << s4 << endl;
	string s5(10, 'a');
	cout << s5 << endl;

	string s6(++s5.begin(), --s5.end());
	cout << s6 << endl;

	s6 = s5;
	s6 = "aaa";
	s6 = 'a';
}

void test_string5() {
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	s1.clear();//�����ͷſռ䣬capacity��Ϊ0
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;  //max_size �Ƚϲ�׼

	string filename;
	FILE* fout = fopen(filename.c_str(), "r ");

}

int main() {
	//test_string1();
	test_string5();
}

//int main() {
//	int a = 1, b = 2;
//	swap(a, b);
//	int* p = func<int>(5);
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//}