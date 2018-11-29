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

struct Node;

using Ptr = std::shared_ptr<Node>;

struct Node
{
	int value;
	Ptr left;
	Ptr right;
	Node(int v = 0, Ptr l = nullptr, Ptr r = nullptr) :value(v), left(l), right(r) {}
	~Node() { std::cout << "free memory" << std::endl;; }
};

int main(){
	Ptr head = std::make_shared<Node>(Node(10));
	head->left = std::make_shared<Node>(Node(11));
	head->right = std::make_shared<Node>(Node(12));


}	