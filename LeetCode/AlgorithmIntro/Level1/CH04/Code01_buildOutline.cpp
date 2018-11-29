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
#include <tuple>
#include <map>
#include <algorithm>

//218 The Skyline Problem

using Matrix = std::vector<std::vector<int>>;
using Result = std::vector<std::pair<int, int>>;
using Node = std::tuple<int, int, bool>;
using ArrNode = std::vector<Node>; //coordination,height,up/down



Result getSkyline(const Matrix& builings) {
	if (builings.empty())return{};

	ArrNode arrNode(builings.size() * 2);

	for (auto i = 0; i < builings.size(); ++i) {
		arrNode[2*i] = std::make_tuple(builings[i][0], builings[i][2], true); //true is up
		arrNode[2*i+1] = std::make_tuple(builings[i][1], builings[i][2], false);//false is down
	}

	std::sort(arrNode.begin(), arrNode.end(),
		[](Node& lhs, Node& rhs) {return std::get<0>(lhs) < std::get<0>(rhs); });

	std::map<int, int> hMap;
	std::map<int, int> rMap;//store result info

	for (int i = 0; i < arrNode.size(); ++i) {
		if (std::get<2>(arrNode[i])) {
			//not found
			/*
			if (hMap.find(std::get<1>(arrNode[i])) == hMap.end()) {
				hMap.insert({ std::get<1>(arrNode[i]), 1 });
			}
			else {
				++hMap[std::get<1>(arrNode[i])];
			}*/
			//or
			++hMap[std::get<1>(arrNode[i])];
		}
		else {
			//whether height in this map?
			if (hMap.find(std::get<1>(arrNode[i])) != hMap.end()) {
				/*
				if (hMap[std::get<1>(arrNode[i])] == 1) {
					hMap.erase(std::get<1>(arrNode[i]));
				}
				else {
					--hMap[std::get<1>(arrNode[i])];
				}*/
				if(--hMap[std::get<1>(arrNode[i])]==0)
					hMap.erase(std::get<1>(arrNode[i]));
			}			
		}
		//leetcode support C++14  not 17
		//rMap.insert_or_assign(std::get<0>(arrNode[i]),  hMap.empty() ? 0 : hMap.rbegin()->first);
		if (rMap.find(std::get<0>(arrNode[i])) != rMap.end()) {
			rMap.erase(std::get<0>(arrNode[i]));
		}
		rMap.insert({ std::get<0>(arrNode[i]), hMap.empty() ? 0 : hMap.rbegin()->first });
	}

	Result res;
	int height = 0;
	for (auto &e : rMap) {
		int curPos = e.first;
		int curHeight = e.second;
		if (height != curHeight) {
			res.push_back({ curPos, curHeight });
			height = curHeight;
		}
	}
	return res;
}

int main(){
	Matrix m{ {0,2,3},{2,5,3} };

	for (auto &e : getSkyline(m)) {
		std::cout << "[ " << e.first << ' ' << e.second << " ] ";
	}
	std::cout << std::endl;
}	