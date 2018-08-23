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
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.empty()) return { -1, -1 };
		for (auto i = 0; i < nums.size(); ++i) {
			if (nums[i] < target) continue;
			else if (nums[i] == target) result.push_back(i);
			else
				break;
		}
		if(result.empty()) return {-1, -1};
		else return {result[0], result[result.size() - 1]};
	}*/

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.empty()) return { -1, -1 };
		// notice its return value
		auto start = std::lower_bound(nums.begin(), nums.end(), target);
		if (start == nums.end() || *start != target) return { -1,-1 };
		else result.push_back(start - nums.begin());
		auto end = std::upper_bound(nums.begin(), nums.end(), target);
		if (end == nums.end()) {
			if (nums.back() == target) result.push_back(nums.size() - 1);
			else return { -1,-1 };
		}
		else
			result.push_back(end - nums.begin() - 1);
		return result;
	}
};