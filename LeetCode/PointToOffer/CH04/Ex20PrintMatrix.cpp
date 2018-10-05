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

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> >& matrix) {
		if (matrix.empty()) return vector<int>();
		int column = matrix[0].size();
		int row = matrix.size();
		vector<int> result;
		int start = 0;
		while (column > start * 2 && row > start * 2) {
			PrintMatrixInCircle(matrix, start, result);
			++start;
		}

		return result;
	}
private:
	void PrintMatrixInCircle(const vector<vector<int>>& matrix, int& start, vector<int>& result) {
		int endX = matrix[0].size() - start - 1;
		int endY = matrix.size() - start - 1;
		//from left to right
		for (int i = start; i <= endX; ++i)
			result.push_back(matrix[start][i]);

		//from top to buttom
		if (start < endY) {
			for (int i = start + 1; i <= endY; ++i) {
				result.push_back(matrix[i][endX]);
			}
		}

		//from right to left
		if (start < endX && start < endY) {
			for (int i = endX - 1; i >= start; --i)
				result.push_back(matrix[endY][i]);
		}

		//from buttom to top
		if (start < endX && start < endY - 1) {
			for (int i = endY - 1; i >= start + 1; --i) {
				result.push_back(matrix[i][start]);
			}
		}
	}
};

int main(){
	
}	