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

using Window = std::deque<int>;
using Arr = std::vector<int>;

bool isValid(const Arr& data, int L, int R, int k) {
	int Max = INT_MIN;
	int Min = INT_MAX;
	for (int i = L; i <= R; ++i) {
		Max = data[i] > Max ? data[i] : Max;
		Min = data[i] < Min ? data[i] : Min;
	}
	return Max - Min <= k;
}
//Brute force
int getNum1(const Arr& data, int k) {
	int res = 0;

	for (int i = 0; i < data.size(); ++i) {
		for (int j = i; j < data.size(); ++j) {
			if (isValid(data, i, j, k))
				++res;
		}
	}
	return res;
}

int getNum2(const Arr& data, int k) {
	if (data.empty()) return 0;

	int res = 0;
	Window qmin;
	Window qmax;
	int L = 0;
	int R = 0;
	while (L < data.size()) {
		while (R < data.size()) {
			//更新最小值窗口
			while (!qmin.empty() && qmin.back() >= data[R]) {
				qmin.pop_back();
			}
			qmin.push_back(data[R]);
			//更新最大值窗口
			//注意就算当前值和最大值窗口的back相等也要更新
			while (!qmax.empty() && qmax.back() <= data[R]) {
				qmax.pop_back();
			}
			qmax.push_back(data[R]);

			if (qmax.front() - qmin.front() > k) {
				break;
			}
			++R;
		}
		//如果最小值是当前L下标的位置，从窗口中删除
		if (qmin.front() == data[L])
			qmin.pop_front();
		if (qmax.front() == data[L])
			qmax.pop_front();

		res += R - L;
		++L;
	}
	return res;
}

int main(){
	for (int i = 0; i < 20; ++i) {
		testCase t(10, 20);
		t.Print();
		std::cout << std::endl;
		std::cout << getNum2(t.getArr(), 5) << ' ' << getNum1(t.getArr(), 5) << std::endl;
	}
}	