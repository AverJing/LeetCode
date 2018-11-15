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

#include "../Level0/CH01/TestCase.h"

using Arr = std::vector<int>;

//没两个元素为一组，先比较，较小的和min比较，较大的和max比较  总共的比较次数大概
//为  3*n/2
//而常规的思路  为2*n

std::pair<int, int> getMinMax(const Arr& data) {
	int maxNum = INT_MIN;
	int minNum = INT_MAX;

	if (data.size() & 0x1)
		maxNum = minNum = data.back();

	for (int i = 0; i + 1< data.size(); i+=2) {
		if (data[i] < data[i + 1]) {
			minNum = data[i] > minNum ? minNum : data[i];
			maxNum = data[i+1] < maxNum ? maxNum : data[i+1];
		}
		else {
			minNum = data[i + 1] > minNum ? minNum : data[i + 1];
			maxNum = data[i] < maxNum ? maxNum : data[i];
		}
	}
	return { minNum, maxNum };
}


int main(){
	auto res = getMinMax({ 5,3,2,7,8,9,1 });
	std::cout << res.first << ' ' << res.second << std::endl;
}	