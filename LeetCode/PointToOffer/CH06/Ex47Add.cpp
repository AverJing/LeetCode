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
	//思想很重要
	int Add(int num1, int num2)
	{
		do {
			auto sum = num1 ^ num2;
			auto carry = (num1&num2) << 1;

			num1 = sum;
			num2 = carry;
		} while (num2 != 0);

		return num1;
	}
};

int main(){
	
}	