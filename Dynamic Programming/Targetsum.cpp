#include <iostream>
#include <vector>
using namespace std;

bool target_Sum_usingdp(vector<int> arr, int target)
{

    vector<vector<bool>> cricketboard(arr.size() + 1, vector<bool>(target + 1, false));

    for (int i = 0; i < cricketboard.size(); i++)
    {
        cricketboard[i][0] = 1;
    }

    for (int i = 1; i < cricketboard[0].size(); i++)
    {
        cricketboard[0][i] = 0;
    }

    for (int i = 1; i < cricketboard.size(); i++)
    {
        for (int j = 1; j < cricketboard[0].size(); j++)
        {
            if (arr[i - 1] > j)
            {
                cricketboard[i][j] = cricketboard[i - 1][j];
            }
            else if (cricketboard[i - 1][j] == 1)
            {
                cricketboard[i][j] = 1;
            }

            else if (cricketboard[i - 1][j - arr[i - 1]] == 1)
            {
                cricketboard[i][j] = 1;
            }
            else
            {
            }
        }
    }

    for (int i = 0; i < cricketboard.size(); i++)
    {

        for (int j = 0; j < cricketboard[0].size(); j++)
        {

            cout << cricketboard[i][j] << " ";
        }
        cout << endl;
    }
    //   pts(cricketboard,cricketboard.size(),cricketboard.size(),arr,"");
    return cricketboard[cricketboard.size() - 1][cricketboard.size() - 1];
}

int main()
{
    int arr[] = {2, 5, 3, 1, 6};

    vector<int> vs(arr, arr + 5);

    cout << target_Sum_usingdp(vs, 9);
}