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
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty()) return false;
		int r = 0;
		int c = array[0].size()-1;

		for (; r < array.size() && c >= 0;) {
			if (array[r][c] == target) return true;
			else if (array[r][c] > target) --c;
			else ++r;
		}
		return false;
	}
};

int main(){
	
}	