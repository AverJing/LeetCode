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

int getNext(const string& s) {
	if (s.empty()) return {};

	Arr next(s.size(), -1);
	next[1] = 0;

	int cur = 0;
	for (int i = 2; i < s.size();) {
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
	return next[s.size()-1];
}

string answer(const string& s) {
	if (s.empty()) return "";

	if (s.size() == 1)
		return s + s;
	if (s.size() == 2)
		return s[0] == s[1] ? (s + s[0]) : (s + s);
	auto endNext = getNext(s);
	return s + s.substr(endNext);
}

int main(){
	std::cout << answer("abcdabcd") << std::endl;
	std::cout << answer("abcdef") << std::endl;
	std::cout << answer("aaaaa") << std::endl;
}	