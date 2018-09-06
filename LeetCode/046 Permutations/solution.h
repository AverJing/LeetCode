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
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#pragma once
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	vector<vector<int>> permute(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		result.push_back(nums);
		if (nums.size() == 1) return result;
		auto start = std::prev(nums.end());
		bool signal = false;
		for (;;) {
			for (;;) {
				auto last = start--;
				if (*start < *last) {
					auto riter = nums.end();
					while (!(*start < *--riter));
					std::iter_swap(start, riter);
					std::reverse(last, nums.end());
					result.push_back(nums);
					break;
				}
				if (start == nums.begin()) {
					//std::reverse(nums.begin(), nums.end());
					//result.push_back(nums); 
					signal = true; break;
				}
			}
			start = std::prev(nums.end());
			if (signal) break;
		}
		return result;	
	}*/
	//other answer
	// use STL function: next_permutation(in header <algorithm>) 
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ret;
		sort(num.begin(), num.end());
		do {
			ret.push_back(num);
		} while (next_permutation(num.begin(), num.end()));
		return ret;
	}

};