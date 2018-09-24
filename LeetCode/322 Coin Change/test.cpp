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
	}
};
int main(){
	vector<int> coins{ 474,83,404,3 };
	Solution s;
	std::cout << s.coinChange(coins, 6);
}	