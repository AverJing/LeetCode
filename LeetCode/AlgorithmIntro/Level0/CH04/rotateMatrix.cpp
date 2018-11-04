/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//旋转方阵
#include <iostream>
#include <vector>

void rotateEdge(std::vector<std::vector<int>>& matrix, int tR, int tC, int dR, int dC) {
	int times = dR - tR;

	for (int i = 0; i < times; ++i) {
		int tmp = matrix[tR][tC + i];
		matrix[tR][tC + i] = matrix[dR - i][tC];
		matrix[dR - i][tC] = matrix[dR][dC - i];
		matrix[dR][dC - i] = matrix[tR + i][dC];
		matrix[tR + i][dC] = tmp;
	}
}

void rotateMatrix(std::vector<std::vector<int>>& matrix) {
	if (matrix.empty()) return;

	int TR = 0;
	int TC = 0;
	int DR = matrix.size() - 1;
	int DC = matrix[0].size() - 1;

	while (TR < DR) {
		rotateEdge(matrix, TR++, TC++, DR--, DC--);
	}
}


int main(){
	std::vector<std::vector<int>> matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	rotateMatrix(matrix);


}	