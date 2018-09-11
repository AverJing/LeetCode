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
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
	2
   / \
  1   3
Output: true
Example 2:

	5
   / \
  1   4
	 / \
	3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
			 is 5 but its right child's value is 4.
*/
#pragma once
#include <iostream>
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

//note: inorder traversal in BST is ordered.
class Solution {
public:
	vector<long long int> inorderTraversal(TreeNode* root) {
		vector<long long int> result;
		for (stack<TreeNode *> inorder; !inorder.empty() || root;) {
			if (root) {
				inorder.push(root);
				root = root->left;
			}
			else {
				root = inorder.top(); inorder.pop();
				result.push_back(root->val);
				root = root->right;
			}
		}
		return result;
	}
	bool isValidBST(TreeNode* root) {
		if (!root) return false;
		auto result = inorderTraversal(root);
		//bool check = false;
		for (auto iter = result.begin(); ;++iter) {
			auto next = std::next(iter);
			if (next != result.end()) {
				if (*iter >= *next) return false;
			}
			else
				break;
		}
		return true;
	}
};
