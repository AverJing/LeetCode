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
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
	5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
	5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/
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

class Solution {
public:
	void InOrder(TreeNode* head, vector<int>& seq) {
		stack<TreeNode*> res;
		while (!res.empty() || head) {
			if (head) {
				res.push(head);
				head = head->left;
			}
			else {
				head = res.top();
				res.pop();
				seq.push_back(head->val);			
				head = head->right;
			}
		}
	}
	bool findTarget(TreeNode* root, int k) {
		vector<int> num;
		InOrder(root, num);

		for (int i = 0, j = num.size() - 1; i < j;) {
			int sum = num[i] + num[j];
			if (sum == k) return true;
			else if (sum < k) ++i;
			else --j;
		}
		return false;
	}
};

int main(){
	
	return 0;
}