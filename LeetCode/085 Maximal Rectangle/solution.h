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
Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
#pragma once

#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int max_area = 0, i = 0, size = height.size();
		for (stack<int> stk; i < size || !stk.empty(); )
			if (stk.empty() || (i != size && height[stk.top()] <= height[i])) stk.push(i++);
			else {
				int tp = stk.top(); stk.pop();
				max_area = std::max(max_area, height[tp] * (stk.empty() ? i : i - stk.top() - 1));
			}
		return max_area;
	}
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int max_area = 0;
		vector<int> height(matrix[0].size(), 0);
		for (size_t i = 0; i < matrix.size(); ++i) {
			for (size_t j = 0; j < matrix[0].size(); ++j)
				if (matrix[i][j] == '0') height[j] = 0;
				else ++height[j];
			max_area = std::max(max_area, largestRectangleArea(height));
		}
		return max_area;
	}
};