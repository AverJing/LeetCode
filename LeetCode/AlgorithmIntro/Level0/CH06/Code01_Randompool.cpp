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
#include <random>
#include <string>

template<class T>
class RandomPool {
public:
	RandomPool() = default;
	void insertKey(T k) {
		if (KeyIndexMap.find(k) == KeyIndexMap.end()) {
			KeyIndexMap.insert({ k, size });
			IndexKeyMap.insert({ size++, k });
		}
	}

	T getRandom() {
		//std::default_random_engine e;
		//std::uniform_int_distribution<unsigned> u(0, size - 1);   //闭区间

		return IndexKeyMap[std::rand()%size];
	}

	void deleteKey(T k) {
		if (KeyIndexMap.find(k) != KeyIndexMap.end()) {
			auto index = KeyIndexMap[k];
			--size;
			auto lastKey = IndexKeyMap.find(size)->second;
			KeyIndexMap.erase(lastKey);
			KeyIndexMap.insert({ lastKey, index });
			IndexKeyMap.erase(index);
			IndexKeyMap.insert({ index, lastKey });

			//注意C++中 是不会重复插入相同的key的
			//if the container doesn't already contain an element with an equivalent key
			//unordered_multimap

			KeyIndexMap.erase(k);
			IndexKeyMap.erase(size);
		}
	}
	void PrintIndexKeyMap() {
		for (auto &e : IndexKeyMap) {
			std::cout << e.first << e.second << ' ';
		}
		std::cout << std::endl;
	}
private:
	std::unordered_map<T, size_t> KeyIndexMap;
	std::unordered_map<size_t, T> IndexKeyMap;
	size_t size = 0;
};

int main(){
	RandomPool<std::string> pool;
	pool.insertKey("hello");
	pool.insertKey(",world");
	pool.insertKey("jing");
	pool.insertKey("cy");

	pool.PrintIndexKeyMap();
	pool.deleteKey("hello");
	pool.PrintIndexKeyMap();
	//std::cout << pool.getRandom() << std::endl;
	//std::cout << pool.getRandom() << std::endl;
	//std::cout << pool.getRandom() << std::endl;
}	