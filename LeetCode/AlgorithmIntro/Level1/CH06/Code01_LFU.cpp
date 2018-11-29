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
#include <memory>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>

using std::unordered_map;
using std::list;

/*
namespace std {
	template<> struct hash<Node>
	{
		std::size_t	operator()(const Node& hash) const noexcept
		{
			size_t hashR = hash.key + 10 * hash.value;
			return hashR;
		}
	};
}*/



namespace Jcy_ver_1 {
	struct Node {
		int key;
		int value;
		int times;
		Node(int k = 0, int v = 0, int t = 0) :key(k), value(v), times(t) {}
	};
	struct NodeList {
		int times;
		list<Node> head;//can not be copied
		NodeList(int t = 0) :times(t) {}
	};
	class LFUCache {
	public:
		LFUCache(int capacity) :capacity(capacity) {
		}

		int get(int key) {
			auto res = records.find(key);
			if (res == records.end())
				return -1;
			else {
				move(res, res->second->key, res->second->value);
				return res->second->value;
			}
		}

		void put(int key, int value) {
			auto res = records.find(key);
			if (res != records.end()) {//exist
				move(res, key, value);
			}
			else {
				if (records.size() == 0) {
					cacheList.push_back(1);
					cacheList.begin()->head.push_back({ key,value,1 });
					heads.insert({ 1,cacheList.begin() });
					records.insert({ key, cacheList.begin()->head.begin() });
				}
				else if (records.size() < capacity) {
					addNodeList(key, value);
				}
				else {
					records.erase(cacheList.begin()->head.back().key);
					cacheList.begin()->head.pop_back();
					//delete node
					if (cacheList.begin()->head.empty()) {
						heads.erase(cacheList.begin()->times);
						cacheList.erase(cacheList.begin());
					}
					addNodeList(key, value);
				}
			}
		}

		void move(unordered_map<int, list<Node>::iterator>::iterator res, int key, int value)
		{
			auto listHead = heads.find(res->second->times);
			int time = listHead->second->times;
			auto tmp = listHead->second;
			auto next = std::next(tmp);
			//delete old node
			tmp->head.erase(res->second);
			//如果当前节点为空释放
			if (tmp->head.empty()) {
				cacheList.erase(tmp);
				heads.erase(time);
			}
			if (next == cacheList.end()) {
				NodeList no(time + 1);
				no.head.push_back({ key,value,time + 1 });
				auto place = cacheList.emplace(next, no);
				//tmp valid?
				heads.insert({ time + 1, place });
				records[key] = (place->head.begin());
			}
			else if (next != cacheList.end()) {//:listHead->second->next != null
				if (next->times == time + 1) {
					next->head.push_front({ key,value,time + 1 });
					records[key] = next->head.begin();
				}
				else {//the node(times == time+1) do not exist
					NodeList no(time + 1);
					no.head.push_back({ key,value,time + 1 });
					auto place = cacheList.emplace(next, no);
					//tmp valid?
					heads.insert({ time + 1, place });
					records[key] = place->head.begin();
				}
			}
		}

		void addNodeList(int key, int value) {
			if (cacheList.begin()->times == 1) {
				cacheList.begin()->head.push_front({ key,value,1 });
				records.insert({ key,cacheList.begin()->head.begin() });
			}
			else {
				NodeList no(1);
				no.head.push_back({ key,value,1 });
				cacheList.push_front(no);
				heads.insert({ 1, cacheList.begin() });
				records.insert({ key, cacheList.begin()->head.begin() });
			}
		}
	private:
		size_t capacity;
		list<NodeList> cacheList;//level from top to buttom
		unordered_map<int, list<Node>::iterator> records; //key to Node
		std::unordered_map<int, list<NodeList>::iterator> heads;//times to NodeList
	};
}

//https://stackoverflow.com/questions/50888127/unordered-set-with-custom-struct
//The reason is when you use custom type for unordered_map/set, you need
//provide the custom hash function

namespace Jcy_ver_2 {
	struct Node {
		int key;
		int value;
		int times; 
		Node(int k = 0, int v = 0, int t = 0) :key(k), value(v),times(t){}
	};
	//如果去掉了Node的次数，如何找到当前Node所在的NodeList？
	//可以考虑head的first更改为list<Node>::iterator
	//但是要注意  一定要给出hash函数的实现
	//其实可以按照key和value给出一个自己的hash实现
	struct NodeList {
		int times;
		list<Node> head;//can not be copied
		NodeList(int t = 0):times(t) {}
	};
	//consider to use move constructor
	//and fix the Node 
	class LFUCache {
	public:
		LFUCache(int capacity) :capacity(capacity) {
		}

		int get(int key) {
			auto res = records.find(key);
			if (res == records.end())
				return -1;
			else {
				move(res, res->second->key, res->second->value);
				return res->second->value;
			}
		}

		void put(int key, int value) {
			auto res = records.find(key);
			if (res != records.end()) {//exist
				move(res, key, value);
			}
			else {
				//没有记录
				if (records.size() == 0) {
					cacheList.push_back(1);
					cacheList.begin()->head.push_back({ key,value, 1});
					heads.insert({ 1,cacheList.begin() });
					records.insert({ key, cacheList.begin()->head.begin() });
				}
				//还有空间
				else if (records.size() < capacity) {
					addNodeList(key, value);
				}
				//空间已满，找
				else {
					records.erase(cacheList.begin()->head.back().key);
					cacheList.begin()->head.pop_back();
					//delete node
					if (cacheList.begin()->head.empty()) {
						heads.erase(cacheList.begin()->times);
						cacheList.erase(cacheList.begin());
					}
					addNodeList(key, value);
				}
			}
		}

		void move(unordered_map<int, list<Node>::iterator>::iterator res, int key, int value)
		{	
			auto listHead = heads.find(res->second->times);
			int time = listHead->second->times;
			auto tmp = listHead->second;
			auto next = std::next(tmp);
			//delete old node
			tmp->head.erase(res->second);
			//如果当前节点为空释放
			if (tmp->head.empty()) {
				cacheList.erase(tmp);
				heads.erase(time);
			}
			if (next == cacheList.end()) {
				NodeList no(time + 1);
				no.head.push_back({ key,value,time + 1 });
				auto place = cacheList.emplace(next, no);
				//tmp valid?
				heads.insert({ time + 1, place });
				records[key] = (place->head.begin());
			}
			else if (next != cacheList.end()) {//:listHead->second->next != null
				if (next->times == time + 1) {
					next->head.push_front({ key,value,time + 1 });
					records[key] = next->head.begin();
				}
				else {//the node(times == time+1) do not exist
					NodeList no(time + 1);
					no.head.push_back({ key,value,time + 1 });
					auto place = cacheList.emplace(next, no);
					//tmp valid?
					heads.insert({ time + 1, place });
					records[key] = place->head.begin();
				}
			}
		}

		void addNodeList(int key, int value) {
			if (cacheList.begin()->times == 1) {
				cacheList.begin()->head.push_front({ key,value,1 });
				records.insert({ key,cacheList.begin()->head.begin() });
			}
			else {
				NodeList no(1);
				no.head.push_back({ key,value,1 });
				cacheList.push_front(no);
				heads.insert({ 1, cacheList.begin() });
				records.insert({ key, cacheList.begin()->head.begin() });
			}
		}
	private:
		size_t capacity;
		list<NodeList> cacheList;//level from top to buttom
		unordered_map<int, list<Node>::iterator> records; //key to Node
		std::unordered_map<int, list<NodeList>::iterator> heads;//times to NodeList
	};
}

int main(){
	
}	