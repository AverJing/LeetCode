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
#include <string>
#include <vector>
#include <queue>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;
using Arr = std::vector<int>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

std::string serialTree(Ptr head) {
	if (!head) return "#_";

	std::string res;
	res += std::to_string(head->value)+"_";
	res += serialTree(head->left);
	res += serialTree(head->right);
	return res;
}

Arr getNext(const std::string& s) {
	if (s.size() == 1) return { -1 };

	Arr next(s.size(), -1); //s.size() >= 2
	next[1] = 0;

	int cur = 0;
	for (int i = 2; i < s.size();) {
		if (s[i - 1] == s[cur]) {
			next[i++] = ++cur;
		}
		else if (cur > 0) {
			cur = next[cur];
		}
		else {
			next[i++] = 0;
		}
	}
}

int IsMatch(const std::string& s1, const std::string& s2) {
	if (s1.size() < 1 || s2.size() < 1 || s1.size() < s2.size()) return -1;

	auto next = getNext(s1);
	int i = 0, j = 0;
	for (; i < s1.size() && j < s2.size();) {
		if (s1[i] == s2[j]) {
			++i;
			++j;
		}
		else if (next[j] != -1) {
			j = next[j];
		}
		else {
			++i;
		}
	}

	return j == s2.size() ? i - j : -1;
}

int main(){
	typename Ptr head(new TreeNode(5));  //不加typename，编译器会推断为函数声明
	head->left = std::make_shared<TreeNode>(TreeNode(3));
	head->right = std::make_shared<TreeNode>(TreeNode(8));
	head->left->left = std::make_shared<TreeNode>(TreeNode(2));
	head->left->right = std::make_shared<TreeNode>(TreeNode(4));
	head->left->left->left = std::make_shared<TreeNode>(TreeNode(3));
	head->right->left = std::make_shared<TreeNode>(TreeNode(7));
	head->right->left->left = std::make_shared<TreeNode>(TreeNode(6));
	head->right->right = std::make_shared<TreeNode>(TreeNode(10));
	head->right->right->left = std::make_shared<TreeNode>(TreeNode(9));
	head->right->right->right = std::make_shared<TreeNode>(TreeNode(11));


	std::cout << serialTree(head);
}	