#include "AVLTree.h"
#include <vector>

//int main() {
//	int a[] = { 24934,5877,9126,13292,25789,24399 };
//	AVLTree<int, int> t;
//	for (auto e : a) {
//		if (e== 24399)
//		{
//			int x = 0;
//		}
//		t.Insert(make_pair(e, e));
//		t.isBalance();
//	}
//	t.InOrder();	
//}

int main() {

	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (int i = 0; i < N; i++) {
		v.push_back(rand());
	}
	AVLTree<int, int> t;
	for (auto e : v) {
		t.Insert(make_pair(e, e));
		//cout << e << " ";
		//cout << t.isBalance() << endl;
	}
	cout << t.isBalance() << endl;
	
	
}