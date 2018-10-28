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

#include <random>
#include <vector>
#include <ctime>

static unsigned int seed = std::time(0);

class testCase {
public:
	testCase(unsigned int size = 0, unsigned int value = 0) {
		std::uniform_int_distribution<unsigned> u(0, size);
		std::default_random_engine e(++seed);
		data.resize(u(e), 0);
		
		std::uniform_real_distribution<float> u2(0, 1);
		for (auto& p : data)
			p = u2(e)  * value;
	}
	size_t size() { return data.size(); }
	std::vector<int>& getArr() { return data; }
	void Print() { 
		for (auto e : data) std::cout << e << ' '; 
		std::cout << std::endl;
	}
private:
	std::vector<int> data;
};

