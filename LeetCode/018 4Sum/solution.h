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
Given an array nums of n integers and an integer target, are there elements a, b, c, 
and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
	[
		[-1,  0, 0, 1],
		[-2, -1, 1, 2],
		[-2,  0, 0, 2]
	]
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		if (nums.size() < 4) return vector<vector<int>>();

		for (auto it = nums.cbegin(); it != nums.cend() - 3; ++it) {
			//optimization
			if (it > nums.cbegin() && *(it - 1) == *it) continue;
			auto b = std::next(it);
			while (b < nums.cend() - 2) {
				auto e = std::prev(nums.cend()), f = std::next(b);
				while (e > f) {
					if ((*it + *b + *e + *f) == target) {
						result.push_back({ *it, *b, *f, *e });
						//optimization
						while (f < e && *(f + 1) == *f) ++f;
						while (f < e && *(e - 1) == *e) --e;
					}
					*it + *b + *e + *f > target ? --e : ++f;
				}
				//optimization
				while ((b < nums.cend() - 2) && *(b + 1) == *b) ++b;
				++b;
			}
		}
		return result;
	}
};
