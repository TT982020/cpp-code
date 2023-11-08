#include "RBTree.h"
#include "AVLTree.h"
#include <vector>
//int main() {
//	int a[] = { 30431, 408, 8118, 21614,27453, 8538};
//	RBTree<int, int> t;
//	for (auto e : a) {
//		if (e== 8538)
//		{
//			int x = 0;
//		}
//		t.Insert(make_pair(e, e));
//		t.IsBalance();
//	}
//	//t.InOrder();	
//}

int main() {
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (int i = 0; i < N; i++) {
		v.push_back(rand());
	}
	RBTree<int, int> t1;
	AVLTree<int, int> t2;
	for (auto e : v) {
		t1.Insert(make_pair(e, e));
		t2.Insert(make_pair(e, e));
		//cout << e << ":" << t.IsBalance() << endl;
	}
	cout << t1.IsBalance() << endl;
	cout << t2.IsBalance() << endl;
	cout << t1.Height() << endl;
	cout << t2.Height() << endl;
	cout << t1.rotateCount << endl;
	cout << t2.rotateCount << endl;
}