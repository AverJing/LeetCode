/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::stack;
using std::vector;

class Solution {
public:
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
		if (pushV.empty() || popV.empty() || pushV.size()!=popV.size()) return false;

		stack<int> data;
		auto iter = pushV.begin();
		for (int i = 0; i < popV.size(); ++i) {
			if(data.empty() || data.top() != popV[i]) {
				auto tmp = find(iter, pushV.end(), popV[i]);
				if (tmp == pushV.end()) return false;
				for (auto beg = iter; beg != tmp; ++beg)
					data.push(*beg);
				iter = std::next(tmp);
			}
			else if (data.top() == popV[i]) data.pop();
		}
		return true;
	}
};

int main(){
	vector<int> i1{ 1,2,3,4,5 };
	vector<int> i2{ 4,5,3,1,2 };
	Solution s;
	std::cout << s.IsPopOrder(i1, i2);
}	