#include <iostream>
#include <string>

using std::string;

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		if (s.empty() && p.empty()) return true;
		auto i = 0, j = 0, temp = 0;
		for (; j != p.size(); ++i, j = temp) {
			if (p[j + 1] != '*') ++temp;
			else if (isMatch(s.substr(i), p.substr(temp + 2))) return true;
			if (i == s.size() && p[j] == '.') return false;
			if (!((p[j] == '.') || s[i] == p[j])) return false;
		}
		return i == s.size();

		/*
		const char *cs = s.c_str(), *cp = p.c_str();
		for (char c = *cp; c != '\0'; ++cs, c = *cp) {
		if (cp[1] != '*') ++cp;
		else if (isMatch(cs, cp + 2)) return true;
		if (!(c == *cs || (c == '.' && *cs != '\0'))) return false;
		}
		return *cs == '\0';*/
	}
};

int main() {
	Solution s;
	std::cout << s.isMatch("mississppi", "mis*is*p*.") << std::endl;
}