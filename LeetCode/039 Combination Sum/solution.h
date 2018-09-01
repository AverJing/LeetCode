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
Given a set of candidate numbers (candidates) (without duplicates) and 
a target number (target), find all unique combinations in candidates 
where the candidate numbers sums to target.

The same repeated number may be chosen from candidates 
unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
#pragma once

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> ret;
		std::sort(candidates.begin(), candidates.end());
		dfs(candidates, target, vector<int>{}, 0, ret);
		return ret;
	}
	void dfs(const vector<int> &cdds, int target, vector<int> curr, size_t index, vector<vector<int>> &ret) {
		if (!target) { ret.push_back(curr); return; }
		for (auto i = index; i < cdds.size(); ++i)
			if (cdds[i] <= target) {
				curr.push_back(cdds[i]);
				dfs(cdds, target - cdds[i], curr, i, ret);
				curr.pop_back();
			}
			else break;
	}
};