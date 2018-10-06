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

using std::vector;


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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (!root) return vector<vector<int>>();
		vector<int> path;
		int currentSum = 0;
		FindPath(root, expectNumber, path, currentSum);
		return result;
	}
private:
	void FindPath(TreeNode* root, int expectNum, vector<int>& path, int& current) {
		current += root->val;
		path.push_back(root->val);

		bool isLeaf = !root->left && !root->right;
		if (current == expectNum && isLeaf) {
			result.push_back(path);
		}

		if (root->left)
			FindPath(root->left, expectNum, path, current);
		if(root->right)
			FindPath(root->right, expectNum, path, current);

		current -= root->val;
		path.pop_back();
	}
	vector<vector<int>> result;
};

int main(){
	
}	