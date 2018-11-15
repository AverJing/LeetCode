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
		res += string("#") + s[i] ;
	}
	return res + "#";
}

string maxLcapsLength(const string& s) {
	if (s.empty() || s.size() < 2) return s;

	auto str = manacherString(s);
	Arr pArr(str.size(), 0);
	int pR = -1;
	int index = -1;
	int maxNum = INT_MIN;
	string res;
	for (int i = 0; i < str.size(); ++i) {
		pArr[i] = pR > i ? std::min(pArr[2 * index - i], pR - i) : 1;
		while (i + pArr[i]<str.size() && i - pArr[i] > -1) {
			if (str[i + pArr[i]] == str[i - pArr[i]]) {
				++pArr[i];
			}
			else {
				break;
			}
		}
		if (i + pArr[i] > pR) {
			index = i;
			pR = i + pArr[i];
		}
		if (maxNum < pArr[i]) {
			maxNum = std::max(maxNum, pArr[i]);
			//res = str.substr(index + 1 - pArr[index], 2 * pArr[index]-1);;
			res = s.substr((index + 1 - pArr[index]) / 2, (2 * pArr[index] - 1) / 2);
		}	
	}
	return res;
}


int main(){
	string s("abc123321cab");
	std::cout << manacherString(s) << std::endl;
	std::cout << maxLcapsLength(s) << std::endl;
}	