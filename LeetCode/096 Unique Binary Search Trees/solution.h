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
Given n, how many structurally unique BST's (binary search trees) 
that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3
*/
#pragma once
#include <climits>

class Solution {
public:
	int numTrees(int n) {
		long long res = 1;
		for (auto i = 1; i <= n; ++i)
			res = res * 2 * (2 * i - 1) / (i + 1);
		return res > INT_MAX ? 0 : res;
	}
};
