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
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	void nextPermutation(vector<int>& nums) {
		std::next_permutation(nums.begin(), nums.end());
	}*/

	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		auto start = std::prev(nums.end());
		for (;;) {
			auto last = start--;
			if (*start < *last) {
				auto riter = nums.end();
				while (!(*start < *--riter));
				std::iter_swap(start, riter);
				std::reverse(last, nums.end());
				return;
			}
			if (start == nums.begin()) {
				std::reverse(nums.begin(), nums.end());
				return;
			}
		}
	}
};