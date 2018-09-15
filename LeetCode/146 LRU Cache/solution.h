/*
*
*
*@author: Aver Jing
*@description：
*@date：
*
*
*/
/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key 
if the key exists in the cache, otherwise return -1.

put(key, value) - Set or insert the value if the key is not already 
present. When the cache reached its capacity, 
it should invalidate the least recently used item 
before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2  );// capacity 

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

#pragma once

#include <unordered_map>
#include <list>

using std::unordered_map;
using std::list;

struct Node {
	int key;
	int value;
};

class LRUCache {
public:
	LRUCache(int capacity):capacity(capacity){
	}

	int get(int key) {
		auto result = cache.find(key);
		if (result != cache.end()) {
			auto listIt = cache[key];
			Node newNode;
			newNode.key = listIt->key;
			newNode.value = listIt->value;
			cacheList.erase(listIt);
			cacheList.push_front(newNode);
			cache[key] = cacheList.begin();

			return cache[key]->value;
		}			
		else
			return -1;
	}

	void put(int key, int value) {
		auto result = cache.find(key);
		if (result == cache.end()) {
			if (cache.size() == capacity) {
				cache.erase(cacheList.back().key);
				cacheList.pop_back();
			}
		}
		else {
			auto listIt = result->second;
			cacheList.erase(listIt);
		}
		Node newNode;
		newNode.key = key;
		newNode.value = value;
		cacheList.push_front(newNode);
		cache[key] = cacheList.begin();
	}
private:
	size_t capacity;
	list<Node> cacheList;
	unordered_map<int, list<Node>::iterator> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
