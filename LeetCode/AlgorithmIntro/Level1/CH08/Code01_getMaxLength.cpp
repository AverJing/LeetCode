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
#include "../../Level0/CH01/TestCase.h"

using Arr = std::vector<int>;

int getMaxLength(const Arr& data, int aim) {
	if (data.empty())return 0;

	int L = 0, R = 0;
	int sum = data[0];
	int res = 0;
	for (; L < data.size();) {
		if (sum < aim) {
			++R;
			if (R == data.size())
				break;
			sum += data[R];
		}
		else if (sum == aim) {
			res = std::max(res, R - L + 1);
			sum -= data[L++];
		}
		else {
			sum -= data[L++];
		}
	}
	return res;
}

int main(){
	for (int i = 0; i < 30; ++i) {
		testCase t(10, 10);
		t.Print();
		std::cout << ' ' << getMaxLength(t.getArr(), 10);
		std::cout << std::endl;
	}
}	