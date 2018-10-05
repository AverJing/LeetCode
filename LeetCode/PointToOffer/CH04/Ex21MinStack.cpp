/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/

//LeetCode 155 min stack
#include <iostream>
#include <stack>

using std::stack;

class Solution {
public:
	void push(int value) {
		if (minStk.empty() || minStk.top() > value)
			minStk.push(value);
		result.push(value);
	}
	void pop() {
		if (result.top() == minStk.top())
			minStk.pop();
		result.pop();
	}
	int top() {
		return result.top();
	}
	int min() {
		return minStk.top();
	}
private:
	stack<int> result;
	stack<int> minStk;
};

int main(){
	
}	