/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>

static unsigned int seed = std::time(0);
using std::string;

class testCase {
public:
	testCase(unsigned int size = 0, unsigned int value = 0) {
		std::uniform_int_distribution<unsigned> u(0, size);//闭区间
		std::default_random_engine e(++seed);
		data.resize(u(e), 0);
		
		std::uniform_real_distribution<float> u2(0, 1);//闭区间
		for (auto& p : data)
			p = u2(e)  * value;
	}
	size_t size() { return data.size(); }
	std::vector<int>& getArr() { return data; }
	void Print() { 
		for (auto e : data) std::cout << e << ' '; 
	}
	template<class T>
	bool compare(T& rhs) {
		return std::equal(data.begin(), data.end(), rhs.begin());
	}
private:
	std::vector<int> data;
};

class testCaseString {
public:
	testCaseString(unsigned int size = 0) {
		std::uniform_int_distribution<unsigned> u(0, size);//闭区间
		std::default_random_engine e(++seed);
		data.resize(u(e),' ');

		std::uniform_int_distribution<unsigned> u2('a', 'z');//闭区间
		for (auto& p : data)
			p = u2(e);
	}
	size_t size() { return data.size(); }
	string& getString() { return data; }
	void Print() {
		std::cout << data << ' ';
	}
	template<class T>
	bool compare(T& rhs) {
		return std::equal(data.begin(), data.end(), rhs.begin());
	}
private:
	string data;
};
