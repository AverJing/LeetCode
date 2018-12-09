/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this 
place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, adjacent houses have security 
system connected and it will automatically contact the police if two 
adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob 
tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
			 because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
			 Total amount you can rob = 1 + 3 = 4.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	int rob(const vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		return std::max(getValue(nums.begin(), std::prev(nums.end())),
			getValue(std::next(nums.begin()), nums.end()));
		
	}
	template<typename Iter>
	int getValue(Iter begin, Iter end) {
		int prev1 = 0, prev2 = 0;

		for (; begin < end; ++begin) {
			int tmp = prev1;
			prev1 = std::max(*begin + prev2, prev1);
			prev2 = tmp;
		}
		return prev1;
	}*/
	//思路一样
	//避免函数调用
	int rob(const vector<int>& nums) {
		int n = nums.size();
		if (n==0) return 0;
		if (n == 1) return nums[0];

		int prev1 = 0, prev2 = 0;

		for (int i = 0; i < n-1; ++i) {
			int tmp = prev1;
			prev1 = std::max(nums[i] + prev2, prev1);
			prev2 = tmp;
		}
		int ret = prev1;
		prev1 = 0;
		prev2 = 0;

		for (int i = 1; i < n; ++i) {
			int tmp = prev1;
			prev1 = std::max(nums[i] + prev2, prev1);
			prev2 = tmp;
		}
		return std::max(ret, prev1);
	}
};

int main(){
	
}	