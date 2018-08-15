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
Given an array nums of n integers and an integer target, find three integers in nums such that 
the sum is closest to target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:

	Given array nums = [-1, 2, 1, -4], and target = 1.

	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
#pragma once
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		std::sort(nums.begin(), nums.end());
		int min(INT_MAX), sum(0), tmtarget(0);

		for (auto it = nums.cbegin(); it != nums.cend(); ++it) {
			for (auto b = std::next(it), e = std::prev(nums.cend()); b < e; tmtarget > target ? --e : ++b) {
				if ((tmtarget = *it + *b + *e) == target) return target;
				else if (std::abs(tmtarget - target) < min) {
					sum = tmtarget; min = std::abs(tmtarget - target);
				}
			}
		}
		return sum;
	}
};
