/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
//小和问题（逆序数问题），用归并排序（思想，分治法）求解
#include <iostream>
#include <vector>

template<class T>
int merge(T& rhs, int L, int mid, int R) {
	T t(R - L + 1, 0);
	int res = 0;
	int p1 = L;
	int p2 = mid + 1;
	int i = 0;
	while (p1 <= mid && p2 <= R) {
		//res += (rhs[p1] < rhs[p2] ? rhs[p1] * (R - p2 + 1) : 0);//求小和
		res += (rhs[p1] < rhs[p2] ? (R - p2 + 1) : 0); //求逆序对
		t[i++] = (rhs[p1] < rhs[p2] ? rhs[p1++] : rhs[p2++]);
	}

	while (p1 <= mid)
		t[i++] = rhs[p1++];
	while (p2 <= R)
		t[i++] = rhs[p2++];

	for (int i = 0; i < t.size(); ++i)
		rhs[L + i] = t[i];

	return res;
}

template<class T>
int sortProcess(T& rhs, int L, int R) {
	if (L == R) return 0;

	int mid = L + ((R - L) >> 1);
	return sortProcess(rhs, L, mid)+
	sortProcess(rhs, mid + 1, R)+
	merge(rhs, L, mid, R);
}

template<class T>
int mergeSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return 0;

	return sortProcess(rhs, 0, rhs.size() - 1);
}

int main(){
	std::vector<int> ivec{ 1,3,4,2,5 };
	std::cout << mergeSort(ivec);
}	