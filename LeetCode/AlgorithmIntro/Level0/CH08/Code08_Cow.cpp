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

int Cow(int n) {
	if (n < 1)return 0;
	else if (n < 4) return n;

	return Cow(n - 3) + Cow(n - 1);
}

//iterator
int CowIter(int n) {
	if (n < 1)return 0;
	else if (n <= 4) return n;

	int res = 3;
	int pre = 2;
	int prepre = 1;
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 4; i <= n; ++i) {
		tmp1 = res;
		tmp2 = pre;
		res = prepre + res;
		pre = tmp1;
		prepre = tmp2;
	}
	return res;
}

int main(){
	std::cout << Cow(8) << ' ' << CowIter(8);
}	