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
Given a string s, partition s such that every substring of
the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include <iostream>
#include <string>
#include <vector>
#include "../AlgorithmIntro/Level0/CH01/TestCase.h"

using std::string;
using std::vector;

class Solution {
public:
	bool isPalindrome(const string& s, int i, int j) {
		for (; i < j; ++i, --j) {
			if (s[i] != s[j])
				return false;
		}return true;
	}

	vector<vector<string>> partition(string& s) {
		if (s.empty()) return {};
		vector<vector<string>> res;
		vector<string> path;
		dfs(s, res, path, 0, 1);
		return res;
	}

	void dfs(const string& s, vector<vector<string>>& result, vector<string>& path, size_t prev, size_t start) {
		if (start == s.size()) {//到达字符串末尾
			if (isPalindrome(s, prev, start-1)) {
				path.push_back(s.substr(prev, start - prev));
				result.push_back(path);
				path.pop_back();
			}
			return;
		}

		//不断开，继续搜索
		dfs(s, result, path, prev, start + 1);
		if (isPalindrome(s, prev, start-1)) {//duankai
			path.push_back(s.substr(prev, start - prev));
			dfs(s, result, path, start, start + 1);
			path.pop_back();
		}
	}
};

int main(){
	Solution s;
	for (int i = 0; i < 20; ++i) {
		testCaseString t(15);
		t.Print();
		std::cout << "start ";
		std::cout << std::endl;
		s.partition(t.getString());
		for (auto &e : s.partition(t.getString())) {
			for (auto &t : e) {
				std::cout << t << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << "end" << std::endl;
	}
}	