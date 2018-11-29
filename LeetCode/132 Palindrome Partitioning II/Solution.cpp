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
Given a string s, partition s such that every substring of the 
partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced 
using 1 cut.
*/

#include <iostream>
#include <string>

using std::string;

#include <iostream>
#include <string>
#include <vector>
#include "../AlgorithmIntro/Level0/CH01/TestCase.h"

using std::string;
using std::vector;

//可以解决但是会超时
class Solution_0 {
public:
	bool isPalindrome(const string& s, int i, int j) {
		for (; i < j; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}return true;
	}

	int minCut(string& s) {
		if (s.empty()) return {};
		vector<vector<string>> res;
		vector<string> path;
		dfs(s, res, path, 0, 1);
		return res[0].size()-1;
	}

	void dfs(const string& s, vector<vector<string>>& result, vector<string>& path, size_t prev, size_t start) {
		if (start == s.size()) {//到达字符串末尾
			if (isPalindrome(s, prev, start - 1)) {
				path.push_back(s.substr(prev, start - prev));
				if (result.empty()) {
					result.push_back(path);
				}
				else {
					if (result[0].size() > path.size()) result[0] = path;
				}
				path.pop_back();
			}
			return;
		}

		//不断开，继续搜索
		dfs(s, result, path, prev, start + 1);
		if (isPalindrome(s, prev, start - 1)) {//duankai
			path.push_back(s.substr(prev, start - prev));
			dfs(s, result, path, start, start + 1);
			path.pop_back();
		}
	}
};
/*
class Solution {
public:
	bool isPalindrome(const string& s, int i, int j) {
		for (; i < j; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}return true;
	}

	int minCut(const string& s) {
		if (s.empty()) return {};
		vector<vector<bool>> res(s.size(), vector<bool>(s.size(), false));
		
		//for (int i = 0; i < s.size(); ++i) {//lie
		//	for (int j = i; j < s.size(); ++j) {//hang
		//		res[j][i] = isPalindrome(s, i, j);		
		//	}
		//}
		for (int i = s.size() -1; i >= 0; --i) {
			for (int j = i; j < s.size(); ++j) {
				//加速dp求解
				//res[i][j]表示从i到j是不是回文
				res[i][j] = s[i] == s[j] && ((j - i) < 2 || res[i + 1][j - 1]);
			}
		}
		const int n = s.size();
		vector<vector<string> > sub_palins[n]; // sub palindromes of s[0,i]
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j)
				if (res[i][j]) {
					const string palindrome = s.substr(i, j - i + 1);
					if (j + 1 < n) {
						for (auto v : sub_palins[j + 1]) {
							v.insert(v.begin(), palindrome);
							sub_palins[i].push_back(v);
						}
					}
					else {
						sub_palins[i].push_back(vector<string> { palindrome });
					}
				}
		}
		return sub_palins[0];

	}
};*/

class Solution {
public:
	int minCut(const string& s) {
		if (s.empty()) return {};
		vector<vector<bool>> res(s.size(), vector<bool>(s.size(), false));
		vector<int> dp(s.size()+1, INT_MAX);
		dp[s.size()] = -1;
		for (int i = s.size() - 1; i >= 0; --i) {
			for (int j = i; j < s.size(); ++j) {
				//加速dp求解
				//res[i][j]表示从i到j是不是回文
				if (s[i] == s[j] && ((j - i) < 2 || res[i + 1][j - 1])) {
					res[i][j] = true;
					dp[i] = std::min(dp[i], dp[j + 1] + 1);
				}	
			}
		}
		return dp[0];
	}
};

int main() {
	Solution s;
	s.minCut("abbab");
}