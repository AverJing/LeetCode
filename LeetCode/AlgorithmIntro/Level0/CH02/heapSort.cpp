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

#include "../CH01/TestCase.h"

template<class T>
void heapInsert(T& rhs, int index) {
	while (rhs[index] > rhs[(index - 1) / 2]) {
		std::swap(rhs[index], rhs[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

template<class T>
void heapify(T& rhs, int index, int size) {
	//left is left child of index
	int left = index * 2 + 1;
	while (left < size) {
		int indexMax = (left + 1 < size && rhs[left] < rhs[left + 1]) ? left + 1 : left;
		indexMax = (rhs[index] < rhs[indexMax]) ? indexMax : index;

		if (index == indexMax)
			break;
		else {
			std::swap(rhs[index], rhs[indexMax]);
			index = indexMax;
			left = index * 2 + 1;
		}
	}
}

template<class T>
void heapSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;
	
	//generate max heap
	for (int i = 0; i < rhs.size(); ++i) {
		heapInsert(rhs, i);
	}

	auto heapSize = rhs.size();
	//switch the max(first) value with the final value
	std::swap(rhs[0], rhs[--heapSize]);
	while (heapSize > 0) {
		//readjust the heap to max heap
		heapify(rhs, 0, heapSize);
		std::swap(rhs[0], rhs[--heapSize]);
	}
}

int main(){
	for (int i = 0; i < 20; ++i) {
		testCase t(10, 50);	
		heapSort(t.getArr());
		for (auto e : t.getArr())
			std::cout << e << ' ';
		std::cout << std::endl;
	}
}	