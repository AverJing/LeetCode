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

class Sum {
public:
	Sum() { ++num; sum += num; }
	inline static void Reset() { sum = 0; num = 0; }
	inline static int GetSum() { return sum; }
private:
	static int sum;
	static int num;
};

int Sum::sum = 0;
int Sum::num = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Sum::Reset();	//记得初始化  否则多次计算结果会出错
		auto result = new Sum[n];
		delete[]result;
		result = nullptr;
		return Sum::GetSum();
	}
};

int main(){
	Solution s;
	std::cout << s.Sum_Solution(5);
}	