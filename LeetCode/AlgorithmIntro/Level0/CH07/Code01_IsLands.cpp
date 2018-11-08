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

using std::vector;

using Matrix = vector<vector<int>>;

void infect(Matrix &m, int i, int j, int N, int M) {
	if (i < 0 || j < 0 || i >= N || j >= M || m[i][j] != 1) {
		return;
	}
	m[i][j] = 2;
	infect(m, i - 1, j, N, M);
	infect(m, i + 1, j, N, M);
	infect(m, i, j-1, N, M);
	infect(m, i, j+1, N, M);
}

int countIslands(Matrix &matrix) {
	if (matrix.empty()) return 0;

	int res = 0;
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == 1) {
				++res;
				infect(matrix, i, j, matrix.size(), matrix[0].size());
			}
		}
	}
	return res;
}

int main(){
	Matrix m{ {0,0,0,0,1,0},
			  {0,0,0,0,0,0},
			  {0,0,0,0,0,0},
			  {0,0,0,0,0,0}, };

	std::cout << countIslands(m) << std::endl;
}	