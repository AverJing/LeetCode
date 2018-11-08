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
#include <algorithm>

using std::string;
using Arr = std::vector<string>;

string lowestString(Arr& strs) {
	if (strs.empty()) return "";

	std::sort(strs.begin(), strs.end(), [](string& s1, string& s2) {
		return s1 + s2 < s2 + s1;
	});

	string s;
	for (auto& e : strs)
		s += e;

	return s;
}

int main(){
	Arr strs = { "jibw", "ji", "jp", "bw", "jibw" };
	std::cout << lowestString(strs);
}	