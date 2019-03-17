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

float custom_sqrt(float n) {
	if (n < 0) return-1;
	if (n == 0) return 0;
	float x1 = 1.0f;
	float x2 = 2.0f;
	int count = 0;
	while (true) {
		++count;
		x2 = (x1*x1 + n) / (2 * x1);
		x1 = x2;
		if (std::abs(x2*x2 - n) < 0.00001)
			break;
	}
	std::cout << count << std::endl;
	return x2;
}

float FastInvSqrt(float x) {
	float xhalf = 0.5f * x;
	int i = *(int*)&x;         // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);  // what the fuck?
	x = *(float*)&i;
	x = x * (1.5f - (xhalf*x*x));
	return x;
}  

//这个算法求得是   1/sqrt(x)

int main(){
	//std::cout << custom_sqrt(1800);
	//std::cout << FastInvSqrt(180000000000);
}	