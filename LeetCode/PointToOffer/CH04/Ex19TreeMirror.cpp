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
#include <stack>

using std::stack;

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
	void Mirror(TreeNode *pRoot) {
		if (!pRoot || (!pRoot->left && !pRoot->right)) return;

		std::swap(pRoot->left, pRoot->right);

		if (pRoot->left) Mirror(pRoot->left);
		if (pRoot->right) Mirror(pRoot->right);
	}
	//use preOrder
	void Mirror(TreeNode *pRoot) {
		if (!pRoot || (!pRoot->left && !pRoot->right)) return;

		for (stack<TreeNode*> preOrder; !preOrder.empty() || pRoot;) {
			if (pRoot) {
				preOrder.push(pRoot);
				//visit node
				if(pRoot->left || pRoot->right)
					std::swap(pRoot->left, pRoot->right);
				pRoot = pRoot->left;
			}
			else {
				pRoot = preOrder.top();
				preOrder.pop();
				pRoot = pRoot->right;
			}
		}
	}
	//level order is better?
};

int main(){
	
}	