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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//体会这两种递归的差别
	//注意添加nullptr可以减少边界处理，巧
	//第一种没有充分发挥递归的作用，分的过于详细，其实都可以放进递归里边
	/*
	vector<TreeNode*> process(int start, int end) {
		//base case
		if (start >= end) return {};
		if (end - start == 1) {
			auto head1 = new TreeNode(end);
			head1->left = new TreeNode(start);

			auto head2 = new TreeNode(start);
			head2->right = new TreeNode(end);

			return vector<TreeNode*>{head1, head2};
		}

		auto Node = process(start + 1, end);
		vector<TreeNode*> head(Node.size(), new TreeNode(start));
		for (int i = 0; i < Node.size(); ++i)
			head[i]->right = Node[i];

		return head;
	}
	//毫无疑问，超时。
	vector<TreeNode*> generateTrees(int n) {
		if (n <= 0)return{};
		vector<TreeNode*> res;
		for (int i = 1; i <= n; ++i) {
			auto NodeLeft = process(1, i - 1);
			auto NodeRight = process(i + 1, n);
			//在组合。。
			for (int k = 0; NodeLeft.empty() || k < NodeLeft.size(); ) {
				bool signal = false;
				for (int j = 0; NodeRight.empty() || j < NodeRight.size(); ) {
					auto head = new TreeNode(i);
					head->left = NodeLeft.empty()? nullptr : NodeLeft[k++];
					head->right = NodeRight.empty() ? nullptr : NodeRight[j++];
					res.push_back(head);
					if ((NodeLeft.empty() && NodeRight.empty())
						|| (NodeLeft.empty() && j == NodeRight.size())
						|| (NodeRight.empty() && k == NodeLeft.size())) {
						signal = true;
						break;
					}
						
				}
				if (signal)
					break;
			}
		}
		return res;
	}*/
	//最好使用unique_ptr
	/*
	vector<TreeNode*> GenerateTrees(int start, int end) {
		vector<TreeNode*> res;
		if (start > end) res.push_back(nullptr);
		if (start == end) res.push_back(new TreeNode(start));
		if (end > start) {
			for (int i = start; i <= end; ++i) {
				auto left = GenerateTrees(start, i - 1);
				auto right = GenerateTrees(i + 1, end);

				for (int j = 0; j < left.size(); ++j) {
					for (int k = 0; k < right.size(); ++k) {
						auto head = new TreeNode(i);
						head->left = left[j];
						head->right = right[k];
						res.push_back(head);
					}
				}
			}
		}
		return res;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n < 1) return{};

		return GenerateTrees(1, n);
	}*/
};

int main(){
	Solution s;
	s.generateTrees(3);
}	