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
#include <deque>
#include <vector>
#include "../../Level0/CH01/TestCase.h"

template<class T>
using Window = std::deque<T>;

template<class T>
using Arr = std::vector<T>;

class Solution {
public:
	template<class T>
	Arr<T> getMaxWindow(Arr<T>& data, int k) {
		if (data.empty() || data.size() < 2 || data.size() < k)
			return {};

		Arr<T> result(data.size() - k + 1, 0);
		Window<int> maxWin;
		int index = 0;
		for (int i = 0; i < data.size(); ++i) {
			while (!maxWin.empty() && data[maxWin.back()] <= data[i]) {
				maxWin.pop_back();
			}
			maxWin.push_back(i);
			if (i >= k-1) {
				result[index++] = data[maxWin.front()];
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	for (int i = 0; i < 10; ++i) {
		testCase t(10,20);
		t.Print();
		std::cout << std::endl;
		for (auto e : s.getMaxWindow(t.getArr(), 3))
			std::cout << e << ' ';
		std::cout << std::endl;
	}
}	