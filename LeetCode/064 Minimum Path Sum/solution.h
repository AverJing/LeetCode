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
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) return  0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (i == 0 && j == 0) continue;
				else if (i == 0 && j != 0) grid[i][j] += grid[i][j - 1];
				else if (i != 0 && j == 0) {
					grid[i][j] += grid[i - 1][j];
				}
				else if (i != 0 && j != 0) {
					grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
				}
			}
		}
		return grid[grid.size() - 1][grid[0].size() - 1];
	}
};
