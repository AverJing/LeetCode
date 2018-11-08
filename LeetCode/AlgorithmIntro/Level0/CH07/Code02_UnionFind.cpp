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
#include <unordered_map>
#include <vector>

template<class T>
struct Node {
	T value;
	bool operator==(const Node& rhs) {
		return value == rhs.value;
	}
	bool operator!=(const Node& rhs) {
		return !(*this==rhs);
	}
};

template<class T>
class Union {
public:
	using sets = std::vector<Node<T>>;
	void makeSets(sets& nodes) {
		if (!fatherMap.empty())
			fatherMap.clear();
		if (!sizeMap.empty())
			sizeMap.clear();

		for (auto &e : nodes) {
			fatherMap.insert({ e,e });
			sizeMap.insert({ e,1 });
		}
	}

	bool isSameSet(const Node<T>& lhs,const Node<T>& rhs) {
		return findHead(lhs) == findHead(rhs);
	}
	void unionSet(const Node<T>& a, const Node<T>& b) {
		auto ahead = findHead(a);
		auto bhead = findHead(b);

		if (ahead != bhead) {//not in same set
			auto aSetSize = sizeMap[ahead];
			auto bSetSize = sizeMap[bhead];

			if (aSetSize < bSetSize) {
				fatherMap[ahead] = bhead;
				sizeMap[bhead] = aSetSize + bSetSize;
			}
			else {
				fatherMap[bhead] = ahead;
				sizeMap[ahead] = aSetSize + bSetSize;
			}
		}
	}
private:
	using HashMap = std::unordered_map<Node<T>, Node<T>>;
	HashMap fatherMap;
	std::unordered_map<Node<T>, size_t> sizeMap;

	Node<T> findHead(const Node<T>& node) {
		auto father = fatherMap[node];
		if (father != node) {
			father = fatherMap[father]; 
		}
		fatherMap[node] = father;//optimization
		return father;
	}
};

int main(){
	
}	