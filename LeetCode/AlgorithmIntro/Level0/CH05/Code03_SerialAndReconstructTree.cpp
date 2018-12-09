/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//实现树的前序序列化和反序列化
//拓展  中，后，层次？
//只实现了递归方式的前，中，后序列化
//中 后  的反序列化？？  
#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct TreeNode;

using Ptr = std::shared_ptr<TreeNode>;

struct TreeNode {
	int value;
	std::shared_ptr<TreeNode> left;
	std::shared_ptr<TreeNode> right;
	TreeNode(int v) :value(v), left(nullptr), right(nullptr) {}
};

std::string  serialTreeByPre(Ptr head) {
	if (!head) return "#_";  //_ is separator

	std::string res = std::to_string(head->value) + "_";
	res += serialTreeByPre(head->left);
	res += serialTreeByPre(head->right);
	return res;
}

std::string  serialTreeByInOrder(Ptr head) {
	if (!head) return "#_";  //_ is separator

	std::string res;
	res += serialTreeByInOrder(head->left);
	res += std::to_string(head->value) + "_";
	res += serialTreeByInOrder(head->right);
	return res;
}

std::string  serialTreeByPost(Ptr head) {
	if (!head) return "#_";  //_ is separator

	std::string res;
	res += serialTreeByInOrder(head->left);
	res += serialTreeByInOrder(head->right);
	res += std::to_string(head->value) + "_";
	return res;
}

//其实利用istringstream更好 利用空格来区分
std::vector<std::string> splitByPara(std::string preStr, const std::string& para = "_") {
	if (preStr.empty()) return {};
	std::vector<std::string> data;
	for (int pos = preStr.find_first_of(para); pos != std::string::npos; pos = preStr.find_first_of(para)) {
		data.push_back(preStr.substr(0, pos));
		preStr = preStr.substr(pos + 1);
	}
	return data;
}

std::shared_ptr<TreeNode> reconByPreOrder(std::queue<std::string>& que) {
	auto data = que.front();
	que.pop();
	if (data == "#")
		return nullptr;
	std::shared_ptr<TreeNode> head(new TreeNode(std::stoi(data)));
	head->left = reconByPreOrder(que);
	head->right = reconByPreOrder(que);

	return head;
}

std::shared_ptr<TreeNode> reconByPreString(std::string& preStr) {
	std::vector<std::string> values = splitByPara(preStr);
	std::queue<std::string> que;
	for (int i = 0; i < values.size(); ++i)
		que.push(values[i]);
	return reconByPreOrder(que);
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

	/*
	auto PreStr = serialTreeByPre(head);
	std::cout << PreStr << std::endl;

	auto reCon = reconByPreString(PreStr);

	for (auto &e : serialTreeByPre(reCon))
		std::cout << e ;*/

	auto PreStr = serialTreeByInOrder(head);
	std::cout << PreStr << std::endl;
}	