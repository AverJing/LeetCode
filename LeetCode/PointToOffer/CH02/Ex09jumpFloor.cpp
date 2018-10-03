/*
*
*
*@author: Aver Jing
*@description：用dp求解，leetcode刷过
*@date：
*
*
*/

#include <iostream>

class Solution {
public:
	int jumpFloor(int number) {
		if (number < 0) return;
		else if (number < 3) return number;
		int floorOne = 1;
		int floorTwo = 2;
		int result = 0;
		for (int i = 3; i <= number; ++i) {
			result = floorOne + floorTwo;
			floorOne = floorTwo;
			floorTwo = result;
		}
		return number > 1 ? result : floorTwo;
	}
};

int main(){
	
}	