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
Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

	  5
	 / \
	4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 
which sum is 22.
*/
#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool process(TreeNode* root, int sum) {
		sum -= root->val;
		if (sum == 0) return true;
		if (!root) return false;
		return process(root->left, sum)|| process(root->right, sum);	
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
};

int main(){
	
}	