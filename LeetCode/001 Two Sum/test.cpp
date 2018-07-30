/*
*
*@author£ºAver Jing
*@description£º
*@date£º
*
*/

#include<iostream>
#include "solution.h"

using namespace std;

int main() {
	Solution s;

	std::vector<int> v1{ 2, 7, 11, 15 };
	cout << (s.twoSum(v1, 9) == std::vector<int>{0, 1}) << endl;

	return 0;
}