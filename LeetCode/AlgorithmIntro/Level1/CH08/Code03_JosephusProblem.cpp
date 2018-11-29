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

int JosephusProblem(int n, int m) {
	if (n < 1 || m < 1) return -1;

	int last = 0;
	for (int i = 2; i <= n; ++i)
		last = (last + m) % i;

	return last;
}

int main(){
	
}	