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
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
	/  \
   15   7
*/
#pragma once

#include <vector>

using std::vector;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	using cIter = vector<int>::const_iterator;
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
	}
	TreeNode *buildTree(cIter preBeg, cIter preEnd, cIter inBeg, cIter inEnd) {
		if (preBeg >= preEnd || inBeg >= inEnd) return NULL;
		TreeNode *root = new TreeNode(*preBeg);
		auto inRoot = std::find(inBeg, inEnd, root->val);
		root->left = buildTree(next(preBeg), next(preBeg, inRoot - inBeg + 1), inBeg, inRoot);
		root->right = buildTree(next(preBeg, inRoot - inBeg + 1), preEnd, next(inRoot), inEnd);
		return root;
	}
};
