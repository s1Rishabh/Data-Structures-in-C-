#include <iostream>
#include <vector>

using namespace std;

void printMCP(vector<vector<int> >& storage ,int r, int c,string psf){ 
  if(r==storage.size()-1 && c==storage[0].size()-1)
  { 
      cout<<psf<<endl;
      return;
  }
  else if(r== storage.size()-1)
  {
    printMCP(storage,r,c+1,psf+"H");

  }
  else if(c==storage[0].size()-1){ 
    printMCP(storage,r+1,c,psf+"V");
  }
  else
  { 
 int mymin= min(storage[r][c+1],storage[r+1][c]);
    if(storage[r+1][c]==mymin){
       printMCP(storage,r+1,c,psf+"V");  
    }

    if(storage[r][c+1]==mymin){ 
        printMCP(storage,r,c+1,psf+"H");
    } 
  }

}

int cost(vector<vector<int> > &matrix)
{
    vector<vector<int> > storage(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = storage.size() - 1; i >= 0; i--)
    {
        for (int j = storage[0].size() - 1; j >= 0; j--)
        {

            if(i==storage.size()-1 && j==storage[0].size()-1) 
           { storage[i][j] = matrix[i][j];
           }
            else if (i==storage.size()-1)
            {
                storage[i][j] = matrix[i][j] + storage[i][j+1];
            }
            else if (j== storage.size()-1)
            {
                storage[i][j] = matrix[i][j] + storage[i+1][j];
            }

            else 
            {
                storage[i][j] = min(storage[i][j+1], storage[i+1][j]) + matrix[i][j];
            }
        }
    }
    printMCP(storage,0,0,"");
  return storage[0][0];
}



int main()
{
    int arr[][6] = {{2, 6, 5, 1, 3, 4}, {0, 4, 9, 2, 9, 0}, {4, 8, 1, 0, 6, 5}, {0, 3, 3, 1, 5, 4}, {1, 2, 7, 0, 6, 9}, {5, 7, 1, 3, 8, 2}};
    vector<vector<int> > board;
    // int arr[][3]= {{1,3,1} ,{1,5,1}, {4,2,1}};
    for (int i = 0; i <6; i++)
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

    cout << cost(board);
}