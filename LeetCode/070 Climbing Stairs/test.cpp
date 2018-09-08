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

int climbStairs(int n) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
	std::cout << climbStairs(4) << std::endl;

	return 0;
}