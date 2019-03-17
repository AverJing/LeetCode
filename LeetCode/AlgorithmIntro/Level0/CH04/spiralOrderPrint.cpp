/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//转圈方式打印矩阵  不一定是方阵
#include <iostream>
#include <vector>

void printEdge(std::vector<std::vector<int>>& matrix,
	int tR, int tC, int dR, int dC)
{
	if (tR == dR) {
		for (int i = tC; i <= dC; ++i)
			std::cout << matrix[tR][i] << ' ';
	}
	else if (tC == dC) {
		for (int i = tR; i <= dR; ++i)
			std::cout << matrix[i][tC] << ' ';
	}
	else {
		for (int i = tC; i < dC; ++i)
			std::cout << matrix[tR][i] << ' ';
		for (int i = tR; i < dR; ++i)
			std::cout << matrix[i][dC] << ' ';
		for (int i = dC; i > tC; --i)
			std::cout << matrix[dR][i] << ' ';
		for (int i = dR; i > tR; --i)
			std::cout << matrix[i][tC] << ' ';
	}
}

void spiralOrderPrint(std::vector<std::vector<int>>& matrix) {
	if (matrix.empty()) return;

	int TR = 0;
	int TC = 0;
	int DR = matrix.size() - 1;
	int DC = matrix[0].size() - 1;

	while (TR <= DR && TC <= DC) {
		printEdge(matrix, TR++, TC++, DR--, DC--);
	}
}


int main(){
	std::vector<std::vector<int>> matrix{ {1,2,3,4,5},{6,7,8,9,10} };
	spiralOrderPrint(matrix);
}	