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
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
#pragma once

#include <vector>

using std::vector;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m > n) std::swap(m, n);
		if (m < 2) return m;
		vector<int> step(n, 1);
		for (auto i = 1; i < m; ++i)
			for (auto j = 1; j < n; ++j)
				step[j] += step[j - 1];
		return step[n - 1];
	}
};
