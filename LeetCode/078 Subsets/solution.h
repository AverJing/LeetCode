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
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#pragma once

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<int> set(S.cbegin(), S.cend());
		std::sort(set.begin(), set.end());
		int size = pow(2, set.size());
		vector<vector<int>> retv(size);
		for (int i = 0; i < size; ++i)
			for (decltype(set.size()) j = 0; j < set.size(); ++j)
				if ((i >> j) & 0x1) retv[i].push_back(set[j]);
		return retv;
	}
};
