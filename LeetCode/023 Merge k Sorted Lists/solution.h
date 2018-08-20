/*
*
*
*@author: Aver Jing
*@description£º
*@date£º
*
*
*/
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

	Input:
	[
	  1->4->5,
	  1->3->4,
	  2->6
	]
	Output: 1->1->2->3->4->4->5->6
*/
#pragma once

#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		return mergeKLists(lists.cbegin(), lists.cend());
	}
private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode res(0);

		ListNode* temp = &res;

		while (l1 && l2) {
			if (l1->val > l2->val) {
				temp->next = l2;
				l2 = l2->next;
			}
			else {
				temp->next = l1;
				l1 = l1->next;
			}
			temp = temp->next;
		}

		temp->next = l1 ? l1 : l2;

		return res.next;
	}
	using vecNodeCIter = std::vector<ListNode *>::const_iterator;
	ListNode* mergeKLists(vecNodeCIter beg, vecNodeCIter end) {
		if (beg == end) return NULL;
		else if (std::distance(beg, end) == 1) return *beg;
		else if (std::distance(beg, end) == 2) return mergeTwoLists(*beg, *std::next(beg));
		else return mergeTwoLists(mergeKLists(beg, beg + std::distance(beg, end) / 2),
			mergeKLists(beg + std::distance(beg, end) / 2, end));
	}

	/* better answer
	use min heap to solve problem
	Notice: 1.how to delete element in min heap(line 88, pop_heap)
	2. the default compare(<) will construct max heap(seem to be a little bizarre)
	static bool heapComp(ListNode* a, ListNode* b) {
        return (a->val > b->val);
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
		ListNode head(0);
		ListNode *curNode = &head;
		vector<ListNode*> v;   
		for(int i =0; i<lists.size(); i++){
			if(lists[i]) v.push_back(lists[i]);
		}
		make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

		while(v.size()>0){
			curNode->next=v.front();
			pop_heap(v.begin(), v.end(), heapComp); 
			v.pop_back(); 
			curNode = curNode->next;
			if(curNode->next) {
				v.push_back(curNode->next); 
				push_heap(v.begin(), v.end(), heapComp);
			}
		}
		return head.next;
	}
	*/
};

