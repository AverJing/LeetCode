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
#include <memory>
#include <stack>
#include <queue>
#include <algorithm>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

struct ReturnType {
	int size;
	Ptr head;
	int Min;
	int Max;
	ReturnType(int a=0, Ptr h=nullptr, int b=INT_MAX, int c=INT_MIN) 
		:size(a), head(h), Min(b), Max(c) {}
};

/*
边界情况返回值
左边返回值
右边返回值
分析情况（如何根据上边左右返回值得到当前节点的返回值）
*/
ReturnType getMaxSubBSTInTree(Ptr head) {
	if (!head) {
		return ReturnType();
	}

	auto left = getMaxSubBSTInTree(head->left);
	auto right = getMaxSubBSTInTree(head->right);

	int includeItSelf = 0;
	if (head->left == left.head && head->right == right.head
		&& head->value < right.Min && left.Max < head->value) {
		includeItSelf = left.size + 1 + right.size;
	}

	int maxSize = std::max({ includeItSelf, left.size,right.size });
	auto maxHead = maxSize == includeItSelf ? head : (maxSize == left.size ? left.head : right.head);

	return ReturnType(maxSize, maxHead, std::min({ head->value,left.Min,right.Min }), std::max({ head->value,left.Max,right.Max }));
}

void PreTraverse(Ptr head) {
	if (!head)return;

	std::cout << head->value << ' ';
	PreTraverse(head->left);
	PreTraverse(head->right);
}

int main(){

	typename Ptr head(new TreeNode(6));  //不加typename，编译器会推断为函数声明
	head->left = std::make_shared<TreeNode>(TreeNode(1));
	head->left->left = std::make_shared<TreeNode>(TreeNode(0));
	head->left->right = std::make_shared<TreeNode>(TreeNode(3));
	head->right = std::make_shared<TreeNode>(TreeNode(12));
	head->right->left = std::make_shared<TreeNode>(TreeNode(10));
	head->right->left->left = std::make_shared<TreeNode>(TreeNode(4));
	head->right->left->left->left = std::make_shared<TreeNode>(TreeNode(2));
	head->right->left->left->right = std::make_shared<TreeNode>(TreeNode(5));
	head->right->left->right = std::make_shared<TreeNode>(TreeNode(14));
	head->right->left->right->left = std::make_shared<TreeNode>(TreeNode(11));
	head->right->left->right->right = std::make_shared<TreeNode>(TreeNode(15));
	head->right->right = std::make_shared<TreeNode>(TreeNode(13));
	head->right->right->left = std::make_shared<TreeNode>(TreeNode(20));
	head->right->right->right = std::make_shared<TreeNode>(TreeNode(16));

	PreTraverse(getMaxSubBSTInTree(head).head);
}	