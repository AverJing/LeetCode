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
Given a binary tree, check whether it is a mirror of itself 
(ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
	1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/
#pragma once
#include <iostream>
#include <stack>

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
	//recursion
	/*
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return check(root->left, root->right);
	}
private:
	bool check(TreeNode* left, TreeNode* right) {
		if (left && right)
			if (left->val != right->val) return false;
			else return check(left->left, right->right) && check(left->right, right->left);
		else if (left || right) return false;
		else return true;
	}*/

	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		TreeNode *lt = root->left, *rt = root->right;
		for (stack<TreeNode *> stack; !stack.empty() || (lt&&rt);) {
			if (lt && rt) {
				if (lt->val != rt->val) return false;
				stack.push(lt->right); stack.push(rt->left);
				lt = lt->left; rt = rt->right;
			}
			else if (lt || rt) return false;
			else {
				lt = stack.top(); stack.pop();
				rt = stack.top(); stack.pop();
			}
		}
		if (lt || rt) return false;
		else return true;
	}
};
