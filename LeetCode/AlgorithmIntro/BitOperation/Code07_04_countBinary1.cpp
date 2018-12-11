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
#include <bitset>
#include "../Level0/CH01/TestCase.h"

int count1(int n) {
	int res = 0;
	while (n) {
		res += n & 1;
		n >>= 1;
	}
	return res;
}

int count2(int n) {
	int res = 0;
	while (n) {
		n &= (n - 1);
		++res;
	}
	return res;
}

int count3(int n) {
	int res = 0;
	while (n) {
		n -= n&(~n + 1); //排除n最右边的1
		//n&(~n + 1)得到n最右边的1
		++res;
	}
	return res;
}

//平行算法
int count4(int n) {
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555); //2
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333); //4
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f); //8
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff); //16
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff); //32

	return n;
}
//count4和count5实现差不多
//有加速

int count5(int n) {
	std::bitset<32> res(n);

	return res.count();
}

int main(){
	testCase t(10, 500);

	for (auto e : t.getArr()) {
		std::cout << e << ' ' << count1(e) << ' ' << count2(e)
			<< ' ' << count3(e)
			<< ' ' << count4(e)
			<< ' ' << count5(e) << '\n';
	}
}	