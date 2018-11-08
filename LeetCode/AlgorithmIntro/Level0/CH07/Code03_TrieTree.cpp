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
#include <string>
#include <vector>

const int MAX = 26;

struct TrieNode;

using Ptr = std::shared_ptr<TrieNode>;
using String = std::string;
using CharArr = std::vector<char>;

//64位原生指针大小是 8字节，智能指针是16字节

struct TrieNode {
	Ptr next[MAX];  //default constructor : nullptr
	size_t path=0;
	size_t end=0;
};

class TrieTree {
public:
	TrieTree() :root(new TrieNode()) {};
	void insertNode(const String& s) {
		if (s.empty()) return;
		
		auto node = root;
		for (int i = 0; i < s.size(); ++i) {			
			auto index = s[i] - 'a';
			if (!node->next[index]) {
				node->next[index] = std::make_shared<TrieNode>();
			}
			node = node->next[index];
			++node->path;
		}
		++node->end;

		/*
		auto node = root.next;
		for (int i = 0; i < s.size(); ++i) {			
			auto index = s[i] - 'a';
			if (!node[index]) {
				node[index] = std::make_shared<TrieNode>();
			}
			node = node[index]->next;
			++node[index]->path;
		}
		++node[(s[s.size() - 1] - 'a')]->end;
		*/
	}
	void deleteNode(const String& word) {
		if (search(word)) {
			auto node = root;
			for (int i = 0; i < word.size(); ++i) {
				auto index = word[i] - 'a';
				if (--node->next[index]->path == 0) {
					node->next[index] = nullptr;       //此处就算使用了智能指针，会内存泄漏吗
					return;					//类比问题，用智能指针实现的链表，故意断链，会自动释放内存吗
				}
				node = node->next[index];
			}
			--node->end;
		}
	}
	int search(const String& word) {
		if (word.empty() || !root) return 0;

		auto node = root;
		for (int i = 0; i < word.size(); ++i) {
			auto index = word[i] - 'a';
			if (!node->next[index])
				return 0;
			node = node->next[index];
		}
		return node->end;
	}
	int prefixNumber(const String& pre) {
		if (pre.empty()) return 0;

		auto node = root;
		for (int i = 0; i < pre.size(); ++i) {
			auto index = pre[i] - 'a';
			if (!node->next[index])
				return 0;
			node = node->next[index];
		}
		return node->path;
	}
private:
	Ptr root;
};

int main(){
	TrieTree trie;
	std::cout << (trie.search("zuo"));//0
	trie.insertNode("zuo");
	std::cout << (trie.search("zuo"));//1
	trie.deleteNode("zuo");
	std::cout << (trie.search("zuo"));//0
	trie.insertNode("zuo");
	trie.insertNode("zuo");
	trie.deleteNode("zuo");
	std::cout << (trie.search("zuo"));//1
	trie.deleteNode("zuo");
	std::cout << (trie.search("zuo"));//0
	trie.insertNode("zuoa");
	trie.insertNode("zuoac");
	trie.insertNode("zuoab");
	trie.insertNode("zuoad");
	trie.deleteNode("zuoa");
	std::cout << (trie.search("zuoa"));//0
	std::cout << (trie.prefixNumber("zuo"));//3
}	