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

int main(){
	std::cout << Cow(5);
}	