/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>

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

		if (row < grid.size()-1) res2 = dep(grid, row + 1, colm);
		else res2 = 1;

		if (colm > 0) res3 = dep(grid, row, colm - 1);
		else res3 = 1;

		if (colm < grid[0].size()-1) res4 = dep(grid, row, colm + 1);
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


int main(){

	vector<vector<char>>  grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'} };

	Solution s;
	std::cout << s.numIslands(grid);
}	