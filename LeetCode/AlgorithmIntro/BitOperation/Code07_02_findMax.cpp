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
#include <bitset>
//P335
//判断a-b的符号
inline int findMax(int a, int b) {
	int c = a - b;//如果a-b溢出，结果就不正确

	bool signal = (c >> 31) & 1;

	return a * !signal + b * signal;
}

//解决溢出问题
//只有a和b异号c才会溢出
inline bool getSignal(int a) {
	return   (a >> 31) & 0x1;
}

inline int findMaxFix(int a, int b) {
	bool signalA = getSignal(a);
	bool signalB = getSignal(b);

	if (signalA^signalB) return a * !signalA + b * !signalB;
	else {
		int c = a - b;//如果a-b溢出，结果就不正确
		bool signalC = getSignal(c);
		return a * !signalC + b * signalC;
	}	
}

int main(){
	/*std::cout << findMax(10, 8) << std::endl;
	std::cout << findMax(-10, 8) << std::endl;
	std::cout << findMax(-10, -8) << std::endl;*/
	//int a = 2147483647; INT_MAX
	//std::cout << findMaxFix(2147483647, 100) << std::endl;
}	