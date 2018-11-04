/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//将单向链表按某种划分成左边小，中间相等，右边大的形式
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
	int value;
	Node* next;
	Node(int v) :value(v), next(nullptr) {}
};

//方法1，使用荷兰国旗问题解决
Node* listPartition(Node* head, int pivot) {
	if (!head || !head->next) return head;

	std::vector<int> data;
	auto curr = head;
	while (curr) {
		data.push_back(curr->value);
		curr = curr->next;
	}

	int less = -1, more = data.size();

	for (int i = 0; i < more; ) {
		if (data[i] < pivot) {
			std::swap(data[++less], data[i++]);
		}
		else if (data[i] > pivot) {
			std::swap(data[--more], data[i]);
		}
		else {
			++i;
		}
	}
	curr = head;
	for (auto e : data) {
		curr->value = e;
		curr = curr->next;
	}

	return head;
}

//为了保持源序列相对顺序不变，把源链表拆分为3个链表
Node* listPartition2(Node*& head, int pivot) {
	if (!head || !head->next) return head;

	Node* lH = nullptr;  //less head
	Node* lT = nullptr;  //less tail
	Node* eH = nullptr;	 //equal
	Node* eT = nullptr;
	Node* mH = nullptr;	 //more
	Node* mT = nullptr;
	Node* next = nullptr;

	while (head) {
		next = head->next;
		head->next = nullptr;
		if (head->value < pivot) {
			if (!lH) {
				lH = head;
				lT = head;
			}
			else {
				lT->next = head;
				lT = head;
			}
		}else if (head->value > pivot) {
			if (!mH) {
				mH = head;
				mT = head;
			}
			else {
				mT->next = head;
				mT = head;
			}
		}
		else {
			if (!eH) {
				eH = head;
				eT = head;
			}
			else {
				eT->next = head;
				eT = head;
			}
		}
		head = next;
	}

	//link list
	if (lT) {
		lT->next = eH;
		eT = eT == nullptr ? lT : eT;
	}
	if (eT) {
		eT->next = mH;
	}
	return lH ? lH : (eH ? eH : mH);
}

void PrintNode(Node* head) {
	if (!head) return;

	while (head) {
		std::cout << head->value << ' ';
		head = head->next;
	}
}


void destroy(Node*& head) {
	if (!head) return;

	while (head) {
		auto tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main(){
	auto head1 = new Node(2);
	head1->next = new Node(3);
	head1->next->next = new Node(1);
	head1->next->next->next = new Node(2);
	head1->next->next->next->next = new Node(5);

	//auto head = listPartition(head1, 2);
	auto head = listPartition2(head1, 2);

	PrintNode(head);

	destroy(head);
}	