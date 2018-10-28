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

template<class T>
void heapInsert(T& rhs, int index) {
	while (rhs[index] > rhs[(index - 1) / 2]) {
		std::swap(rhs[index], rhs[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

template<class T>
void heapSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;

	for (int i = 0; i < rhs.size(); ++i) {
		heapInsert(rhs, i);
	}
}

int main(){
	std::vector<int> ivec{ 2,1,4,5,6,7,3 };

	heapSort(ivec);

	for (auto e : ivec)
		std::cout << e << ' ';
}	