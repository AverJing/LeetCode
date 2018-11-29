/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//518. Coin Change 2

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using Arr = std::vector<int>;
using Cache = std::unordered_map<string, int>;

int process(const Arr& money, int index, int aim) {
	int res = 0;
	if (index == money.size())
		res = aim == 0 ? 1 : 0;
	else {
		for (int i = 0; money[index] * i <= aim; ++i)
			res += process(money, index + 1, aim - (money[index] * i));
	}
	return res;
}

int getCoins(const Arr& money, int aim) {
	if (money.empty())return 0;
	return process(money, 0, aim);
}

int process2(const Arr& money, int index, int aim, Cache& map) {
	int res = 0;
	if (index == money.size())
		res = aim == 0 ? 1 : 0;
	else {
		for (int i = 0; money[index] * i <= aim; ++i) {
			int nextAim = aim - (money[index] * i);		
			auto record = map.find(std::to_string(index + 1) + "_" + std::to_string(nextAim));
			if (record != map.end()) {
				res += record->second;
			}
			else {
				res += process2(money, index + 1, aim - (money[index] * i), map);
			}		
		}		
	}
	map.insert({ std::to_string(index) + "_" + std::to_string(aim), res });
	return res;
}

//考虑记录其中的数据，因为有非常多的重复计算
int getCoins2(const Arr& money, int aim) {
	if (money.empty())return 0;
	Cache ch;
	return process2(money, 0, aim, ch);
}

int getCoins3(const Arr& money, int aim) {
	if (money.empty())return 0;
	std::vector<std::vector<int>> dp(money.size()+1, std::vector<int>(aim + 1, 0));
	dp[money.size()][0] = 1;
	for (int i = money.size() - 1; i >= 0; --i) {
		for (int j = 0; j < aim + 1; ++j) {
			dp[i][j] = dp[i + 1][j] + (j - money[i] >= 0 ? dp[i][j - money[i]] : 0);
		}
	}
	return dp[0][aim];
}

//还可以压缩空间
int getCoins4(const Arr& money, int aim) {
	if (money.empty())return aim == 0 ? 1 : 0;
	Arr dp(aim + 1, 0);
	dp[0] = 1;
	for (int i = money.size() - 1; i >= 0; --i) {
		for (int j = 1; j < aim + 1; ++j) {
			dp[j] = dp[j] + (j - money[i] >= 0 ? dp[j - money[i]] : 0);
		}
	}
	return dp[aim];
}

int main(){
	std::cout << getCoins4({ 10,5,1,25 }, 2000);
}	