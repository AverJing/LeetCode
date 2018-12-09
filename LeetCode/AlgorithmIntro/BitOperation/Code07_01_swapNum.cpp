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

//P334
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
//a^b=c，那么c就是a和b整数位信息和b整数位信息所以不同信息

int main(){
	
}	