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
#include <random>
#include <algorithm>
#include "TestCase.h"

template <class T>
void Print(const T& rhs) {
	for (auto e : rhs) {
		std::cout << e << ' ';
	}
	std::cout << std::endl;
}

//思路，每次从前边冒出来一个最大的数放在后边
//注意边界条件
//O(n^2)  O(1)
template<class T>
void BubbleSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;

	for(int i = rhs.size()-1; i > 0; --i)
		for (int j = 0; j < i; ++j) {
			if (rhs[j] > rhs[j + 1])
				std::swap(rhs[j], rhs[j + 1]);
		}
}

//思路：每次从待排序的数字中选择最小的放在已排序的数字中
//O(n^2) O(1)
template<class T>
void SelectionSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;

	for (int i = 0; i < rhs.size()-1; ++i) {
		int minIndex = i;
		for (int j = i+1; j < rhs.size(); ++j) {
			minIndex = (rhs[j] < rhs[minIndex]) ? j : minIndex;
		}
		std::swap(rhs[minIndex], rhs[i]);
	}
		
}

//思路：依次从未排序的数字中，拿出第一个插入到前边有序数字的合适位置
//O(n^2) O(1)
template<class T>
void InsertionSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;

	for (int i = 1; i < rhs.size(); ++i)
		for (int j = i-1; j >=0 && rhs[j]>rhs[j+1]; --j) {
				std::swap(rhs[j], rhs[j + 1]);
		}
}

//重点    归并排序的实现
//O(NlogN) O(N)
template<class T>
void merge(T& rhs, int L, int mid, int R) {
	T t(R - L + 1, 0);
	int i = 0;
	int p1 = L;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= R) {
		t[i++] = (rhs[p1] < rhs[p2]) ? rhs[p1++] : rhs[p2++];
	}

	while (p1 <= mid)
		t[i++] = rhs[p1++];
	while (p2 <= R)
		t[i++] = rhs[p2++];

	for (auto i = 0; i < t.size(); ++i)
		rhs[L + i] = t[i];
}

template<class T>
void sortProcess(T& rhs, int L, int R) {
	if (L == R) return;

	int mid = L + ((R - L) >> 1);
	sortProcess(rhs, L, mid);
	sortProcess(rhs, mid+1, R);
	merge(rhs, L, mid, R);
}

template<class T>
void MergeSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;

	sortProcess(rhs, 0, rhs.size() - 1);
}



int main(){
	/*
	testCase t(10,20);
	t.Print();

	testCase t1(7, 30);
	t1.Print();

	testCase t2(10, 40);
	t2.Print();

	testCase t3(10, 50);
	t3.Print();*/
	/*
	std::uniform_real_distribution<double> u2(0, 1);
	std::default_random_engine e;
	for (int i = 0; i < 100; ++i)
		std::cout << u2(e) << ' ';*/

	int testTime = 100;
	bool succeed = true;
	int size = 10;
	int value = 100;

	for (int i = 0; i < testTime; ++i) {
		testCase t(size, value);
		auto arr2(t.getArr());
		auto arr3(t.getArr());

		std::sort(arr2.begin(), arr2.end());
		//BubbleSort(arr3);
		//SelectionSort(arr3);
		//InsertionSort(arr3); 
		MergeSort(arr3);

		if (!std::equal(arr2.begin(), arr2.end(), arr3.begin())) {
			succeed = false;
			t.Print();
			break;
		}

		std::cout << (succeed ? "Nice " : "fuck... ");
	}
}	