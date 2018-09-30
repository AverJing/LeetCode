/*
*
*
*@author: Aver Jing
*@description：用两个栈实现队列
*@date：
*
*
*/

#include <iostream>
#include <stack>
#include <cassert>

using std::stack;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		assert(!stack2.empty());

		int tmp = stack2.top();
		stack2.pop();
		return tmp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};


int main(){
	
}	