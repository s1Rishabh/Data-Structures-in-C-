#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool debuggable = true;
bool canPlaceTheWordH(vector<vector<char>> &board, int i, int j, string word)
{
	if (j + word.size() > board.size())
	{
		// thw word is too large for the board
		return false;
	}
	else if (j > 0 && board[i][j - 1] != '+')
	{
		// there is a non + on left side
		return false;
	}
	else if (j + word.size() < board.size() &&
			 board[i][j + word.size()] != '+')
	{
		// there is a non + on right side
		return false;
	}
	else
	{
		for (int ii = 0; ii < word.size(); ii++)
		{
			if (board[i][j + ii] != '-' && board[i][j + ii] != word[ii])
			{
				return false;
			}
		}

		return true;
	}
}

void placeTheWordH(vector<vector<char>> &board, int i, int j, string word,
				   bool dipit[])
{
	for (int ii = 0; ii < word.size(); ii++)
	{
		dipit[ii] = board[i][j + ii] == '-';
		board[i][j + ii] = word[ii];
	}
}

void unplaceTheWordH(vector<vector<char>> &board, int i, int j, string word,
					 bool dipit[])
{
	for (int ii = 0; ii < word.size(); ii++)
	{
		if (dipit[ii] == true)
		{
			board[i][j + ii] = '-';
		}
	}
}

bool canPlaceTheWordV(vector<vector<char>> &board, int i, int j, string word)
{
	if (i + word.size() > board.size())
	{
		// thw word is too large for the board
		return false;
	}
	else if (i > 0 && board[i - 1][j] != '+')
	{
		// there is a non + on left side
		return false;
	}
	else if (i + word.size() < board.size() &&
			 board[i + word.size()][j] != '+')
	{
		// there is a non + on right side
		return false;
	}
	else
	{
		for (int ii = 0; ii < word.size(); ii++)
		{
			if (board[i + ii][j] != '-' && board[i + ii][j] != word[ii])
			{
				return false;
			}
		}

		return true;
	}
}

void placeTheWordV(vector<vector<char>> &board, int i, int j, string word,
				   bool dipit[])
{
	for (int ii = 0; ii < word.size(); ii++)
	{
		dipit[ii] = board[i + ii][j] == '-';
		board[i + ii][j] = word[ii];
	}
}

void unplaceTheWordV(vector<vector<char>> &board, int i, int j, string word,
					 bool dipit[])
{
	for (int ii = 0; ii < word.size(); ii++)
	{
		if (dipit[ii] == true)
		{
			board[i + ii][j] = '-';
		}
	}
}

void crossword(vector<vector<char>> &board, vector<string> &words, int wpsf)
{
	if (wpsf == words.size())
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board.size(); j++)
			{
				cout << board[i][j] << "-";
			}
			cout << endl;
		}
		return;
	}

	if (debuggable)
	{
		cout << wpsf << endl;
	}
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (debuggable)
			{
				cout << wpsf << i << j << "*" << endl;
			}

			if (board[i][j] == '-' || board[i][j] == words[wpsf][0])
			{
				if (debuggable)
				{
					cout << wpsf << i << j << "$" << endl;
				}

				if (canPlaceTheWordH(board, i, j, words[wpsf]))
				{
					if (debuggable)
					{
						cout << wpsf << i << j << "#h" << endl;
					}

					// bool dipit[words[wpsf].size()] = {0};
					// placeTheWordH(board, i, j, words[wpsf], dipit);
					crossword(board, words, wpsf + 1);
					// unplaceTheWordH(board, i, j, words[wpsf], dipit);
				}

				if (canPlaceTheWordV(board, i, j, words[wpsf]))
				{
					if (debuggable)
					{
						cout << wpsf << i << j << "#v" << endl;
					}

					// bool dipit[words[wpsf].size()] = {0};
					// placeTheWordV(board, i, j, words[wpsf], dipit);
					crossword(board, words, wpsf + 1);
					// unplaceTheWordV(board, i, j, words[wpsf], dipit);
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	vector<vector<char>> board{
		{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
		{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
		{'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
		{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
		{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
		{'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
		{'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
		{'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
		{'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
		{'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

	vector<string> words{"agra", "norway", "england", "gwalior"};
	crossword(board, words, 0);
}
