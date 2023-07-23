#include "string.h"
using namespace std;
inline ostream& operator << (ostream& os, const String& str) {
	os << str.get_c_str() << endl;
	return os;
}

int main() {
	String s1("hello");
	String s2(s1);
	s2 = s1;
	
	cout << s1 << s2;
}