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
Given a binary tree, find the lowest common ancestor (LCA) of 
two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common 
ancestor is defined between two nodes p and q as the lowest node in T 
that has both p and q as descendants (where we allow a node to 
be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

		_______3______
	   /              \
	___5__          ___1__
   /      \        /      \
   6      _2       0       8
		 /  \
		 7   4
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
			 according to the LCA definition.
Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
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
	/*
	stack<TreeNode*> PostOrder(TreeNode* root, TreeNode* para) {
		stack<TreeNode*> stk;
		TreeNode* p = root, *last = root;
		stk.push(p);
		for (; !stk.empty();) {	
			p = stk.top();
			if ((!p->left && !p->right) || (!p->right&&last==p->left) || (last==p->right)) {
				if (p == para) return stk;
				stk.pop();
			}
			else {
				if (p->right) stk.push(p->right);
				if (p->left) stk.push(p->left);
			}
		}
	}*/
	stack<TreeNode*> PostOrder(TreeNode* root, TreeNode* para) {
		TreeNode *p = root, *r = NULL;
		stack<TreeNode*> s;
		while (p || !s.empty()) {
			if (p) {//走到最左边
				s.push(p);
				p = p->left;
			}
			else {
				p = s.top();
				if (p->right && p->right != r)//右子树存在，未被访问
					p = p->right;
				else {
					s.pop();
					if (p == para) return s;				
					r = p;//记录最近访问过的节点
					p = NULL;//节点访问完后，重置p指针
				}
			}//else
		}//while
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		auto stk1 = PostOrder(root, p);
		auto stk2 = PostOrder(root, q);

		for (;;) {
			if (stk1.size() < stk2.size()) stk2.pop();
			else if (stk1.size() > stk2.size()) stk1.pop();
			else break;
		}

		for (; !stk1.empty() && !stk2.empty();) {
			auto p1 = stk1.top();
			auto p2 = stk2.top();
			if (p1 == p2) return p1;
			stk1.pop();
			stk2.pop();
		}
	}
};
