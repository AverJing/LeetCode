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

//用分治法求a的n次方

template<class T>
T powN(T t, int n) {
	if (n == 1) return t;

	return n & 0x1 ? powN(t, n / 2)*powN(t, n / 2)*t : powN(t, n / 2)*powN(t, n / 2);
}

int main(){
	std::cout << powN(10, 8);
}	