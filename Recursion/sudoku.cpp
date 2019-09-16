#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_the_sudokusafe(vector<vector<int>> &board, int r, int c, int cv)
{

	for (int i = 0; i < board.size(); i++)
	{
		if (board[r][i] == cv)
		{
			return false;
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][c] == cv)
		{
			return false;
		}
	}

	int smrc = (r / 3) * 3;
	int smcc = (c / 3) * 3;
	for (int i = smrc; i < smrc + 3; i++)
	{
		for (int j = smcc; j < smcc + 3; j++)
		{
			if (board[i][j] == cv)
			{
				return false;
			}
		}
	}

	return true;
}

void sudoku(vector<vector<int>> &board, int bno)
{

	if (bno == board.size() * board.size())
	{
		cout << "------------------------" << endl;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board.size(); j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << "------------------------" << endl;
		return;
	}
	int r = bno / board.size();
	int c = bno % board.size();

	if (board[r][c] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (is_the_sudokusafe(board, r, c, i))
			{
				board[r][c] = i;
				sudoku(board, bno + 1);
				board[r][c] = 0;
			}
		}
	}

	else
	{
		sudoku(board, bno + 1);
	}
}

int main()
{

	int arr[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0}, {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0}, {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0}, {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4}, {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	vector<vector<int>> board;

	for (int i = 0; i < 9; i++)
	{
		vector<int> row;
		for (int j = 0; j < 9; j++)
		{
			row.push_back(arr[i][j]);
		}
		board.push_back(row);
	}
	sudoku(board, 0);
}