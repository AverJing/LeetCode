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
#include <functional>

using std::vector;
using namespace std::placeholders;
/*
bool comp(int a, int b) {
	return a < b;
}
void test(vector<int>& para) {
	std::sort(para.begin(), para.end(), comp);
}*/

//or
/*
class test_sort {
public:
	static bool comp(int a, int b) {
		return a < b;
	}
	void test(vector<int>& para) {
		std::sort(para.begin(), para.end(), comp);
	}
};*/

//or
class test_sort {
public:
	bool comp(int a, int b) {
		return a < b;
	}
	void test(vector<int>& para) {
		//std::sort(para.begin(), para.end(), std::bind(&test_sort::comp, this, _1, _2));
		std::sort(para.begin(), para.end(), [this](int a, int b) {return comp(a, b); });
	}
};

int main(){
	vector<int> ivec{ 2,3,1,6,5,4 };
	test_sort s;
	s.test(ivec);
	for (auto i : ivec)
		std::cout << i << ' ';
}	