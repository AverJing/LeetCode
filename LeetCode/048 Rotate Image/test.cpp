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
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> temp;
		temp.capacity();
		temp.reserve(matrix.size());
		for (int i = matrix.size() - 1; i >= 0; --i) {
			for (int j = 0; j < matrix[i].size(); ++j) {
				temp[j].push_back(matrix[i][j]);
			}
		}
		matrix = temp;
	}
};

int main(){
	vector<vector<int>> maxtrix{ {1} };
	Solution s;
	s.rotate(maxtrix);
}	