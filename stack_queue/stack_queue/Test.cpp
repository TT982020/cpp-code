#include "Stack.h"
#include "Queue.h"
using namespace std;
int main() {
	B::queue<int, list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(14);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

}