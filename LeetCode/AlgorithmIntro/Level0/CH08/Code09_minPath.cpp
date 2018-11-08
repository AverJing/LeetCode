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
#include <algorithm>

using Matrix = std::vector<std::vector<int>>;

int process(Matrix& m, int i, int j) {
	int res = m[i][j];

	if (i == m.size() - 1 && j == m[0].size() - 1)
		return res;
	if (i == m.size() - 1 && j != m[0].size() - 1)
		return res + process(m, i, j + 1);
	if(i != m.size() - 1 && j == m[0].size() - 1)
		return res + process(m, i+1, j);

	return res + std::min(process(m, i + 1, j), process(m, i, j + 1));
}

int GetMinPath(Matrix& m) {
	if (m.empty()) return 0;
	return process(m, 0, 0);
}

int GetMinPath2(Matrix& m) {
	if (m.empty()) return 0;

	Matrix result(m);
	
	//colm
	for (int i = m[0].size() - 2; i >= 0; --i) {
		result[m.size() - 1][i] += result[m.size() - 1][i+1];
	}
	//row
	for (int i = m.size() - 2; i >= 0; --i) {
		result[i][m[0].size()-1] += result[i+1][m[0].size() - 1];
	}

	for (int i = m.size() - 2; i >= 0; --i) {
		for (int j = m[0].size() - 2; j >= 0; --j) {
			m[i][j] += std::min(m[i + 1][j], m[i][j + 1]);
		}
	}

	return m[0][0];
}

int main(){
	Matrix m{ { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };

	//std::cout << GetMinPath(m);

	std::cout << GetMinPath2(m);
}	