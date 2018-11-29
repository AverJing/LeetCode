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
#include <vector>
#include <algorithm>

struct TreeNode;
using Ptr = std::shared_ptr<TreeNode>;
using ReturnType = std::pair<int, int>; //first:coming value second:not coming value

struct TreeNode
{
	int val;
	std::vector<Ptr> next;
	TreeNode(int x) :val(x) {}
};

ReturnType process(Ptr head) {
	int cValue = head->val;  //itself coming
	int nValue = 0;	//do not come

	for (int i = 0; i < head->next.size(); ++i) {
		auto node = head->next[i];
		auto child = process(node);
		cValue += child.second;
		nValue += std::max(child.first, child.second);
	}
	return { cValue,nValue };
}

int getMax(Ptr head) {
	auto tmp = process(head);
	return std::max(tmp.first, tmp.second);
}

//better answer
//dp[i][0]表示的是i作为父节点，它不来的时候的最大活跃度； 
//dp[i][1]表示的是i作为父节点，它来的时候的最大活跃度；

void process(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>&dp, std::vector<bool> vis,  int root) {
	vis[root] = true;  //标记当前结点已经做过父 也就是它的dp两个值都算出来了
	dp[root][1] = matrix[root][1];
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][0] == root && !vis[i]) { //找到儿子
			process(matrix, dp, vis, i);
			dp[root][1] += dp[i][0]; //来的活跃度  加上儿子不来的活跃度
			dp[root][0] += std::max(dp[i][0], dp[i][1]); //不来的活跃度是儿子来或不来的最大值
		}
	}
}

int maxHappy(std::vector<std::vector<int>>& matrix) {
	std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(2));
	std::vector<bool> visited(matrix.size(), false);
	int root = 0;
	for (int i = 0; i < matrix.size(); ++i) {
		if (i == matrix[i][0])
			root = i;
	}
	process(matrix, dp, visited, root);
}
int main(){
	
}	