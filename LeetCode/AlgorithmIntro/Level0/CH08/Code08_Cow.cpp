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
#include <bitset>

template<class T>
using Matrix = std::vector<std::vector<T>>;

int Cow(int n) {
	if (n < 1)return 0;
	else if (n < 4) return n;

	return Cow(n - 3) + Cow(n - 1);
}

//iterator
int CowIter(int n) {
	if (n < 1)return 0;
	else if (n <= 4) return n;

	int res = 3;
	int pre = 2;
	int prepre = 1;
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 4; i <= n; ++i) {
		tmp1 = res;
		tmp2 = pre;
		res = prepre + res;
		pre = tmp1;
		prepre = tmp2;
	}
	return res;
}

//VS  会自动调用相应的移动函数
template <class T>
Matrix<T> MultiMatrix(Matrix<T>& lhs, Matrix<T>& rhs) {
	if (lhs.empty() || rhs.empty() || lhs[0].size()!=rhs.size()) return {};
	Matrix<T> res(lhs.size(), std::vector<T>(lhs[0].size(), 0));
	for (int i = 0; i < lhs.size(); ++i) {//lhs row
		for (int j = 0; j < lhs[0].size(); ++j) {//lhs coln
			for (int k = 0; k < rhs.size(); ++k) {//rhs row
				res[i][j] += lhs[i][k] * rhs[k][j];
			}
		}
	}
	return res;
}

//计算矩阵的n次方
template <class T>
Matrix<T> MatrixPow(const Matrix<T>& m, int n) {
	if (m.empty()) return {};

	Matrix<T> res(m.size(), std::vector<T>(m[0].size(), 0));
	for (int i = 0; i < m.size(); ++i) {
		res[i][i] = 1;
	}
	Matrix<T> tmp(m);
	for (; n ; n >>= 1) {
		if (n & 1) {
			res = MultiMatrix(res, tmp);;
		}
		tmp = MultiMatrix(tmp, tmp);
	}
	return res;
}

int Fibonacci(int n) {
	if (n < 3) return n;

	auto res = MatrixPow(Matrix<int>{ {1, 1}, { 1,0 }}, n - 2);

	return res[0][0] + res[1][0];
}

int stepCal(int n) {
	if (n < 3) return n;

	auto res = MatrixPow(Matrix<int>{ {1, 1}, { 1,0 }}, n - 2);

	return 2 * res[0][0] + res[1][0];
}

int CowCal(int n) {
	if (n < 4) return n;

	auto res = MatrixPow(Matrix<int>{ {1, 1, 0}, { 0, 0, 1 }, {1, 0, 0}}, n - 3);

	return 3 * res[0][0] + 2 * res[1][0] + res[2][0];
}

//https://www.zhihu.com/question/29511959
std::vector<int>&& test() {
	return std::vector<int>{1, 2, 3, 4};
}//holds a reference to the destructed tmp inside the function

int main(){
	/*
	auto res(MatrixPow(Matrix<int>{ {1, 0}, { 0,1 } }, 10));
	for (auto e : res) {
		for (auto d : e)
			std::cout << d << ' ';
	}*/
//	std::vector<int> ivec(test());

	std::cout << Fibonacci(10);
}	