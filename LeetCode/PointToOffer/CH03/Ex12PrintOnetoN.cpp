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

bool Increament(string& s) {
	bool isOverFlow = false;
	int nTakeOver = 0;

	for (int i = s.size() - 1; i >= 0; --i) {
		int nSum = s[i] - '0' + nTakeOver;

		if (i == s.size() - 1)
			++nSum;

		if (nSum >= 10) {
			if (i == 0)
				isOverFlow = true;
			else {
				nSum -= 10;
				nTakeOver = 1;
				s[i] = nSum + '0';
			}
		}
		else {
			s[i] = nSum + '0';
			break;
		}
	}
	return isOverFlow;
}

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
void PrintOneToN(int n) {
	if (n <= 0) return;

	string number(n, '0');
	
	while (!Increament(number)) {
		PrintNumber(number);
	}
}

int main(){
	PrintOneToN(2);
}	