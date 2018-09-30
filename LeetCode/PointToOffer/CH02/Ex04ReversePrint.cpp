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
#include <stack>

using std::stack;
using std::vector;

 struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL) {
       }
 };

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		if (!head) return vector<int>();
		vector<int> ivec;
		stack<ListNode*> stk;
		while (head) {
			stk.push(head);
			head = head->next;
		}
		while (!stk.empty()) {
			ivec.push_back(stk.top()->val);
			stk.pop();
		}
		return ivec;
	}
};

int main(){
	
}	