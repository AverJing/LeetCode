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

void process(const std::string& chs, int i, std::string s) {
	if (i == chs.size()) {
		std::cout << s << std::endl;
		return;
	}

	process(chs, i + 1, s);
	process(chs, i + 1, s+chs[i]);
}

void PrintAllSubSequence(const std::string& chs) {
	if (chs.empty()) return;

	process(chs, 0, "");
}


int main(){
	PrintAllSubSequence("abc");
}	