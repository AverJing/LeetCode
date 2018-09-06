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
Given an array of non-negative integers, 
you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
			 jump length is 0, which makes it impossible to reach the last index.
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:
	bool canJump(vector<int>& nums) {
		int step = 0, max = 0;
		for (auto i = 0, tempMax = 0; i <= max && i < nums.size() - 1; ++i) {
			tempMax = std::max(tempMax, nums[i] + i);
			if (i == max) {
				max = tempMax;
				++step;
				//optimization
				if (max >= (nums.size() - 1)) return true;
			}
		}
		return max >= (nums.size() - 1) ? true : false;
	}
};
