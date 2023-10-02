#include <iostream>
#include <vector>
#include <string>
using namespace std;
void test_vector1() {
	vector<int> v1;
	vector<int> v2(10, 0);

	vector<int> v3(v2.begin(), v2.end());

	string str("hello,world");
	vector<int> v4(str.begin(), str.end());
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v4.begin();
	while (it!=v4.end())
	{
		cout << (char)*it << " ";
		++it;
	}
	cout << endl;
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector3() {
	vector<int> v1;
	cout << v1.max_size() << endl;

	vector<int> v;
	//v.reserve(100);  // size = 0, capacity = 100
	v.resize(100);     // size = 100, capacity = 100  

	for (size_t i = 0; i < v.size(); i++)
	{
		//会断言，如果访问下标超出size，会报错
		v[i] = i;
	}
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}

void test_vector4() {

}

int main() {
	
	test_vector4();
	//TestVectorExpand();
}