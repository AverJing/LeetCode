/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
*/
#pragma once

#include <cmath>

class Solution {
public:
	/*lazy
	double myPow(double x, int n) {
		return std::pow(x, n);
	}*/
	//binary search
	double myPow(double x, int n) {
		if (!n) return 1;
		double tmp = pow(x, n / 2);
		return n & 0x1 ? n > 0 ? x * tmp * tmp : tmp * tmp / x : tmp * tmp;
	}
};