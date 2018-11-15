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

int isMatch(const string& s1, const string& s2) {
	if (s1.empty() || s2.empty() || s2.size() > s1.size())return -1;

	auto next = getNext(s1);
	int i = 0, j = 0;
	for (; i < s1.size() && j < s2.size();) {
		if (s1[i] == s2[j]) {
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

	return j == s2.size() ? i - j : -1;
}

int main(){	
	string s1("aabcaa");
	std::cout << isMatch(s1, "cca");
}	