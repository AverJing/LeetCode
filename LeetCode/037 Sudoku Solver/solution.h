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
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
#pragma once

#include <vector>
using std::vector;
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Solution {
	bool findEmptyCell(const vector<vector<char> > &board, size_t &row, size_t &col)
	{
		for (row = 0; row < board.size(); ++row)
			for (col = 0; col < board[row].size(); ++col)
				if (board[row][col] == '.') return true;
		return false;
	}
	bool isSafe(const vector<vector<char> > &board, size_t row, size_t col, char c)
	{
		for (size_t i = 0; i < 9; ++i) {
			if (board[row][i] == c) return false;
			if (board[i][col] == c) return false;
			if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) return false;
		}
		return true;
	}
public:
	bool solveSudoku(vector<vector<char> > &board) {
		size_t row = 0, col = 0;
		if (!findEmptyCell(board, row, col)) return true;
		for (char c : {'1', '2', '3', '4', '5', '6', '7', '8', '9'})
			if (isSafe(board, row, col, c)) {
				board[row][col] = c;
				if (solveSudoku(board)) return true;
				board[row][col] = '.';
			}
		return false;
	}
};