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
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> retv;
		std::sort(nums.begin(), nums.end());
		do {
			retv.push_back(nums);
		} while (std::next_permutation(nums.begin(), nums.end()));
		return retv;
	}
};