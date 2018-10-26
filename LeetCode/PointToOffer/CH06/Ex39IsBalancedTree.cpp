/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

#include <iostream>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, depth);
	}
private:
	bool IsBalanced(TreeNode* root, int& depth) {
		if (!root) {
			depth = 0;
			return true;
		}

		int left, right;

		if (IsBalanced(root->left, left) && IsBalanced(root->right, right)) {
			int diff = left - right;
			if (std::abs(diff) <= 1) {
				depth = 1 + (left > right ? left : right);
				return true;
			}
			else
				return false;
		}
		return false;
	}
};

int main(){
	
}	