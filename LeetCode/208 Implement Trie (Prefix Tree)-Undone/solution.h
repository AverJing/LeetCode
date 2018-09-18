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
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
#pragma once

#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		trie.insert(word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return trie.find(word) != trie.end();
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		for (auto &e : trie) {
			if(e.find(prefix) != string::npos) return true;
		}
		return false;
	}
private:
	unordered_set<string> trie;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
