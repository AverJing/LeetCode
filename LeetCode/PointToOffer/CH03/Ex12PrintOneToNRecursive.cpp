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

using std::string;

void PrintNumber(const string& s)
{
	bool endZero = false;
	for (auto e : s) {
		if (e != '0')
			endZero = true;
		if (endZero) std::cout << e;

	}
	std::cout << ' ';
}

void Print1ToNRecursively(string& s, int index) {
	if (index == s.size() - 1) {
		PrintNumber(s);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		s[index + 1] = i + '0';
		Print1ToNRecursively(s, index + 1);
	}
}

void Print1ToN(int n) {
	string s(n, '0');

	for (int i = 0; i < 10; ++i) {
		s[0] = i + '0';
		Print1ToNRecursively(s, 0);
	}
}


int main(){
	Print1ToN(2);
}	