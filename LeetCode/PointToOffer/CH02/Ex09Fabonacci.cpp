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
	int Fibonacci(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		int FiboOne = 0;
		int FiboTwo = 1;
		int result = 0;
		for (int i = 2; i <= n; ++i) {
			result = FiboOne + FiboTwo;
			FiboOne = FiboTwo;
			FiboTwo = result;
		}

		return result;
	}
};

int main(){
	
}	