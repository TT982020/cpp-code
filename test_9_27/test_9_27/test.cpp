#define _CRT_SECURE_NO_WARNINGS 1
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
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
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

	//遍历string
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
	//迭代器遍历
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//迭代器写
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

	//原理，编译器替换成迭代器, ch就是*it的拷贝,如果要改变ch，可以用引用
	//引用从语法层面来说，不开空间
	for (auto& ch : s1) {
		ch++;
		cout << ch << " ";
	}
	cout << endl;
	cout << s1 << endl;
	
}

//不建议使用string s，为了避免拷贝，而且是深拷贝，所以加引用
void func(const string& s) {
	string::const_iterator it = s.begin();
	while (it != s.end())
	{
		//不支持写
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

	s1.clear();//不会释放空间，capacity不为0
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;  //max_size 比较不准

	string filename;
	FILE* fout = fopen(filename.c_str(), "r ");

}

void test_string6() {
	string s;
	int old = s.capacity();
	s.reserve(100);
	cout << "capacity = " << s.capacity() << endl;
	for (int i = 0; i < 100; i++)
	{
		s.push_back(i);
		if (old != s.capacity())
		{
			cout << "capacity = " << s.capacity() << endl;
			old = s.capacity();
		}
	}
	s.reserve(10);  //一般不缩小
	cout << "capacity = " << s.capacity() << endl;
}

void test_string7() {
	string s1("hello world");
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(13, 'x');
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(13);
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(20);
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(5);
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	string s2;
	s2.resize(10, '#');
	cout << s2 << endl;
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}

void test_string8() {
	string ss("world");
	string s;
	s.push_back('#');
	s.append("hello ");
	s.append(ss);
	cout << s << endl;

	s += '#';
	s += "hello";
	s += ss;
	cout << s << endl;

	string ret1 = ss + '#';
	string ret2 = ss + " hello";
	cout << ret1 << endl;
	cout << ret2 << endl;
}

void test_string9() {
	string str;
	string base = "a big brown fox run over a dog.";
	str.assign(base, 5, 10);
	cout << str << endl;
}


void test_string10() {
	//insert/erase/replace 都不建议使用，涉及挪动数据，效率不高
	//接口设计复杂，需要用的时候查一下
	string str("hello world");
	str.insert(0, 1, 'x');
	str.insert(0, 1, 'x');

	str.insert(str.begin(), 'x');
	cout << str << endl;


	str.erase(5);
	cout << str << endl;

	/*string s1("hello world");
	s1.replace(5, 1, "%%20");
	cout << s1 << endl;*/

	//空格替换为%20
	string s1 = "The quick brown fox jumps over a lazy dog.";
	string s2;
	for (auto ch : s1) {
		if (ch != ' ')
		{
			s2 += ch;
		}
		else {
			s2 += "%20";
		}
	}
	s1.swap(s2);
	cout << s1 << endl;
}

void test_string11() {
	string s1("test.cpp.tar.zip");
	//size_t i = s1.find('.');
	size_t i = s1.rfind('.');
	string s2 = s1.substr(i);
	cout << s2 << endl;

	string s3("https://legacy.cplusplus.com/reference/string/string/substr/");
	size_t i1 = s3.find(':');
	if (i1 != string::npos)
	{
		string protocol = s3.substr(0, i1);
		cout << protocol << endl;
	}
	else
	{
		cout << "没有找到i1" << endl;
	}
	
	size_t i2 = s3.find('/', i1 + 3);
	if (i2 != string::npos)
	{
		string name = s3.substr(i1 + 3, i2 - (i1 + 3));
		cout << name << endl;
	}
	else
	{
		cout << "没有找到i2" << endl;
	}

	string resource = s3.substr(i2 + 1);
	cout << resource << endl;

}

void test_string12() {
	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::size_t found = str.find_first_of("abc");
	//int count[26] = { 0 }; 计数法，判断是否是 abc，相应位置置为1
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("abc", found + 1); //find_any_of
		//found = str.find_last_of("abc", found + 1); //find_any_of
		//found = str.find_first_not_of("abc", found + 1); //find_any_of
		//found = str.find_last_not_of("abc", found + 1); //find_any_of
	}

	std::cout << str << '\n';
}

void reverse(string s, int left, int right) {
	while (left < right) {
		swap(s[left++], s[right--]);
	}
}
string reverseWords(string s) {
	//getline(cin, s);
	int left = 0, right = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == ' ') {
			right = i;
			reverse(s, left, right);
			left = i + 1;
		}
	}
	//cout<<s<<endl;
	return s;
}

int main() {
	//test_string1();
	//test_string12();
	string str = reverseWords("\"hello world\"");
	cout << str << endl;
	
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