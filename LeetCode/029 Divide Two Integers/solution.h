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
Given two integers dividend and divisor, divide two integers without using multiplication, 
division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2

Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit 
signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, 
assume that your function returns 2^31 − 1 when the division result overflows.
*/
#pragma once

#include <numeric>

class Solution {
public:
	int divide(int dividend, int divisor) {
		//dividend = dividend > INT_MAX ? INT_MAX : dividend;
		//dividend = dividend < INT_MIN ? INT_MIN : dividend;
		//divisor = divisor > INT_MAX ? INT_MAX : divisor;
		//divisor = divisor < INT_MIN ? INT_MIN : divisor;
		long result = static_cast<long>(dividend) / divisor;
		if (result < INT_MIN || result > INT_MAX)
			return INT_MAX;
		else
			return result;
	}
};