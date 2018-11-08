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
#include <queue>
#include <vector>

using Arr = std::vector<int>;
using MinHeap = std::priority_queue<int>;

//huffman classic problem

int lessMoney(Arr& data) {
	int cost = 0;
	MinHeap result;
	for (auto e : data)
		result.push(e);
	while (result.size() != 1) {
		auto tmp = result.top();
		result.pop();
		tmp += result.top();
		result.pop();
		result.push(tmp);
	}
	return result.top();
}

int main(){
	Arr data{ 3, 5, 2, 7, 0, 1, 6, 4 };
	std::cout << lessMoney(data);
}	