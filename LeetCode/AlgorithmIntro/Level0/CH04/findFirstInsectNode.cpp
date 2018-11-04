/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//难题，找两个单链表第一个相交的结点
//注意  是单链表，还要考虑有无环
//两个无环   一个有环一个无环   两个有环
#include <iostream>

struct Node {
	int value;
	Node* next;
	Node(int v) :value(v), next(nullptr) {}
};

Node* getLoopNode(Node* head) {
	if (!head || !head->next || !head->next->next) return nullptr;

	Node* slow = head->next;
	Node* fast = head->next->next;

	while (slow != fast) {
		if (!fast->next || !fast->next->next)
			return nullptr;
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = head;
	while (slow != fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

Node* noLoop(Node* head1, Node* head2) {
	if (!head1 || !head2) {
		return nullptr;
	}

	Node * curr1 = head1;
	Node* curr2 = head2;
	int n = 0;  //注意此处只用了一个计数变量
	while (curr1->next) {
		++n;
		curr1 = curr1->next;
	}
	while (curr2->next) {
		--n;
		curr2 = curr2->next;
	}
	if (curr1 != curr2) { //如果到最后一个结点不相等，肯定不相交
		return nullptr;
	}

	curr1 = n > 0 ? head1 : head2;
	curr2 = curr1 == head1 ? head2 : head1;
	n = std::abs(n);

	while (n != 0) {
		--n;
		curr1 = curr1->next;
	}
	while (curr1 != curr2) {
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	return curr1;
}

Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2) {
	Node* curr1 = nullptr;
	Node* curr2 = nullptr;
	if (loop1 == loop2) {   
		Node * curr1 = head1;
		Node* curr2 = head2;
		int n = 0;  //注意此处只用了一个计数变量
		while (curr1 != loop1) {
			++n;
			curr1 = curr1->next;
		}
		while (curr2 != loop2) {
			--n;
			curr2 = curr2->next;
		}

		curr1 = n > 0 ? head1 : head2;
		curr2 = curr1 == head1 ? head2 : head1;
		n = std::abs(n);

		while (n != 0) {
			--n;
			curr1 = curr1->next;
		}
		while (curr1 != curr2) {
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		return curr1;
	}
	else {
		curr1 = loop1->next;
		while (curr1 != loop1) {
			if (curr1 == loop2)
				return loop1;
			curr1 = curr1->next;
		}
		return nullptr;
	}
}


Node* findFisrtInsect(Node* head1, Node* head2) {
	if (!head1 || !head2) return nullptr;

	auto loop1 = getLoopNode(head1);
	auto loop2 = getLoopNode(head2);

	if (!loop1 && !loop2) {
		return noLoop(head1, head2);
	}
	if(loop1 && loop2){
		return bothLoop(head1, loop1, head2, loop2);
	}
	return nullptr;
}

int main(){
	auto head2 = new Node(0);
	head2->next = new Node(9);
	head2->next->next = new Node(8);
	head2->next->next->next = new Node(7);
	head2->next->next->next->next = head2->next->next;

	auto head1 = new Node(1);
	head1->next = new Node(3);
	head1->next->next = new Node(2);
	head1->next->next->next = head2->next;

	std::cout << findFisrtInsect(head1, head2)->value;
}	