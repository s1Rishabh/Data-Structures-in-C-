#include <iostream>
#include <string>
#include <vector>
using namespace std;

int c = 0;
int multimazepath(vector<vector<int> > &board, int sr, int sc, int dr, int dc, string psf)
{
	if (sr > dr || sc > dc)
	{
		return -1;
	}

	if (sr == dr && sc == dc)
	{
		c++;
		cout << psf << endl;
		return 0;
	}

	for (int j = 1; j <= dc - sc; j++)
	{
		if(board[sr][j]!=-1) {
		multimazepath(board, sr, sc + j, dr, dc, psf + "H" + to_string(j));
		}
	}

	for (int i = 1; i <= dr - sr; i++)
	{  
		if(board[i][sc]!=-1) {
		multimazepath(board, sr + i, sc, dr, dc, psf + "V" + to_string(i));
		}
	}

	for (int i = 1, j = 1; i <= dr && j <= dc; i++, j++)
	{

		if (board[i][j] != -1)
		{
		multimazepath(board, sr + i, sc + j, dr, dc, psf + "D" + to_string(i));
		}
	}
	return c;
}

int main()
{

	int arr[][4] = {{0, 0, -1, 0},
					{0, 0, -1, 0},
					{-1, -1,-1, 0},
					{0, 0, 0, 0}};

	vector<vector<int> > board;

	for (int i = 0; i < 4; i++)
	{
		vector<int> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back(arr[i][j]);
		}
		board.push_back(row);
	}

	cout << multimazepath(board, 0, 0, 3, 3, "");
}