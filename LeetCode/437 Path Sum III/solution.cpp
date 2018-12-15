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
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, 
but it must go downwards (traveling only from parent nodes to child 
nodes).

The tree has no more than 1,000 nodes and the values are in the range 
-1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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
	//尝试优化，可以去掉num，用sum来判断。
	void process(TreeNode* root, int sum, int& res, int num, bool sym) {
		if (num == sum)
			++res;
		if (!root) return; //注意两者的先后顺序
		if (!sym) {
			process(root->left, sum, res, num, false);
			process(root->right, sum, res, num, false);
		}
		process(root->left, sum, res, num + root->val, true);
		process(root->right, sum, res, num + root->val, true);
	}
	int pathSum(TreeNode* root, int sum) {
		int res = 0;
		process(root, sum, res, 0, false);
		return res/2;
	}
	//思路本质上是一样的。
	//比我的好很多。
	//可是为什么提交结果差不少呢？
	//参数变量？
	/*
	public:
    int pathSum(TreeNode* root, int sum) {
        std::array<int, 3> count = {0};
        if (root) {
            pathSum(root, sum, count[0]);
            count[1] = pathSum(root->left, sum);
            count[2] = pathSum(root->right, sum);
        }
        return std::accumulate(count.begin(), count.end(), 0);
    }

private:
    void pathSum(TreeNode *root, int sum, int &count) {
        sum -= root->val;
        if (0 == sum) ++count;
        if (root->left) pathSum(root->left, sum, count);
        if (root->right) pathSum(root->right, sum, count);
    }
	*/
};

int main(){
	TreeNode * head = new TreeNode(10);
	head->left = new TreeNode(5);
	head->right = new TreeNode(-3);
	head->left->left = new TreeNode(3);
	head->left->right = new TreeNode(2);
	head->left->left->left = new TreeNode(3);
	head->left->left->right = new TreeNode(-2);
	head->left->right->right = new TreeNode(1);
	head->right->right = new TreeNode(-11);

	Solution s;
	std::cout <<  s.pathSum(head, 8);
}	