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
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from 
some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

	   1
	  / \
	 2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
	/  \
   15   7

Output: 42
*/
#pragma once
#include <cstddef>
#include <algorithm>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode *root, int &maxSum) {
		if (!root) return 0;
		int leftMax = std::max(0, maxPathSum(root->left, maxSum));
		int rightMax = std::max(0, maxPathSum(root->right, maxSum));
		maxSum = std::max(maxSum, leftMax + rightMax + root->val);
		return root->val + std::max(leftMax, rightMax);
	}

public:
	int maxPathSum(TreeNode *root) {
		int maxSum = INT_MIN;
		maxPathSum(root, maxSum);
		return maxSum;
	}
};