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
#include <array>
#include <memory>
#include <bitset>
#include "..\..\Level0\CH01\TestCase.h"

using Array = std::vector<int>;

int getMaxEOR1(const Array& data) {
	if (data.empty())return 0;
	int res = 0;
	for (int i = 0; i < data.size(); ++i) {		
		for (int j = 0; j <= i; ++j) {
			int eor = 0;
			for (int k = j; k <= i; ++k) {
				eor ^= data[k];
			}
			res = std::max(res, eor);
		}
	}
	return res;
}

int getMaxEOR2(const Array& data) {
	if (data.empty())return 0;
	int res = 0;
	Array dp(data.size(), 0);
	int eor = 0;
	for (int i = 0; i < data.size(); ++i) {
		eor ^= data[i];
		res = std::max(res, eor);
		for (int j = 1; j <= i; ++j) {
			int jToI = eor ^ dp[j - 1];
			res = std::max(jToI, res);
		}
		dp[i] = eor;
	}
	return res;
}

struct Node;
using Ptr = std::shared_ptr<Node>;
struct Node{
	std::array<Ptr, 2> next;
	Node() :next({ nullptr,nullptr }) {}
};

struct NumTrie {
	Ptr head;
	NumTrie():head(std::make_shared<Node>(Node())) {}
	
	void add(int num) {
		std::bitset<32> Nbit(num);
		auto cur = head;
		for (int i = 32; i--;) {
			bool path = Nbit[i] & true;
			cur->next[path] = cur->next[path] ? cur->next[path] : std::make_shared<Node>(Node());
			cur = cur->next[path];
		}
	}

	int maxXor(int num) {
		std::bitset<32> Nbit(num);
		auto cur = head;
		std::bitset<32> res(0);
		for (int i = 32; i--;) {
			bool path = Nbit[i] & true;
			bool best = i == 31 ? path : (path ^ true);
			best = cur->next[best] ? best : (best ^ true);
			res[i] = path ^ best;
			cur = cur->next[best];
		}
		return static_cast<int>(res.to_ullong());
	}
};

int getMaxEOR3(const Array& data) {
	if (data.empty()) return 0;

	int res = INT_MIN;
	int eor = 0;
	NumTrie numtrie;
	numtrie.add(0);
	for (int i = 0; i < data.size(); ++i) {
		eor ^= data[i];
		res = std::max(numtrie.maxXor(eor), res);
		numtrie.add(eor);
	}
	return res;
}

int main(){
	
	for (int i = 0; i < 50; ++i) {
		testCase t(10, 10);
		t.Print();
		std::cout << "R: " << getMaxEOR1(t.getArr()) << ' ' 
			<< getMaxEOR2(t.getArr()) << ' '
			<< getMaxEOR3(t.getArr()) << std::endl;
	}
}