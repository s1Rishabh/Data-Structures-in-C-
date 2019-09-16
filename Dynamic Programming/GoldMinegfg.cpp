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
                storage[i][j] =costs[i][j] +max(storage[i][j + 1],max(storage[i-1][j + 2], storage[i + 1][j + 1]));
            } 
        }
    } 
    int mymax= INT_MIN;
    for(int i=0 ; i<storage.size() ; i++)
    {  
        if(storage[i][0]>mymax)
        mymax= storage[i][0];
    } 
     for (int i = 0; i < storage.size(); i++)
        {

            for (int j = 0; j < storage[0].size(); j++)
            {
                cout<<storage[i][j]<< " ";
            }
            cout<<endl;
        }

    
    return mymax;
}

int main()
{
    int t, n, m;
    cin >> t;
    vector<vector<int> > board;
    while (t--)
    {
        cin >> n;
        cin >> m;
        int arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < m; j++)
            {
                row.push_back(arr[i][j]);
            }
            board.push_back(row);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = arr[i][j];
            }
        }
        int c = min_cost_goldmaze(board);
        cout << c;
    }

    return 0;
}