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

void printProcess(int i, int N, bool down) {
	if (i > N)return;
	printProcess(i + 1, N, true);
	std::cout << (down ? "down " : "up ");
	printProcess(i + 1, N, false);
}

void PrintAllFolds(int N) {
	printProcess(1, N, true);
}

int main(){
	PrintAllFolds(3);
}	