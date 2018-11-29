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
#include <unordered_map>
#include <algorithm>

using Arr = std::vector<int>;
using HashMap = std::unordered_map<int, int>;

int getMostXOR(const Arr& data) {
	if (data.empty()) return 0;

	int ans = 0;
	int _xor = 0;
	Arr dp(data.size(), -1);
	HashMap map;
	map.insert({ 0, -1 });
	for (int i = 0; i < data.size(); ++i) {
		_xor ^= data[i];
		if (map.find(_xor) != map.end()) {
			int pre = map[_xor];
			dp[i] = pre == -1 ? 1 : (dp[pre] + 1);
		}
		if (i > 0) {
			dp[i] = std::max(dp[i - 1], dp[i]);
		}
		map.insert_or_assign(_xor, i);
		ans = std::max(ans, dp[i]);
	}
	return ans;
}


int main(){
	Arr data{ 3,2,0,2,0,5,3};
	std::cout << getMostXOR(data);
}	