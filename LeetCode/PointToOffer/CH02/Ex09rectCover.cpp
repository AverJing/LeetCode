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
	int rectCover(int number) {
		if (number < 3) return number;
		int rectOne = 1;
		int rectTwo = 2;
		int result;
		for (int i = 3; i <= number; ++i) {
			result = rectOne + rectTwo;
			rectOne = rectTwo;
			rectTwo = result;
		}
		return result;
	} 
};

int main(){
	
}	