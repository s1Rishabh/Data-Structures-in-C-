#include <iostream>
#include <vector>

using namespace std;

int min_cost_goldmaze(vector<vector<int> > costs)
{
  vector<vector<int> > storage(costs.size(), vector<int>(costs[0].size(), 0));

  for (int i = costs.size() - 1; i >= 0; i--)
  {
    for (int j = costs[0].size() - 1; j >= 0; j--)
    {

      if (j == costs[0].size() - 1)
      {
        storage[i][j] = costs[i][j];
      }
      else if (i == costs.size() - 1)
      {
        storage[i][j] = costs[i][j] + max(storage[i][j + 1], storage[i - 1][j + 1]);
      }
      else if (i == 0)
      {
        storage[i][j] = costs[i][j] + max(storage[i][j + 1], storage[i + 1][j + 1]);
      }
      else
      {
        storage[i][j] = costs[i][j] + max(storage[i - 1][j + 1], max(storage[i][j + 1], storage[i + 1][j + 1]));
      }
    }
  }
  // for (int i = 0; i < storage.size(); i++)
  // {
  //   for (int j = 0; j < storage[0].size(); j++)
  //   {

  //     cout << storage[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return storage[0][0];
}

int main()
{
  int arr[][6] = {{2, 6, 5, 1, 3, 4}, {0, 4, 9, 2, 9, 0}, {4, 8, 1, 0, 6, 5}, {0, 3, 3, 1, 5, 4}, {1, 2, 7, 0, 6, 9}, {5, 7, 1, 3, 8, 2}};
  vector<vector<int> > board;
  for (int i = 0; i < 6; i++)
  {
    vector<int> row;
    for (int j = 0; j < 6; j++)
    {
      row.push_back(arr[i][j]);
    }
    board.push_back(row);
  }
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board.size(); j++)
    {
      board[i][j] = arr[i][j];
    }
  }

  min_cost_goldmaze(board);
}