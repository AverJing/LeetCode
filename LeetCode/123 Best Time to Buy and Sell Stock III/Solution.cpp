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
Say you have an array for which the ith element is the price of a 
given stock on day i.

Design an algorithm to find the maximum profit. You may complete 
at most two transactions.

Note: You may not engage in multiple transactions at the same time 
(i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), 
			profit = 3-0 = 3.
			 Then buy on day 7 (price = 1) and sell on day 8 (price = 4),
			 profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), 
profit = 5-1 = 4.
			 Note that you cannot buy on day 1, buy on day 2 and sell 
			 them later, as you are
			 engaging multiple transactions at the same time. You must 
			 sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	//error
	/*
	int maxProfit(const vector<int>& prices) {
		if (prices.empty()) return 0;

		vector<int> dp(prices.size(), 0);
		vector<int> index(prices.size(), prices.size()-1);
		//dp[i]表示i位置最好收益
		//index[i]取得最好收益的右边位置
		//但是dp计算的有问题
		int res = 0;
		int count = 0;
		int tmpMin = INT_MAX;
		for (int i = prices.size() - 2; i >= 0; --i) {
			auto tmp = prices[i + 1] + dp[i + 1] - prices[i];
			dp[i] = tmp > 0 && dp[i+1]<tmp ? tmp : 0;
			index[i] = tmp > 0 && dp[i + 1] < tmp ? index[i+1] : i;
			if (tmp > 0 && dp[i + 1] < tmp) {
				if (count < 2) {
					if ( i < prices.size() - 2 && index[i] == index[i + 1] && index[i + 1] == index[i + 2]) {
						res += tmp - dp[i + 1];
						//i == prices.size() - 2 ? ++count : 0;
					}
					else {
						res += tmp;
						++count;
						tmpMin = std::min(tmpMin, tmp);
					}
				}
				else {
					if (res - tmpMin + tmp > res) {
						tmpMin = std::min(tmpMin, tmp);
					}
					res = std::max(res, res - tmpMin + tmp);
				}
			}
		}
		auto tmp1 = dp;
		auto tmp2 = index;
		return res;
	}*/

	//我考虑的问题方向错了
	//本体可以看成最大m字段和，m=2的情况
	int maxProfit(const vector<int>& prices) {
		if (prices.size() < 2) return 0;

		const int n = prices.size();
		vector<int> f(n, 0);
		vector<int> g(n, 0);

		for (int i = 1, valley = prices[0]; i < n; ++i) {
			valley = std::min(valley, prices[i]);
			f[i] = std::max(f[i - 1], prices[i] - valley);
		}
		for (int i = n-2, peak = prices[n-1]; i >= 0; --i) {
			peak = std::max(peak, prices[i]);
			g[i] = std::max(g[i - 1], peak - prices[i]);
		}

		int max_profit = 0;
		for (int i = 0; i < n; ++i)
			max_profit = std::max(max_profit, f[i] + g[i]);

		return max_profit;
	}
};

int main(){
	Solution s;
	std::cout << s.maxProfit({ 1,2,4,2,5,7,2,4,9,0,9 });
}	