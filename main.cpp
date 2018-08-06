#include <bits/stdc++.h>

using namespace std;

bool valid(vector<string> &ans, int r, int c) {
	char cand = ans[r][c];
	for(int i = 0; i < 9; ++i) {
		if(i == r) {
			continue;
		}
		if(ans[i][c] == cand) {
			return false;
		}
	}
	for(int j = 0; j < 9; ++j) {
		if(j == c) {
			continue;
		}
		if(ans[r][j] == cand) {
			return false;
		}
	}
	int rl = r / 3 * 3;
	int cl = c / 3 * 3;
	for(int i = rl; i < rl + 3; ++i) {
		for(int j = cl; j < cl + 3; ++j) {
			if(i == r and j == c) {
				continue;
			}
			if(ans[i][j] == cand) {
				return false;
			}
		}
	}
	return true;
}

bool solve(vector<string> &ans, vector<string> &board, int r, int c) {
	if(r == 9) {
		return true;
	}
	int nr = r, nc = c + 1;
	if(nc == 9) {
		++nr;
		nc = 0;
	}
	if(board[r][c] != '.') {
		return solve(ans, board, nr, nc);
	}
	for(int i = 1; i <= 9; ++i) {
		ans[r][c] = i + '0';
		if(!valid(ans, r, c)) {
			continue;
		}
		if(solve(ans, board, nr, nc)) {
			return true;
		}
	}
	ans[r][c] = '.';
	return false;
}

void solveSudoku(vector<string> &sud) {
	vector<string> board = sud;
	solve(sud, board, 0, 0);
}

void printSudoku(vector<string> &sud) {
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < 9; ++j) {
			cout << sud[i][j] << ' ';
			if(j % 3 == 2 and j != 8) {
				cout << "| ";
			}
		}
		cout << '\n';
		if(i % 3 == 2 and i != 8) {
			cout << "------+-------+------\n";
		}
	}
}

int main() {
	vector<string> sud = {
		"8........",
		"..36.....",
		".7..9.2..",
		".5...7...",
		"....457..",
		"...1...3.",
		"..1....68",
		"..85...1.",
		".9....4.."
	};
	cout << "Initial board\n";
	printSudoku(sud);
	solveSudoku(sud);
	cout << "\nSolved board\n";
	printSudoku(sud);
	return 0;
}
