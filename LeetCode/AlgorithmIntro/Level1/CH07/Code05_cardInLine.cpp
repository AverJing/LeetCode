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

using Arr = std::vector<int>;

int f(const Arr& data, int i, int j);
int s(const Arr& data, int i, int j);
//f(i,j)表示在i到j这个排列上被绝顶聪明的人先拿得到的分数
int f(const Arr& data, int i, int j) {
	if (i == j)
		return data[i];
	//s(i+1,j)其实表示先拿的人第二次拿的结果
	return std::max(data[i] + s(data, i + 1, j), data[j] + s(data, i, j - 1));
}
//s(i,j)表示在i到j这个排列上被绝顶聪明的人后拿得到的分数
int s(const Arr& data, int i, int j) {
	if (i == j) return 0;
	//把最差的结果给对手
	return std::min(f(data, i + 1, j), f(data, i, j - 1));
}

int win1(const Arr& data) {
	if(data.empty()) return 0;

	return std::max(f(data, 0, data.size() - 1), s(data, 0, data.size() - 1));
}

int win2(const Arr& data) {
	if (data.empty()) return 0;

	std::vector<std::vector<int>> f(data.size(), std::vector<int>(data.size(), 0));
	std::vector<std::vector<int>> s(data.size(), std::vector<int>(data.size(), 0));

	for (int j = 0; j < data.size(); ++j) {
		f[j][j] = data[j];
		for (int i = j - 1; i >= 0; --i) {
			f[i][j] = std::max(data[i] + s[i + 1][j], data[j] + s[i][j - 1]);
			s[i][j] = std::min(f[i + 1][j], f[i][j - 1]);
		}
	}
	return std::max(f[0][data.size() - 1], s[0][data.size() - 1]);
}

int main(){
	std::cout << win2({ 1,2,100,4 });
}	