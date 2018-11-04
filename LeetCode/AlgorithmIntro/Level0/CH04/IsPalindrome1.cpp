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

struct Node {
	int value;
	Node* next;
	Node(int v) :value(v), next(nullptr) {}
};

//need O(n/2) extra space
bool isPalindrome1(Node* head) {
	if (!head || !head->next) return true;
	
	auto fast = head;
	auto slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	if (fast&&fast->next)
		slow = slow->next;
	//可以通过fast空或者fast->next空来判断

	//注意这个写法可以跳过结点个数奇偶的判断
	/*
	auto fast = head;
	auto slow = head->next;
	while (fast->next&&fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}*/


	std::stack<Node*> stk;
	while (slow) {
		stk.push(slow);
		slow = slow->next;
	}

	while (!stk.empty()) {
		if (head->value != stk.top()->value) {
			return false;
		}
		stk.pop();
		head = head->next;
	}
	return true;
}

void destroy(Node*& head) {
	while (head) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
}

//need O(1) extra space
bool isPalindrome12(Node* head) {
	if (!head || !head->next) return true;

	auto fast = head;
	auto slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	//if (fast&&fast->next)
		//slow = slow->next;
	//注意此次不用跳过  链表长度为奇数时的中间结点

	//可以通过fast空或者fast->next空来判断

	//注意这个写法可以跳过结点个数奇偶的判断
	/*
	auto fast = head;
	auto slow = head->next;
	while (fast->next&&fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}*/

	fast = nullptr;// right part first node
	Node* pre = nullptr;
	//reverse right part list
	while (slow) {
		fast = slow->next;
		slow->next = pre;
		pre = slow;
		slow = fast;		
	}//end loop , pre: the fisrt node of right part
	auto rFirst = pre;
	bool res = true;
	while (head&&pre)
	{
		if (head->value != pre->value) {
			res = false; break;
		}
			
		head = head->next;
		pre = pre->next;
	}
	//recover list
	pre = nullptr;
	while (rFirst) {
		fast = rFirst->next;
		rFirst->next = pre;
		pre = rFirst;
		rFirst = fast;
	}
	return res;
}

int main(){
	auto head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(2);
	head->next->next->next = new Node(1);
	//head->next->next->next->next = new Node(1);

	std::cout << isPalindrome12(head);

	destroy(head);
}	