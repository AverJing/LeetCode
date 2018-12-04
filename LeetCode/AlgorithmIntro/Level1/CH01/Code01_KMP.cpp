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

using string = std::string;
using Arr = std::vector<int>;

Arr getNext(const string& s) {
	if (s.empty()) return {};

	Arr next(s.size(), -1);

	if (s.size() > 1) next[1] = 0;

	int cur = 0;
	for (int i = 2; i < s.size(); ) {
		if (s[i - 1] == s[cur]) {
			next[i++] = ++cur;
		}
		else if (cur > 0) {
			cur = next[cur];
		}
		else {
			next[i++] = 0;
		}
	}

	return next;
}

int isMatch(const string& s, const string& m) {
	if (s.empty() || m.empty() || m.size() > s.size())return -1;

	auto next = getNext(m);
	int i = 0, j = 0;
	for (; i < s.size() && j < m.size();) {
		if (s[i] == m[j]) {
			++i;
			++j;
		}
		else if (next[j] != -1) {
			j = next[j];
		}
		else {
			++i;
		}
	}

	return j == m.size() ? i - j : -1;
}

int main(){	
	string s("aabcaa");
	std::cout << isMatch(s, "caa");
}	