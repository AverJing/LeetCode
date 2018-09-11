/*
*
*
*@author: Aver Jing
*@description：
*@date：Sep 11, 2018
*
*
*/
/*
Given two binary trees, write a function to check 
if they are the same or not.

Two binary trees are considered the same 
if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
		  / \       / \
		 2   3     2   3

		[1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
		  /           \
		 2             2

		[1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
		  / \       / \
		 2   1     1   2

		[1,2,1],   [1,1,2]

Output: false

*/
#pragma once

#include <queue>

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		queue<TreeNode *> q1, q2;
		if (!p && !q) return true;
		q1.push(p); q2.push(q);
		while (!q1.empty() && !q2.empty()) {
			auto lead1 = q1.front(), lead2 = q2.front();
			q1.pop(); q2.pop();
			if (!lead1 && !lead2) continue;
			else if (!lead1 && lead2) return false;
			else if (lead1  && !lead2 ) return false;
			else if(lead1->val != lead2->val) return false;
			
			q1.push(lead1->left), q2.push(lead2->left);
			q1.push(lead1->right), q2.push(lead2->right);
		}
		return true;
	}
	//recursion
	/*
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p && q) return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else if (!p && !q) return true;
		else return false;
	}*/
};