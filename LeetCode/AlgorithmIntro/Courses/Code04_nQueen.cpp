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
#include <vector>
#include <algorithm>

using Arr = std::vector<int>;

bool isValid(int cur, Arr& rec, int coln) {
	for (int k = 0; k < cur; ++k) {
		//cur: current row
		//coln: current colomn
		if (rec[k] == coln || std::abs(cur - k) == std::abs(rec[k] - coln)) {
			return false;
		}
	}
	return true;
}

int process(int cur, Arr& rec, int n) {
	if (cur == n) return 1;

	int res = 0;
	for (int j = 0; j < n; ++j) {
		if (isValid(cur, rec, j)) {
			rec[cur] = j;
			res += process(cur + 1, rec, n);
		}
	}
	return res;
}

int getN_Queen(int n) {
	if (n < 1) return 0;
	else if (n == 1) return 1;
	else if (n < 4) return 0;

	Arr record(n, -1);

	return process(0, record, n);
}

int main(){
	std::cout << getN_Queen(8);
}	