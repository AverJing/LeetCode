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
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot) return 0;

		int nLeft = TreeDepth(pRoot->left);
		int nRight = TreeDepth(pRoot->right);

		return nLeft > nRight ? nLeft + 1 : nRight + 1;
	}
};

int main(){
	
}	