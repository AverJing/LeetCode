/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
Say you have an array for which the ith element is the price of 
a given stock on day i.

If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
			 Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#pragma once

#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
	//bad answer
	/* 
	int maxProfit(vector<int>& prices) {
		int max = 0;
		for (auto i = 0; i < prices.size(); ++i) {
			for(auto j = i + 1; i < prices.size(); ++j) {
				if (prices[j] > prices[i]) {
					max = max < prices[j] - prices[i] ? prices[j] - prices[i] : max;
				}
			}
		}
		return max;
	}
	*/
	/*
	int maxProfit(vector<int>& prices) {
		int max = 0;
		if (prices.size() < 2) return 0;
		stack<int> s; s.push(prices[0]);
		for (auto i = 1; i < prices.size(); ++i) {
			if (prices[i - 1] > prices[i]) {
				if (s.top() > prices[i]) {
					s.pop();
					s.push(prices[i]);
				}
			}
			auto top = s.top();
			max = max < prices[i] - top ? prices[i] - top : max;
		}
		return max;
	}
	*/
	//optimization
	int maxProfit(vector<int>& prices) {
		int max = 0;
		if (prices.size() < 2) return 0;
		int min = prices[0];
		for (auto i = 1; i < prices.size(); ++i) {
			if (prices[i - 1] > prices[i]) {
				if (min > prices[i]) {
					min = prices[i];
				}
			}
			max = max < prices[i] - min ? prices[i] - min : max;
		}
		return max;
	}
};
