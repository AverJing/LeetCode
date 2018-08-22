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
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	int search(vector<int>& nums, int target) {
		auto result = std::find(nums.begin(), nums.end(), target);
		return result != nums.end() ? result - nums.begin() : -1;
	}*/
	int find(vector<int> &num, int target, int left, int right) {
		if (left > right) return -1;
		int mid = (left + right) / 2;
		if (num[mid] == target) return mid;

		if (num[left] <= num[mid]) {
			if (num[left] <= target && target <= num[mid])
				return find(num, target, left, mid - 1);
			else
				return find(num, target, mid + 1, right);
		}
		if (num[right] >= num[mid])
		{

			if (num[right] >= target && num[mid] <= target)
			{

				return find(num, target, mid + 1, right);

			}

			return find(num, target, left, mid - 1);
		}
	}
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		int ans = find(nums, target, 0, nums.size() - 1);
		return ans;
	}
};

