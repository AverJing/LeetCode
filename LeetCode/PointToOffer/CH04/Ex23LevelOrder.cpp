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
#include <vector>
#include <queue>

using std::vector;
using std::queue;

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (!root) return vector<int>();
		vector<int> result;
		queue<TreeNode*> level;
		level.push(root);
		while (!level.empty()) {
			auto tmp = level.front();
			level.pop();
			result.push_back(tmp->val);
			if (tmp->left) level.push(tmp->left);
			if (tmp->right) level.push(tmp->right);
		}
		return result;
	}
};

int main(){
	
}	