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
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

	1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6
*/
#pragma once
#include <vector>
#include <stack>

using std::vector;
using std::stack;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode *root) {
		for (; root; root = root->right)
			if (root->left) {
				TreeNode *end = root->left;
				while (end->right) end = end->right;
				end->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
	}
};