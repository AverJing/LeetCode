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
Given a binary tree and a sum, find all root-to-leaf paths where each 
path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

	  5
	 / \
	4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <iostream>
#include <vector>

using std::vector;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool process(TreeNode* root, int sum) {
	if (!root) return false;
	sum -= root->val;
	if (sum == 0&&!root->left&&!root->right) return true;
	return process(root->left, sum) || process(root->right, sum);
}

bool hasPathSum(TreeNode* root, int sum) {
	if (root) {
		return process(root, sum);
	}
	return false;
}

//better answer
/*
bool hasPathSum(TreeNode* root, int sum) {
	if(!root) return false;
	if(!root->left && !root->right) return root->val == sum;

	return hasPathSum( root->left, sum- root->val) || hasPathSum( root->right, sum -root->val);

}
*/

class Solution {
public:
	void process(TreeNode* root, int sum, vector<vector<int>>& res, vector<int> tmp) {
		if (!root) return;
		tmp.push_back(root->val);
		sum -= root->val;
		if (sum == 0 && !root->left && !root->right) {
			res.push_back(tmp);
		}
		process(root->left, sum, res, tmp);
		process(root->right, sum, res, tmp);
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		process(root, sum, res, vector<int>());
		return res;
	}
};

int main(){
	
}	