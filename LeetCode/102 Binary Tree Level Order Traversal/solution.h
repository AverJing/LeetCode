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
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
#pragma once
#include <vector>
#include <queue>

using std::vector;
using std::queue;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode *> q1;
		vector<vector<int>> result;
		TreeNode * last = root;
		vector<int> temp;
		q1.push(root); 
		while (!q1.empty()) {
			auto lead1 = q1.front();
			q1.pop();
			if (!lead1 ) continue;
			else if (lead1) temp.push_back(lead1->val);
			if (lead1->left) {
				q1.push(lead1->left);
			}
			if (lead1->right) {
				q1.push(lead1->right);
			}		
			if (lead1 == last) {
				result.push_back(temp);
				temp.clear();
				last = q1.back();
			}
		}
		return result;
	}
};
