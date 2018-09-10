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
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
	bool dfs(vector<vector<char>>& board, int row, int col, const string& word, int start, int M, int N, int slen) {
		char curC;
		bool res = false;
		if ((curC = board[row][col]) != word[start]) return false;
		else if (start == slen - 1) return true;
		board[row][col] = '*';
		if (row > 0) res = dfs(board, row - 1, col, word, start + 1, M, N, slen); //up
		if (!res && row < M - 1) res = dfs(board, row + 1, col, word, start + 1, M, N, slen); //down
		if(!res&&col > 0) res = dfs(board, row , col - 1, word, start + 1, M, N, slen);//left
		if (!res&&col < N - 1) res = dfs(board, row, col + 1, word, start + 1, M, N, slen);//right
		board[row][col] = curC;
		return res;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty()) return false;
		int m = board.size(), n = board[0].size();
		for (auto i = 0; i < m; ++i) {
			for (auto j = 0; j < n; ++j) {
				if (dfs(board, i, j, word, 0, m, n, word.size())) return true;
			}
		}
		return false;
	}
};
