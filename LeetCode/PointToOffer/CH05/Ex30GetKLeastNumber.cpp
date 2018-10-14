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
#include <queue>
#include <functional>
#include <set>

using std::vector;
using std::priority_queue;
using std::multiset;

class Solution {
public:
	/*
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k > input.size()) return vector<int>();
		vector<int> result;
		result.reserve(k);
		priority_queue<int, vector<int>, std::greater<int>> min_k(std::greater<int>(), input);
		//priority_queue<int> min_k(std::less<int>(), input);
		//for (auto e : input)
			//min_k.push(e);
		for (int i = 0; i < k; ++i) {
			result.push_back(min_k.top());
			min_k.pop();
		}
		return result;
	}*/
	/*
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k > input.size() || k <= 0) return vector<int>();
		auto start = input.begin(), end = input.end(), index =
			std::partition(start, end, [=](int tmp) { return tmp < *start; });
		while (index - input.begin() != k - 1) {
			if (index - start > k - 1) {
				end = index;
				index = std::partition(start, end, [&](int tmp) { return tmp < *start; });
			}
			else {
				start = index+1;
				index = std::partition(start, end, [&](int tmp) { return tmp < *start; });
			}
		}
		return input;
	}*/
	//use multiset
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k > input.size() || k <= 0) return vector<int>();
		multiset<int, std::greater<int>> result;
		for (auto iter = input.begin(); iter != input.end(); ++iter) {
			if (result.size() < k) {
				result.insert(*iter);
			}
			else {
				if (*iter < *result.begin()) {
					result.erase(result.begin());
					result.insert(*iter);
				}
			}
		}
		return vector<int>(result.begin(), result.end());
	}
};

int main(){
	Solution s;
	for (auto e : s.GetLeastNumbers_Solution({ 4,5,1,6,2,7,3,8 }, 4)) {
		std::cout << e << ' ';
	}
}	