/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//求一个有序数组，相邻两数的最大差值
//挺困难的，解析看初级班03   1：41：00分钟
#include <iostream>
#include <vector>
#include <algorithm>

#include "../CH01/TestCase.h"

using std::vector;

template<class T>
int bucket(T value, int len, int minX, int maxX) {
	return (value - minX)* len / (maxX - minX);
}

template<class T>
int maxGap(const T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return 0;

	auto minValue = *std::min_element(rhs.begin(), rhs.end());
	auto maxValue = *std::max_element(rhs.begin(), rhs.end());

	std::vector<int> empty(rhs.size()+1, 0);
	std::vector<int> maxInBucket(rhs.size() + 1, 0);
	std::vector<int> minInBucket(rhs.size() + 1, 0);

	for (int i = 0; i < rhs.size(); ++i) {
		auto bid = bucket(rhs[i], rhs.size(), minValue, maxValue);
		maxInBucket[bid] = empty[bid] ? std::max(maxInBucket[bid], rhs[i]) : rhs[i];
		minInBucket[bid] = empty[bid] ? std::min(minInBucket[bid], rhs[i]) : rhs[i];
		empty[bid] = 1;
	}
	int result = 0;
	int lastMax = maxInBucket[0];
	for (int i = 1; i <= rhs.size(); ++i) {
		if (empty[i]) {
			result = std::max(result, minInBucket[i] - lastMax);
			lastMax = maxInBucket[i];
		}
	}
	return result;
}

int main(){
	for (auto i = 0; i < 20; ++i) {
		testCase t(10, 20);
		std::sort(t.getArr().begin(), t.getArr().end());
		t.Print();
		std::cout << "gap: " << maxGap(t.getArr()) << std::endl;
	}
}	