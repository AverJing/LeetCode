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

class Solution {
public:
	double Power(double base, int exponent) {
		if (equal_double(base, 0.0) && exponent < 0) return 0.0;

		unsigned int absExponent = std::abs(exponent);
		
		double result = calPow(base, absExponent);

		if (exponent < 0) return 1.0 / result;
		
		return result;
	}
private:
	double calPow(double base, unsigned int exponent) {
		if (exponent == 0) return 1;
		if (exponent == 1) return base;

		auto result = calPow(base, exponent >> 1);
		result *= result;
		if (exponent & 0x01) result *= base;

		return result;
	}
	bool equal_double(double lhs, double rhs) {
		if (lhs - rhs > -0.0000001 && lhs - rhs < 0.0000001)
			return true;
		return false;
	}
};

int main(){
	
}	