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
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
#pragma once

#include <vector>

using std::vector;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (int i = 0; i < matrix.size() && i < matrix[0].size(); ++i) {
			if (matrix[i][i] == target) return true;
			else{
				for (auto k  = i; k < matrix[0].size(); ++k) {
					if (matrix[i][k] == target) return true;
				}
				for (auto k = i; k < matrix.size(); ++k) {
					if (matrix[k][i] == target) return true;
				}
			}
			
		}
		return false;
	}
};
