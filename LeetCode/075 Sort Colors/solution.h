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
Given an array with n objects colored red, white or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, 
white, and blue respectively.

Note: You are not suppose to use the library's sort function 
for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/* bad answer
	void sortColors(vector<int>& nums) {
		vector<int> result;
		int count0 = 0, count1 = 0, count2 = 0;
		for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
			if (*iter == 0) ++count0;
			else if (*iter == 1) ++count1;
			else if (*iter == 2) ++count2;
		}
		for (auto i = 0; i < count0 + count1 + count2; ++i) {
			if (i < count0) result.push_back(0);
			else if (i < count0 + count1) result.push_back(1);
			else result.push_back(2);
			
		}
		nums = result;
	}*/
	/*
	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) return;
		//order of variable initialization in for(beg, end) is not from left to right. random.
		for (auto beg = nums.begin(), end = std::next(nums.begin()); beg != nums.end();) {
			if (*beg > *end) {
				std::swap(*beg, *end);
			}
			++end;
			if (end == nums.end()) {
				++beg;
				if (beg == std::prev(nums.end())) break;
				else {
					end = std::next(beg);
				}
			}
		}
	}*/

	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) return;
		
		int zero = -1, one = 0, two = nums.size();

		while (one < two) {
			if (nums[one] == 0) {
				swap(nums, ++zero, one++);
			}
			else if (nums[one] == 2) {
				swap(nums, --two, one);
			}
			else {
				++one;
			}
		}
	}

	void swap(vector<int>& nums, int i, int j) {
		std::swap(nums[i], nums[j]);
	}
};
