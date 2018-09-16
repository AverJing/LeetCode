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
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element 
always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	int majorityElement(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}*/
	//https://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
	//Moore's voting algorithm
	int majorityElement(vector<int>& nums) {
		int curr = nums[0], count = 0;

		for (auto &e : nums) {
			if (curr == e) {
				++count;
			}
			else if (count == 0) {
				curr = e;
				++count;
			}
			else {
				--count;
			}
		}
	}
};
