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
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution 
using the divide and conquer approach, which is more subtle.
*/
#pragma once
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	// [8,-19,5,-4,20]
	/*
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int result = nums[0], index = 0;;
		for (auto i = 1; i < nums.size(); ++i) {
			int temp = result;
			for (auto j = index + 1; j <= i; ++j) {
				temp = std:: max(nums[j], temp + nums[j];)
				if (result < temp && temp > nums[j]) result = temp, index = j;
				else if (result < nums[j]) result = nums[j], index = j;
				else;
			}
		}
		return result;
	}*/
	//better answer [8,-19,5,-4,20]
	int maxSubArray(vector<int>& nums) {
		int maxv = nums[0];
		for (int i = 0, benefited = 0; i != nums.size(); ++i)
		{
			benefited = std::max(nums[i], benefited + nums[i]);
			maxv = std::max(maxv, benefited);
		}
		return maxv;
	}
};