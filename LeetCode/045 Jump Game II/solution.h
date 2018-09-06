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
Given an array of non-negative integers, you are initially positioned 
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
	Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:

You can assume that you can always reach the last index.
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*wrong answer
	int jump(vector<int>& nums) {
		int result = 1;
		for (auto i = 0, max_index = i; i < nums.size()-1;) {
			int step = nums[i]; 
			if (i + step >= nums.size() - 1) return result;
			for (auto j = i + 1; j <= step+i &&j <nums.size(); ++j)
				if (nums[j] >= nums[max_index]) max_index = j;
			if(i != max_index) i = max_index,++result;;
			if (i + nums[max_index] >= nums.size() - 1) return result;
		}
		return result;
	}*/
	int jump(vector<int>& nums) {
		int step = 0, max = 0;
		for (auto i = 0, tempMax = 0; i <= max && i < nums.size() - 1; ++i) {
			tempMax = std::max(tempMax, nums[i] + i);
			if (i == max) {
				max = tempMax;
				++step;
				//optimization
				if (max >= (nums.size() - 1)) return step;
			}
		}
		return max >= (nums.size() -1) ? step : -1;
	}

};