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
#include <algorithm>

using std::vector;

class Solution {
public:
	/*
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return -1;
		vector<int> result(amount + 1, -1);
		result[0] = 0;
		for (auto money = 1; money <= amount; ++money) {
			if (std::find(coins.begin(), coins.end(), money) != coins.end()) result[money] = 1;
			else {
				auto min = INT_MAX;
				for (auto&e : coins) {
					if (money - e >= 0 && result[money - e] != -1 && result[money - e] + 1 < min) min = result[money - e] + 1, result[money] = min;
				}
			}
		}
		return result.back();
	}*/
	//不可以用贪心
	/*
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return -1;
		std::sort(coins.begin(), coins.end());

		int times = 0;
		for (int i = coins.size() - 1; i >= 0; --i) {
			int tmp = amount / coins[i];
			amount -= tmp * coins[i];
			times += tmp;
			if (amount == 0) break;
		}
		return amount == 0 ? times : -1;
	}
	*/


	//递归解法，接下来改写dp
	/*
	void process(const vector<int>& coins, int index, int amount, int times, vector<int>& result) {
		if (amount == 0) {
			result[0] == -1 ? result[0] = times : (times < result.back() ? result[0] = times : 0);
			return;
		}
		else if (index == coins.size()) {
			return;
		}
		else {
			for (int i = 0; coins[index] * i <= amount; ++i) {
				process(coins, index + 1, amount - coins[index] * i, times + i, result);
			}
		}
	}

	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty()) return -1;
		vector<int> result(1, -1);
		process(coins, 0, amount, 0, result);
		return result.back();
	}*/
	//空间优化后的
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
int main(){
	vector<int> coins{ 1,2,5,3 };
	Solution s;
	std::cout << s.coinChange(coins, 6);
}	