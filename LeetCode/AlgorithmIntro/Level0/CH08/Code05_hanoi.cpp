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

void hanoi(int n, char from, char to, char help) {
	if (n == 1)
		std::cout << "move 1 from " << from << " to " << to << std::endl;
	else {
		hanoi(n - 1, from, help, to);
		std::cout << "move " << n << " from " << from << " to " << to << std::endl;
		hanoi(n - 1, help, to, from);
	}
	
}

int main(){
	hanoi(3, 'A', 'B', 'C');
}	