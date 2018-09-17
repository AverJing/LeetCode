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
Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. An island is surrounded by water 
and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
#pragma once

#include <vector>

using std::vector;

class Solution {
public:
	int dep(vector<vector<char>>& grid, int row, int colm) {
		int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
		if (grid[row][colm] == '0' || grid[row][colm] == '*') return 1;
		grid[row][colm] = '*';
		if (row > 0) res1 = dep(grid, row - 1, colm);
		else res1 = 1;

		if (row < grid.size() - 1) res2 = dep(grid, row + 1, colm);
		else res2 = 1;

		if (colm > 0) res3 = dep(grid, row, colm - 1);
		else res3 = 1;

		if (colm < grid[0].size() - 1) res4 = dep(grid, row, colm + 1);
		else res4 = 1;
		return res1 && res2&&res3&&res4;
	}
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		int count = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == '1') count += dep(grid, i, j);
			}
		}
		return count;
	}
};
