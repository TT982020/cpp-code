#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class C
{
public:
	C();
	~C();

	
	void* operator new (size_t size);
	//void* operator new[](size_t size);
	void operator delete(void* pf);
	//void operator delete[](void* pf);
private:

};

C::C()
{
}

C::~C()
{
}
int main() {

}