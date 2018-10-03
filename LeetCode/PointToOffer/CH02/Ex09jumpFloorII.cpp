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
#include <cmath>

class Solution {
public:
	/*
	int jumpFloorII(int number) {
		if (number < 3) return number;
		else return calPow(2, number - 1);
	}
	int calPow(int p, int power) {
		if (power == 1) return p;
		else {
			int temp = calPow(p, power / 2);
			if (power % 2) return temp * temp * p;
			else return temp * temp;
		}
	}*/

	int jumpFloorII(int number) {
		if (number < 3) return number;
		else return std::pow(2, number - 1);
	}
};

int main(){
	
}	