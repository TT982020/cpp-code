#include <iostream>
#include <vector>
using namespace std;

//全排列的方法---深度遍历
void traverse(vector<vector<int>>& v, int k, vector<vector<int>>& res, vector<int>& cur) {
	if (k == v.size())
	{
		res.push_back(cur);
		return;
	}
	for (size_t i = 0; i < v[k].size(); i++)
	{
		cur.push_back(v[k][i]);

		traverse(v, k + 1, res, cur);
		cur.pop_back();
	}
}

//17. 电话号码的字母组合
const char* numArray[10] = { "", "" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

//注意一点，这里不需要再遍历完之后移除，因为Combine(digits, i + 1, combinestr + e, res);
//没有改变i，也没有改变combinestr，当递归结束回来可以继续使用
void Combine(string digits, int i, string combinestr, vector<string>& res) {
	if (i == digits.size()) {
		res.push_back(combinestr);
		return;
	}
	int num = digits[i] - '0';
	string str = numArray[num];
	for (auto e : str) {
		Combine(digits, i + 1, combinestr + e, res);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> res;
	if (digits.empty()) {
		return res;
	}
	Combine(digits, 0, "", res);
	return res;
}

//或者改成如下版本也可以
void Combine1(string digits, int i, string combinestr, vector<string>& res) {
	if (i == digits.size()) {
		res.push_back(combinestr);
		return;
	}
	int num = digits[i] - '0';
	string str = numArray[num];
	for (auto e : str) {
		combinestr.push_back(e);
		Combine(digits, i + 1, combinestr, res);
		combinestr.pop_back();
	}
}

vector<string> letterCombinations1(string digits) {
	vector<string> res;
	string s;
	if (digits.empty()) {
		return res;
	}
	Combine(digits, 0, s, res);
	return res;
}

int main() {
	vector<vector<int>> res;
	vector<int> cur;
	vector<int> v1;
	
	v1.push_back(1);
	v1.push_back(2);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);

	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);

	traverse(v, 0, res, cur);
	for (auto e : res) {
		for (auto ee : e) {
			cout << ee << " ";
		}
		cout << endl;
	}
}