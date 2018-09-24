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
You are given coins of different denominations and a total amount of 
money amount. Write a function to compute the fewest number of coins 
that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		if (coins.empty()) return -1;
		vector<int> result(amount + 1, -1);
		result[0] = 1;
		for (auto money = 1; money <= amount; ++money) {
			if (std::find(coins.begin(), coins.end(), money) != coins.end()) result[money] = 1;
			else {
				auto min = INT_MAX;
				for (auto&e : coins) {
					if (money - e >= 0 && result[money - e] != -1 && result[money - e] + 1 < min) min = result[money - e] + 1, result[money] = min;;
				}
			}
		}
		return result.back();
	}*/
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i < amount + 1; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i >= coins[j]) {
					dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
				}
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};