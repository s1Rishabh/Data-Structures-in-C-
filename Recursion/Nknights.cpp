#include <iostream>
#include <vector>
#include <string>

using namespace std;
int counter = 0;

bool isknightsafe(vector<vector<bool> > &board, int i, int j)
{

    for (int ii = i + 1, ij = j - 1; ii < 2 && ij >= 0; ii++, ij--)
    {
        if (board[ii][ij])
        {
            return false;
        }
    }

    for (int ii = i + 1, ij = j + 1; ii < 2 && ij < 1; ii++, ij--)
    {
        if (board[ii][ij])
        {
            return false;
        }
    }

    for (int ii = i - 1, ij = j - 1; ii >= 0 && ij >= 0; ii--, ij--)
    {
        if (board[ii][ij])
        {
            return false;
        }
    }
    for (int ii = i + 1, ij = j - 1; ii < 2 && ij >= 0; ii++, ij--)
    {
        if (board[ii][ij])
        {
            return false;
        }
    }
    return true;
}

bool isboardsafe(vector<vector<bool> > &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {

            if (board[i][j] == true)
            {
                if (isknightsafe(board, i, j) == false)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void nknight(vector<vector<bool> > &board, int qpsf, int abcd, string asf)
{
    if (qpsf == board.size())
    {
        if (isboardsafe(board) == true)
        {
            cout << asf << endl;
            counter++;
        }

        return;
    }

    for (int i = abcd + 1; i < board.size() * board.size(); i++)
    {
        int r = i / board.size();
        int c = i % board.size();
        if (board[r][c] == false && isknightsafe(board, r, c))
        {
            board[r][c] = true;
            nknight(board, qpsf + 1, i, asf + to_string(r) + to_string(c) + " ");
            board[r][c] = false;
        }
    }
}

void nknightsp(vector<vector<bool> > &board, int qpsf, int cb, string asf)
{

    if (cb == board.size() * board.size())
    {
        if (qpsf == board.size())
        {
            cout << asf << endl;
            counter++;
        }
        return;
    }
    
    nknightsp(board, qpsf, cb + 1, asf);
    int r = cb / board.size();
    int c = cb % board.size();
    if (board[r][c] == false && isknightsafe(board, r, c))
    {
        board[r][c] = true;
        nknightsp(board, qpsf + 1, cb + 1, asf + to_string(r) + to_string(c) + " ");
        board[r][c] = false;
    }
}

int main(int argc, char const *argv[])
{
    int arr[4][4] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    vector<vector<bool> > board;
    for (int i = 0; i < 4; i++)
    {
        vector<bool> row;
        for (int j = 0; j < 4; j++)
        {
            row.push_back(arr[i][j]);
        }
        board.push_back(row);
    }
    // nknight(board,0,-1,"");
    nknightsp(board, 0, 0, "");
    cout << counter;
    return 0;
}
