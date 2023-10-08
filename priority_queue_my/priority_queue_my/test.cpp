#include <vector>
#include <iostream>



using namespace std;
#include "priority.h"
int main() {
	bit::priority_queue<int> q;
	q.push(3);
	q.push(2);
	q.push(10);
	q.push(1);
	while (!q.empty())
	{
		cout<< q.top() << " ";
		q.pop();
	}
}