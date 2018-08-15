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
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

	Given array nums = [-1, 0, 1, 2, -1, -4],

	A solution set is:
	[
		[-1, 0, 1],
		[-1, -1, 2]
	]

*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.empty() || nums.size() < 2) return vector<vector<int>>();
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> ivv;
		//specified analysis
		//a bad idea
		/*
		if (*nums.begin() == *std::prev(nums.end())) {
		if (nums.size() >= 3 ? (*nums.begin() == 0) : false) {
		ivv.push_back({ nums[0] , nums[1] , nums[2] });
		return ivv;
		}
		return vector<vector<int>>();
		}*/
		for (auto i = 0; i < nums.size() - 2; ++i) {
			auto j = i + 1;
			auto k = nums.size() - 1;
			//line 40 and 41 : algorithm optimization
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			while (k > j) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					//think seriously why we do not use code in line 47 and 48 instead of code in line 45
					//if (std::find(ivv.begin(), ivv.end(), vector<int>{ nums[i], nums[j], nums[k] }) == ivv.end())
					ivv.push_back({ nums[i] , nums[j] , nums[k] });
					while (j < k && nums[j] == nums[j + 1]) ++j;
					while (j < k && nums[k] == nums[k - 1]) --k;
				}
				nums[i] + nums[j] + nums[k] > 0 ? --k : ++j;
			}
		}
		return ivv;
	}
};
