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

//数组中只有一个数出现一次
int getOddCountNum(const vector<int>& arr) {
	int res = 0;

	for (auto e : arr)
		res ^= e;

	return res;
}

//数组中有两个不同的数出现一次
std::pair<int,int> getOddCountNum2(const vector<int>& arr) {
	int res = 0, eOne = 0;

	for (auto e : arr)
		res ^= e;

	int right = res & (~res + 1);//获取res最右边为1的数

	for (auto e : arr) {
		if (e&right) eOne ^= e;
	}
	return { eOne, res^eOne };
}

int main(){
	
}	