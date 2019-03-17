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
#include <array>

bool process(std::vector<int>& arr, int i, int sum, int aim) {
	if (sum == aim) return true;
	//剪枝  注意此处意味着  arr都是正整数，或者是排序的
	if (sum > aim || i == arr.size()) return false;

	return process(arr, i + 1, sum, aim) || process(arr, i + 1, sum + arr[i], aim);
}

bool getNumber(std::vector<int>& arr, int aim) {
	if (arr.empty()) return false;

	process(arr, 0, 0, aim);
}

//结合递归分析
bool getNumber2(std::vector<int>& arr, int aim) {
	std::vector<std::vector<bool>> dp(arr.size() + 1, std::vector<bool>(aim + 1, false));
	
	for (int i = 0; i < arr.size(); ++i)
		dp[i][aim] = true;

	for (int i = arr.size() - 1; i >= 0; --i) {
		for (int j = aim - 1; j >= 0; --j) {
			dp[i][j] = dp[i + 1][j];
			if (j + arr[i] <= aim) {
				dp[i][j] = dp[i][j] || dp[i + 1][arr[i] + j];
			}
		}
	}
	return dp[0][0];
}

int main(){
	std::vector<int> arr{ 1,2,4,5,3,7,2,2,3 };

	std::cout << getNumber2(arr, 10);

}	