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
#include <queue>
#include <vector>

struct Node
{
	int p; //profit
	int c; //cost
	Node(int profit, int cost) :p(profit), c(cost) {}
};

auto cmp1 = [](Node& lhs, Node& rhs) { return lhs.c > rhs.c; };
using MinHeap = std::priority_queue < Node, std::vector<Node>,
	 decltype(cmp1)> ;

auto cmp2 = [](Node& lhs, Node& rhs) { return lhs.p < rhs.p; };
using MaxHeap = std::priority_queue < Node, std::vector<Node>,
	decltype(cmp2)>;

int findMaxCapital(int k, int w, const std::vector<int>& p, const std::vector<int>& c) {
	MinHeap minCost(cmp1);
	MaxHeap maxProfit(cmp2);
	for (int i = 0; i < p.size(); ++i) {
		minCost.push(Node(p[i], c[i]));
	}

	for (int i = 0; i < k; ++i) {
		while (!minCost.empty() && minCost.top().c <= w) {
			maxProfit.push(minCost.top());
			minCost.pop();
		}
		if (maxProfit.empty())
			return w;
		w += maxProfit.top().p;
		maxProfit.pop();
	}
	return w;
}

int main(){
	
}	