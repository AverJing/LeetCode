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

void getSize(int num[]) {
	std::cout << sizeof(num) << std::endl;
}

int main(){
	int num1[] = { 1,2,3,4 };
	auto num2 = num1;

	std::cout << sizeof(num1) << std::endl;
	std::cout << sizeof(num2) << std::endl;
	getSize(num1);
	
}	