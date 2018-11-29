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
#include <memory>
#include <bitset>
#include <array>
using std::vector;

struct Node;
using Ptr = std::shared_ptr<Node>;

struct Node {
	std::array<Ptr, 2> next;
	Node() :next{nullptr,nullptr} {}
};

struct TrieTree {
	Ptr head;
	TrieTree(Ptr h = nullptr) :head(h) {}

	void addNum(int num) {
		std::bitset<32> bitNum(num);

		auto cur = head;
		for (int i = 31; i >= 0; --i) {
			cur->next[bitNum[i]] = cur->next[bitNum[i]] ? cur->next[bitNum[i]] : std::make_shared<Node>(Node());
			cur = cur->next[bitNum[i]];
		}
	}

	int getMax(int num) {
		std::bitset<32> bitNum(num);
		auto cur = head;
		std::bitset<32> res;
		for (int i = 31; i >= 0; --i) {
			bool path = bitNum[i];
			bool best = i == 31 ? path : path ^ true;
			best = cur->next[best] ? best : best^true;
			cur = cur->next[best];
			res[i] = path ^ best;
		}
		return static_cast<int>(res.to_ulong());
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		if (nums.empty() || nums.size()==1) return 0;

		TrieTree tree(std::make_shared<Node>(Node()));
		tree.addNum(nums[0]);
		int res = 0;
		for (int i = 1; i < nums.size(); ++i) {
			res = std::max(res, tree.getMax(nums[i]));
			tree.addNum(nums[i]);
		}
		return res;
	}
};

int main(){
	Solution s;
	vector<int> para{ 3,10,5,25,2,8 };
	std::cout <<s.findMaximumXOR(para);
}	