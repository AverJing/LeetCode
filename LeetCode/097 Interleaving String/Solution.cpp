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

using std::string;
using std::vector;

class Solution {
public:
	/*
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.empty()) return true;
		if (s1.empty() && s2.empty() && !s3.empty()) return false;

		for (int i1 = 0, i2 = 0, j = 0; (i1 < s1.size() || i2 < s2.size()) && j < s3.size();++j) {
			if (!s1.empty() && s1[i1] == s3[j]) ++i1;
			else if (!s2.empty() && s2[i2] == s3[j]) ++i2;
			else return false;
		}
		return true;
	}*/
	//https://www.cnblogs.com/grandyang/p/4298664.html
	//其中f[i][j] 表示的是 s2 的前 i 个字符和 s1 的前 j 个字符是否匹配 s3 的前 i+j 个字符
	bool isInterleave(const string& s1, const string& s2, const string& s3) {
		if (s3.length() != s1.length() + s2.length())
			return false;
		vector<vector<bool>> f(s1.length() + 1,
			vector<bool>(s2.length() + 1, true));
		for (size_t i = 1; i <= s1.length(); ++i)
			f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (size_t i = 1; i <= s2.length(); ++i)
			f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		for (size_t i = 1; i <= s1.length(); ++i)
			for (size_t j = 1; j <= s2.length(); ++j)
				f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
				|| (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
		return f[s1.length()][s2.length()];
	}
};

int main(){
	Solution s;
	std::cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}	