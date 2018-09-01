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
Given a collection of candidate numbers (candidates) and a target number 
(target), find all unique combinations in candidates 
where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
#pragma once

#include <vector>
#include <set>
using std::vector;
#include <algorithm>
#include <functional>

class Solution {
public:
	void dfs(const vector<int> &num, vector<vector<int>> &ret, int target, vector<int> cur, size_t start) {
		if (target == 0) { ret.push_back(cur); return; }
		for (auto i = start; i < num.size(); ++i)
			if (i > start && num[i] == num[i - 1]) continue;
			else if (num.at(i) <= target) {
				cur.push_back(num.at(i));
				dfs(num, ret, target - num.at(i), cur, i + 1);
				cur.pop_back();
			}
			else break;
	}

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>> ret;
		std::sort(num.begin(), num.end());
		dfs(num, ret, target, vector<int>{}, 0);
		return ret;
	}
};