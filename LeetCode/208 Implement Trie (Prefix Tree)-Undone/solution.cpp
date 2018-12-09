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
#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

struct TrieNode;

using Ptr = shared_ptr<TrieNode>;//为了方便资源管理
//我没去验证真的释放了吗

struct TrieNode
{
	Ptr next[26];  //a-z
	size_t end = 0;
};


class Trie {
public:
	/** Initialize your data structure here. */
	Trie() : root(new TrieNode){

	}

	/** Inserts a word into the trie. */
	void insert(const string& word) {
		auto node = root;
		for (auto e : word) {
			if (!node->next[e - 'a']) {
				node->next[e - 'a'] = std::make_shared<TrieNode>();
			}
			node = node->next[e - 'a'];
		}
		++node->end;
	}

	/** Returns if the word is in the trie. */
	bool search(const string& word) {
		auto node = root;
		for (auto e : word) {
			if (node->next[e - 'a']) {
				node = node->next[e - 'a'];
			}
			else {
				return false;
			}
		}
		return node->end ? true : false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(const string& prefix) {
		auto node = root;
		for (auto e : prefix) {
			if (node->next[e - 'a']) {
				node = node->next[e - 'a'];
			}
			else {
				return false;
			}
		}
		return true;
	}

	Ptr root;
};
int main(){
	//测试
	std::weak_ptr<TrieNode> p;

	{
		Trie tr;
		p = tr.root;
		tr.insert("apple");
		tr.insert("hello");
	}
	//释放内存了
	std::cout << p.use_count() << std::endl;
}	