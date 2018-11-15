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

using Arr = std::vector<int>;

int getMaxRec(Arr& height) {
	std::stack<int> s;
	int maxRec = INT_MIN;
	for (int j = 0; j < height.size(); ++j) {
		//栈中的值从小到大
		while (!s.empty() && height[s.top()] >= height[j]) {
			auto k = s.top();
			s.pop();
			auto L = s.empty() ? -1 : s.top();
			int res = (j - L - 1)*height[k];
			maxRec = res > maxRec ? res : maxRec;
		}
		s.push(j);
	}
	while (!s.empty()) {
		auto k = s.top();
		s.pop();
		auto L = s.empty() ? -1 : s.top();
		int res = (height.size() - L - 1)*height[k];
		maxRec = res > maxRec ? res : maxRec;
	}
	return maxRec;
}

template<class T>
int getMaxSubRec(const T& data) {
	if (data.empty()) return 0;

	int res = 0;

	Arr height(data[0].size(), 0);
	int maxRec = 0;
	for (int i = 0; i < data.size(); ++i) {	
		for (int j = 0; j < data[0].size(); ++j) {
			height[j] = data[i][j] ? height[j] + data[i][j] : 0;
		}
		maxRec = std::max(getMaxRec(height), maxRec);
	}
	return maxRec;
}

int main(){
	std::cout << getMaxSubRec(
		std::vector<std::vector<int>>{
			{ 1, 0, 1, 1 },
			{ 1, 1, 0, 1 },
			{ 1, 1, 1, 0 }});
}	