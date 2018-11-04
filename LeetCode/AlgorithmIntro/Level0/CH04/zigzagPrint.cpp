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
#include <vector>

using Matrix = std::vector<std::vector<int>>;

void printLevel(Matrix& m, int tR, int tC, int dR, int dC, bool f) {
	if (f) {
		while (tR != dR + 1) {
			std::cout << m[tR++][tC--] << ' ';
		}
	}
	else {
		while (dR != tR - 1) {
			std::cout << m[dR--][dC++] << ' ';
		}
	}
}

void zigzagPrint(Matrix& matrix) {
	if (matrix.empty()) return;

	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;

	int endX = matrix[0].size();
	int endY = matrix.size();
	bool fromUp = false;
	while (tR != endY) {
		printLevel(matrix, tR, tC, dR, dC, fromUp);
		tR = (tC == endX - 1) ? tR + 1 : tR;
		tC = (tC == endX - 1) ? tC : tC + 1;
		dC = (dR == endY - 1) ? dC + 1 : dC;  //注意 此处还有点小问题
		dR = (dR == endY - 1) ? dR : dR + 1;//此处拿的是dr进行判断的，所以dC和dR的顺序不要颠倒
		fromUp = !fromUp;
	}
}

int main(){
	Matrix m{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };

	zigzagPrint(m);
}	