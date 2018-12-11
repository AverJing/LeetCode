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
#include <stack>
#include <vector>

using std::string;
using std::stack;
using std::vector;

class Solution {
public:
	string decodeString(string s) {
		int frequence = 0;
		stack<string> stk;
		stack<int> time;
		string result;
		for (auto it = s.begin(); it != s.end(); ) {
			if (*it <= '9'&&*it >= '0') {
				int num = 0;
				while (*it <= '9'&&*it >= '0') {
					num = num * 10 + (*it - '0');
					++it;
				}
				time.push(num);
			}
			else if (*it == '[') {
				stk.push(result);
				result = "";
				++it;
			}
			else if (*it == ']') {
				auto frequence = time.top();
				time.pop();
				auto tmp = stk.top();
				stk.pop();
				for (; frequence--;)
					tmp.append(result);
				result = tmp;
				++it;
			}
			else {
				result += *it;
				++it;
			}
		}
		return result;
	}
};

//s = "abcabccdcdcdef", return "2[abc]3[cd]ef".
//将上边过程反过来
//http://www.cnblogs.com/grandyang/p/6194403.html
class Solution2 {
public:
	string encode(string s) {
		int n = s.size();
		vector<vector<string>> dp(n, vector<string>(n, ""));
		for (int step = 1; step <= n; ++step) {
			for (int i = 0; i + step - 1 < n; ++i) {
				int j = i + step - 1;
				dp[i][j] = s.substr(i, step);
				for (int k = i; k < j; ++k) {
					string left = dp[i][k], right = dp[k + 1][j];
					if (left.size() + right.size() < dp[i][j].size()) {
						dp[i][j] = left + right;
					}
				}
				string t = s.substr(i, j - i + 1), replace = "";
				auto pos = (t + t).find(t, 1);
				if (pos >= t.size()) replace = t;
				else replace = std::to_string(t.size() / pos) + '[' + dp[i][i + pos - 1] + ']';
				if (replace.size() < dp[i][j].size()) dp[i][j] = replace;
			}
		}
		return dp[0][n - 1];
	}
};
int main(){
	Solution s;
	std::cout << s.decodeString("3[a2[c]]");
}	