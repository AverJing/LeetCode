/*
*
*
*@author: Aver Jing
*@description：给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
注意乘积中没有A[i]
*@date：
*
*
*/

/*
链接：https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46
来源：牛客网

B[i]的值可以看作下图的矩阵中每行的乘积。
下三角用连乘可以很容求得，上三角，从下向上也是连乘。
因此我们的思路就很清晰了，先算下三角中的连乘，即我们先算出B[i]中的一部分，
然后倒过来按上三角中的分布规律，把另一部分也乘进去。
*/

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	//思想借助已经得到的结果获取新的结果，减少运算
	vector<int> multiply(const vector<int>& A) {
		if (A.empty()) return {};

		vector<int> result;
		result.resize(A.size(),0);

		result[0] = 1;
		//计算下三角
		for (auto i = 1; i < A.size(); ++i) {
			result[i] = result[i - 1] * A[i - 1];
		}
			
		int tmp = 1;
		//计算上三角
		for (int i = A.size() - 2; i >= 0; --i) {
			tmp *= A[i + 1];
			result[i] *= tmp;
		}

		return result;
	}
};

int main(){
	Solution s;
	for (auto e : s.multiply({ 1,2,3,4 }))
		std::cout << e << ' ';
}	