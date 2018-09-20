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
Given an array nums of n integers where n > 1,  
return an array output such that output[i] is equal to 
the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? 
(The output array does not count as extra space for the purpose of 
space complexity analysis.)
*/
#pragma once

#include <vector>

using std::vector;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int N = nums.size();
		vector<int> ans(N, 1);
		int left = 1, right = 1;

		for (int i = 1; i < N; ++i) {
			left *= nums[i - 1];
			ans[i] *= left;
		}

		for (int i = N-2; i >= 0; --i) {
			right *= nums[i + 1];
			ans[i] *= right;
		}

		return ans;
	}
};
