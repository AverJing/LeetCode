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
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
	\
	 2
	/
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
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
};