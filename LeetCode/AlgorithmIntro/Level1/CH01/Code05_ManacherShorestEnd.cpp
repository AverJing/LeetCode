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
#include <climits>

using std::string;
using Arr = std::vector<int>;

string manacherString(const string& s) {
	string res;

	for (int i = 0; i < s.size(); ++i) {
		res += string("#") + s[i];
	}
	return res + "#";
}

string shortestEnd(const string& s) {
	if (s.empty() || s.size() < 2) return s;

	auto str = manacherString(s);

	Arr pArr(str.size(), 0);
	int pR = -1;
	int index = -1;
	int maxContainEnd = -1;
	for (int i = 0; i < str.size(); ++i) {
		pArr[i] = pR > i ? std::min(pArr[2 * index - i], pR - i) : 1;
		while (i + pArr[i]<str.size() && i - pArr[i]>-1) {
			if (str[i + pArr[i]] == str[i - pArr[i]]) {
				++pArr[i];
			}
			else {
				break;
			}
		}
		if (i + pArr[i] > pR) {
			pR = i + pArr[i];
			index = i;
		}
		if (pR == str.size()) {
			maxContainEnd = pArr[i];
			break;
		}
	}
	string res(s.size() - maxContainEnd + 1, ' ');
	for (int i = 0; i < res.size(); ++i) {
		res[res.size()-i-1] = str[i * 2 + 1];
	}
	return res;
}

int main(){
	string s("abcd");

	std::cout << shortestEnd(s);
}	