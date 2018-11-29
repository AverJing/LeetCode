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
#include <random>

//给出一个数num，请把小于num的数放在数组的左边，大于num的数放在数组的右边,等于num放在中间
//O(n) O(1)
template<class T>
std::pair<int, int> partitionByNum(T& rhs, int num) {
	if (rhs.empty() || rhs.size() < 2) return;

	int less = -1;
	int more = rhs.size();
	for (int curr = 0; curr < more;) {
		if (rhs[curr] < num) {
			std::swap(rhs[++less], rhs[curr++]);
		}
		else if (rhs[curr] > num) {
			std::swap(rhs[--more], rhs[curr]);
		}
		else {
			++curr;
		}
	}
	return {less+1, more-1};
}

//标准库partition 返回第一个为假的迭代器
//此处根据lambda进行判断的
template<class T>
void partitionByNumBySTL(T& rhs, int num) {
	std::partition(rhs.begin(), rhs.end(), [=](int i) { return i < num; });
}

//走一把随机快排
template<class T>
std::pair<int, int> partition_quick(T& rhs, int L, int R) {
	int less = L-1;
	int more = R;  //注意和partitionByNum的区别，此处为了简便把rhs[R]暂时放到more中
	while (L < more) {
		if (rhs[L] < rhs[R]) {
			std::swap(rhs[++less], rhs[L++]);
		}
		else if (rhs[L] > rhs[R]) {
			std::swap(rhs[--more], rhs[L]);
		}
		else {
			++L;
		}
	}
	std::swap(rhs[R], rhs[L]);  //将rhs[R]放在合适的位置
	return { less + 1, more };
}

//random quick sork   O(N*logN) O(logN)
template<class T>
void quickSort(T& rhs, int L, int R) {
	if (L < R) {
		//如果使用rand的结果除以RAND_MAX，这种方法不正确，因为 随机整数的精度通常
		//低于随机浮点数，这样就导致有一些浮点数永远不会被生成了
		//使用STL可以得到更好的随机数，但是比rand慢
		std::uniform_real_distribution<double> u(0, 1);
		std::default_random_engine e;
		std::swap(rhs[L + static_cast<int>(u(e)*(R - L))], rhs[R]);

		auto p = partition_quick(rhs, L, R);
		quickSort(rhs, L, p.first - 1);
		quickSort(rhs, p.second + 1, R);
	}
}

template<class T>
void quickSort(T& rhs) {
	if (rhs.empty() || rhs.size() < 2) return;

	quickSort(rhs, 0, rhs.size() - 1);
}


int main(){
	std::vector<int> ivec{ 1,3,2,3,4,1,3,5,3,7,3,8 };
	std::vector<int> ivec2{ 1,7,2,5,7,3 };
	//partitionByNum(ivec, 3);
	//partitionByNumBySTL(ivec2, 3);

	quickSort(ivec);

	for (auto e : ivec)
		std::cout << e << ' ';

}	