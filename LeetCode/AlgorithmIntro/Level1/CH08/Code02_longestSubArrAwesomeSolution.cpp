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

int getMaxLength(const vector<int>& arr, int aim) {
	if (arr.empty()) return 0;

	vector<int> min_sum(arr.size(), 0);
	vector<int> min_sum_index(arr.size(), 0);
	min_sum.back() = arr.back();
	min_sum_index.back() = arr.size() - 1;
	//min_sum[i]以i开头的所有子数组的最小累加和
	//min_sum_index[i]取得最小累加和的右边界
	for (int i = arr.size() - 2; i >= 0; --i) {
		min_sum_index[i] = min_sum_index[i + 1];
		min_sum[i] = min_sum[i + 1] < 0 ? min_sum[i] + min_sum[i + 1] : min_sum[i];
	}
	int end = 0;
	int sum = 0;
	int res = 0;
	for (int i = 0; i < arr.size(); ++i) {
		while (end < arr.size() && sum + min_sum[end] <= aim) {
			sum += min_sum[end];
			end = min_sum_index[end] + 1;
		}
		sum -= end > i ? arr[i] : 0;
		res = std::max(res, end - i);
		end = std::max(end, i + 1);
	}
	return res;
}

int main(){
	
}	