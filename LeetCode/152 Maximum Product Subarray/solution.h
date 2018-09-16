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
Given an integer array nums, find the contiguous subarray 
within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) return 0;
		int maxP = nums[0];
		for (int i = 1, imax = nums[0], imin = nums[0]; i < nums.size(); ++i) {
		// multiplied by a negative makes big number smaller, small number bigger
		// so we redefine the extremums by swapping them
			if (nums[i] < 0) std::swap(imax, imin);

		// max/min product for the current number is either the current number itself
		// or the max/min by the previous number times the current one
			imin = std::min(nums[i], imin * nums[i]);
			imax = std::max(nums[i], imax * nums[i]);

			maxP = std::max(maxP, imax);
		}
		return maxP;
	}
};