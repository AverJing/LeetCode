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
#include <string>
#include <vector>

using String = std::string;
using DP = std::vector<std::vector<int>>;

//时间复杂度O(N*M)  空间复杂度O(N*M)
//N=lhs.size(), M=rhs.size()
//可以把空间复杂度优化为O(1)
//注意到DP是由res[i - 1][j - 1]得到的
DP getDP(const String& lhs, const String& rhs) {
	DP res(lhs.size(), std::vector<int>(rhs.size(), 0));

	for (int i = 0; i < lhs.size(); ++i) {
		res[i][0] = lhs[i] == rhs[0] ? 1 : 0;
	}
	for (int i = 0; i < rhs.size(); ++i) {
		res[0][i] = rhs[i] == lhs[0] ? 1 : 0;
	}

	for (int i = 1; i < lhs.size(); ++i) {
		for (int j = 1; j < rhs.size(); ++j) {
			if (lhs[i] == rhs[j]) {
				res[i][j] = res[i - 1][j - 1] + 1;
			}
		}
	}
	return res;
}

String getLCS(const String& lhs, const String& rhs) {
	if (lhs.empty() || rhs.empty()) return "";

	int end = 0;
	int maxL = 0;

	auto dp = getDP(lhs, rhs);

	for (int i = 0; i < lhs.size();++i) {
		for (int j = 0; j < rhs.size(); ++j) {
			if (dp[i][j] > maxL) {
				maxL = dp[i][j];
				end = i;
			}
		}
	}
	return lhs.substr(end - maxL + 1, maxL);
}

String getLCS_2(const String& lhs, const String& rhs) {
	if (lhs.empty() || rhs.empty()) return "";

	int end = 0;
	int maxL = 0;

	int row = 0;//斜线开始的行
	int coln = rhs.size() - 1; //斜线开始的列

	while (row < lhs.size()) {
		int i = row;
		int j = coln;
		int len = 0;
		while (i < lhs.size() && j < lhs.size()) {
			if (lhs[i] != rhs[j])
				len = 0;
			else
				++len;
			if (len > maxL) {
				maxL = len;
				end = i;
			}
			++i;
			++j;
		}
		if (coln > 0) {
			--coln;
		}
		else {
			++row;
		}
	}

	return lhs.substr(end - maxL + 1, maxL);
}

int main(){
	std::cout << getLCS_2("abcd123", "dc12de");
}	