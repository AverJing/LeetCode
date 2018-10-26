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
#include <algorithm>

using std::vector;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0) return -1;
		vector<int> result;
		result.reserve(index);
		result.push_back(1);
		int nextUgly = 1;

		for (auto pMultiple2 = result.begin(), pMultiple3 = result.begin(), pMultiple5 = result.begin();
			nextUgly < index;) {
			result.push_back(std::min({ *pMultiple2 * 2, *pMultiple3 * 3, *pMultiple5 * 5 }));

			if (*pMultiple2 * 2 <= result[nextUgly])
				++pMultiple2;
			if (*pMultiple3 * 3 <= result[nextUgly])
				++pMultiple3;
			if (*pMultiple5 * 5 <= result[nextUgly])
				++pMultiple5;
			++nextUgly;
		}
		return result.back();
	}
};

int main(){
	Solution s;
	s.GetUglyNumber_Solution(10);
}	